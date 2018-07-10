/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define GPIO_INPUT_0              0
#define GPIO_INTPUT_PIN_SEL       (1ULL<<GPIO_INPUT_0)
#define ESP_INTR_FLAG_DEFAULT     0

static xQueueHandle gpio_evt_queue = NULL;
static const char *GPIO_TAG = "gpio";

static void IRAM_ATTR gpio_isr_handler(void* arg){
    uint32_t gpio_num = (uint32_t) arg;
    ets_printf("gpio interrupt been triggered.\n");
    xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}
static void gpio_task(void* arg){
    uint32_t io_num;
    int32_t press_cnt = 0;
    if(gpio_evt_queue == NULL){
        gpio_evt_queue = xQueueCreate(5, sizeof(io_num));
    }
    while(1){
        if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
            printf("gpio%d has been pressed %d times.\n", io_num, ++press_cnt);
            gpio_get_level(io_num);
        }
    }
}
void gpio_init(){
    gpio_config_t io_config;
    io_config.pin_bit_mask = GPIO_INTPUT_PIN_SEL;
    io_config.intr_type = GPIO_PIN_INTR_NEGEDGE;
    io_config.mode = GPIO_MODE_INPUT;
    io_config.pull_up_en = 1;
    gpio_config(&io_config);
}

void app_main()
{
    printf("Hello world!\n");
    ESP_LOGI(GPIO_TAG, "init gpio...");
    gpio_init();
    ESP_LOGI(GPIO_TAG, "gpio init done!");

    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    //hook isr handler for specific gpio pin
    gpio_isr_handler_add(GPIO_INPUT_0, gpio_isr_handler, (void*) GPIO_INPUT_0);
    ESP_LOGI(GPIO_TAG, "gpio isr handler added!");

    xTaskCreate(gpio_task, "gpio task", 1024*2, NULL, 10, NULL);
    ESP_LOGI(GPIO_TAG,"gpio task created.");

}
