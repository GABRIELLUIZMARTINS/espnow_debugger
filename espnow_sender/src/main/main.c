#include "espnow_sender.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "time.h"


void task_example(void *pvParameter)
{
    // Main loop 
    for( ;; )
    {
        srand((unsigned) time(NULL));
        Data_t data;
        data.value_1 = rand() %10; 
        data.value_2 = rand() %100; 
        data.value_3 = rand() %1000; 
        
        send_espnow(data);

        // Wait before sending again (adjust as needed)
        vTaskDelay(pdMS_TO_TICKS(1000)); 
    }
}

void app_main()
{
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    ESP_ERROR_CHECK(ret);

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ret = nvs_flash_erase();
        ESP_ERROR_CHECK(ret);
    }

    // Initialize espnow and wifi 
    ret = espnow_wifi_init();
    ESP_ERROR_CHECK(ret);

   xTaskCreatePinnedToCore(&task_example, "Task Example",1024,NULL,5,NULL,tskNO_AFFINITY);
}
