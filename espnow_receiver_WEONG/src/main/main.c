#include <stdio.h>
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "espnow_receiver.h"

void app_main() 
{
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) 
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    ESP_ERROR_CHECK(ret);
    wifi_init();

    // Configure ESP NOW
    ESP_ERROR_CHECK(esp_now_init());

    // Register the callback function for received data 
    ESP_ERROR_CHECK(esp_now_register());
}
