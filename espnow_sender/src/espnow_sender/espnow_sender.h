#ifndef ESPNOW_SENDER_H
#define ESPNOW_SENDER_H

#include <stdio.h>
#include <string.h>

#include "esp_log.h"
#include "esp_now.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Structure to store teh data to be sent
typedef struct
{
    uint32_t value_1;
    uint32_t value_2;
    uint32_t value_3;
} Data_t;

esp_err_t wifi_init();
esp_err_t send_espnow(Data_t data);
esp_err_t espnow_wifi_init();

#endif
