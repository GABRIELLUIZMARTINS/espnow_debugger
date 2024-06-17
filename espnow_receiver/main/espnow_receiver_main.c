#include <stdio.h>
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_now.h"
#include <string.h>

// Struct for storing received data
typedef struct 
{
    uint32_t value_1;
    uint32_t value_2;
    uint32_t value_3;
} Data_t;

static const char *TAG = "espnow_recv";

// Initialize wifi 
static void wifi_init() 
{
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
}

void on_data_received(const uint8_t *mac_addr, const uint8_t *data, int len) 
{
    // Checks the size of received data     
    if (len == sizeof(Data_t) ) 
    {
        //Convert the received data to the data structure  
        Data_t *received_data = (Data_t *)data;     
        
        ESP_LOGI(TAG, "(%d;%d;%d)",
                        received_data->value_1, 
                        received_data->value_2, 
                        received_data->value_3);
        
    }
    else
    {
        ESP_LOGW(TAG, "Incorrect received data size: %d, expected: %d", len, sizeof(Data_t));
    }
        
    vTaskDelay(pdMS_TO_TICKS(1/1000)); // Delay 1 microsegund

}

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
    ESP_ERROR_CHECK(esp_now_register_recv_cb(on_data_received));
}
