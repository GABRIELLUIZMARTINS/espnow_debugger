#include "espnow_receiver.h"

// Initialize wifi 
esp_err_t wifi_init() 
{
    esp_err_t ret;
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ret = esp_wifi_start();
    ESP_ERROR_CHECK(ret);
    return ret;
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

esp_err_t esp_now_register()
{
    return esp_now_register_recv_cb(on_data_received);
}