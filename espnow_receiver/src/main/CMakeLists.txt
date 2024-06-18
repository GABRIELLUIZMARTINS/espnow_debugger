idf_component_register(SRCS "espnow_receiver_main.c"
                    INCLUDE_DIRS "."
                    REQUIRES nvs_flash espnow_receiver)
