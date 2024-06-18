#include <stdio.h>
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_now.h"
#include <string.h>
#include "espnow_receiver.h"

void app_main() 
{
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) 
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
        ESP_ERROR_CHECK(ret);

    }

    wifi_init();
        ESP_ERROR_CHECK(ret);


    // Configurar ESP-NOW
    ESP_ERROR_CHECK(esp_now_init());

    // Registrar a função de callback para dados recebidos
    ESP_ERROR_CHECK(esp_now_register_recv_cb(on_data_received));
}

// #define SOC_CLK_RC_FAST_FREQ_APPROX         17500000                            /*!< Approximate RC_FAST_CLK frequency in Hz */
// #define SOC_CLK_RC_SLOW_FREQ_APPROX         136000                              /*!< Approximate RC_SLOW_CLK frequency in Hz */
