#ifndef UI_H
#define UI_H

#ifdef __cplusplus
extern "C" {
#endif

/** Initialise l'interface LVGL. */
void ui_init(void);

/** Met à jour les éléments de l'interface (appel périodique). */
void ui_update(void);

#ifdef __cplusplus
}
#endif

#endif // UI_H
