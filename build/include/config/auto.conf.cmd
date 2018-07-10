deps_config := \
	/home/yuxufeng/esp/esp-idf/components/app_trace/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/aws_iot/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/bt/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/driver/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/esp32/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/esp_http_client/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/ethernet/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/fatfs/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/freertos/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/heap/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/libsodium/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/log/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/lwip/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/mbedtls/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/mdns/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/openssl/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/pthread/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/spi_flash/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/spiffs/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/vfs/Kconfig \
	/home/yuxufeng/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/yuxufeng/esp/esp-idf/Kconfig.compiler \
	/home/yuxufeng/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/yuxufeng/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/yuxufeng/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/yuxufeng/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
