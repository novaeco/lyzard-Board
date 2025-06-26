#include "database.h"
#include "esp_log.h"

static const char *TAG = "database";

void database_init(void)
{
    // Initialisation de la base SQLite ou du stockage fichier.
    ESP_LOGI(TAG, "Initialisation de la base de donnees");
    // TODO: implémenter la création et l'ouverture de la base.
}

void database_save_event(const char *event)
{
    ESP_LOGI(TAG, "Sauvegarde d'un evenement: %s", event);
    // TODO: insérer l'événement dans la base de données.
}
