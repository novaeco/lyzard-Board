#ifndef DATABASE_H
#define DATABASE_H

#ifdef __cplusplus
extern "C" {
#endif

/** Initialise la base de données locale (SQLite ou fichier).
 */
void database_init(void);

/** Sauvegarde un événement dans la base.
 *  Les structures détaillées sont à implémenter.
 */
void database_save_event(const char *event);

#ifdef __cplusplus
}
#endif

#endif // DATABASE_H
