#include "database.h"
#include "esp_log.h"
#include <sqlite3.h>

static const char *TAG = "database";
static sqlite3 *s_db = NULL;

void database_init(void)
{
    // Initialisation de la base SQLite ou du stockage fichier.
    ESP_LOGI(TAG, "Initialisation de la base de donnees");

    int rc = sqlite3_open("/spiffs/lyzard.db", &s_db);
    if (rc != SQLITE_OK) {
        ESP_LOGE(TAG, "Impossible d'ouvrir la base: %s", sqlite3_errmsg(s_db));
        sqlite3_close(s_db);
        s_db = NULL;
        return;
    }

    const char *sql =
        "CREATE TABLE IF NOT EXISTS events("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "data TEXT NOT NULL);";
    char *err_msg = NULL;
    rc = sqlite3_exec(s_db, sql, NULL, NULL, &err_msg);
    if (rc != SQLITE_OK) {
        ESP_LOGE(TAG, "Erreur creation table: %s", err_msg);
        sqlite3_free(err_msg);
    }
}

void database_save_event(const char *event)
{
    ESP_LOGI(TAG, "Sauvegarde d'un evenement: %s", event);

    if (!s_db) {
        ESP_LOGW(TAG, "Base de donnees non initialisee");
        return;
    }

    sqlite3_stmt *stmt = NULL;
    const char *sql = "INSERT INTO events(data) VALUES(?1);";

    int rc = sqlite3_prepare_v2(s_db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        ESP_LOGE(TAG, "Prepare echouee: %s", sqlite3_errmsg(s_db));
        return;
    }

    sqlite3_bind_text(stmt, 1, event, -1, SQLITE_TRANSIENT);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        ESP_LOGE(TAG, "Insertion echouee: %s", sqlite3_errmsg(s_db));
    }

    sqlite3_finalize(stmt);
}
