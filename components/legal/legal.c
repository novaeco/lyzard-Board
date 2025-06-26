#include "legal.h"
#include "esp_log.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

static const char *TAG = "legal";

void legal_init(void)
{
    ESP_LOGI(TAG, "Initialisation du module legal");

    const char *dir = "/spiffs/legal";
    if (mkdir(dir, 0775) == 0) {
        ESP_LOGI(TAG, "Repertoire %s cree", dir);
    } else if (errno == EEXIST) {
        ESP_LOGI(TAG, "Repertoire %s deja existant", dir);
    } else {
        ESP_LOGW(TAG, "Impossible de creer %s: %s", dir, strerror(errno));
    }
    // Chargement des parametres reglementaires eventuels
}

void legal_generate_docs(const char *operation)
{
    ESP_LOGI(TAG, "Generation des documents pour l'operation: %s", operation);

    const char *base = "/spiffs/legal";
    char path[64];

    // CERFA
    snprintf(path, sizeof(path), "%s/CERFA_%s.txt", base, operation);
    FILE *f = fopen(path, "w");
    if (f) {
        fprintf(f, "Placeholder CERFA pour %s\n", operation);
        fclose(f);
        ESP_LOGI(TAG, "CERFA genere: %s", path);
    } else {
        ESP_LOGW(TAG, "Echec creation %s", path);
    }

    // I-FAP
    snprintf(path, sizeof(path), "%s/I-FAP_%s.txt", base, operation);
    f = fopen(path, "w");
    if (f) {
        fprintf(f, "Placeholder I-FAP pour %s\n", operation);
        fclose(f);
        ESP_LOGI(TAG, "I-FAP genere: %s", path);
    } else {
        ESP_LOGW(TAG, "Echec creation %s", path);
    }

    // CITES
    snprintf(path, sizeof(path), "%s/CITES_%s.txt", base, operation);
    f = fopen(path, "w");
    if (f) {
        fprintf(f, "Placeholder CITES pour %s\n", operation);
        fclose(f);
        ESP_LOGI(TAG, "CITES genere: %s", path);
    } else {
        ESP_LOGW(TAG, "Echec creation %s", path);
    }
}
