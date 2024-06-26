#ifndef ESPNOW_RECEIVER_H
#define ESPNOW_RECEIVER_H

#include <stdio.h>
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

esp_err_t wifi_init();
esp_err_t esp_now_register();

#endif
