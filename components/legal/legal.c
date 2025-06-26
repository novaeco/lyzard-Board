#include "legal.h"
#include "esp_log.h"

static const char *TAG = "legal";

void legal_init(void)
{
    ESP_LOGI(TAG, "Initialisation du module legal");
    // TODO: charger les parametres reglementaires.
}

void legal_generate_docs(const char *operation)
{
    ESP_LOGI(TAG, "Generation des documents pour l'operation: %s", operation);
    // TODO: generer CERFA, I-FAP, CITES, etc.
}
