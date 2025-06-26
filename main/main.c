#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "database.h"
#include "ui.h"
#include "legal.h"

static const char *TAG = "main";

void app_main(void)
{
    ESP_LOGI(TAG, "Demarrage de Lyzard Board");

    // Initialisation NVS requise par ESP-IDF
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialisation des modules
    database_init();
    legal_init();
    ui_init();

    while (1) {
        ui_update();
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}
