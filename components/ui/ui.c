#include "ui.h"
#include "lvgl.h"
#include "esp_log.h"

static const char *TAG = "ui";

void ui_init(void)
{
    ESP_LOGI(TAG, "Initialisation de LVGL");
    lv_init();
    // TODO: initialiser les drivers d'écran et de saisie tactiles.
    // TODO: créer les écrans et onglets LVGL.
}

void ui_update(void)
{
    // Appel périodique pour mettre à jour LVGL.
    lv_timer_handler();
}
