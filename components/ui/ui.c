#include "ui.h"
#include "lvgl.h"
#include "esp_log.h"
#include "esp_heap_caps.h"
#include "esp_timer.h"
#include "lvgl_helpers.h"
#include "disp_driver.h"
#include "touch_driver.h"

static const char *TAG = "ui";

#define DISP_HOR_RES 800
#define DISP_VER_RES 480
#define DISP_BUF_LINES 40
#define DISP_BUF_SIZE (DISP_HOR_RES * DISP_BUF_LINES)

static lv_disp_draw_buf_t s_draw_buf;
static lv_color_t *s_buf1;
static lv_color_t *s_buf2;
static esp_timer_handle_t s_tick_timer;

static void lv_tick_cb(void *arg)
{
    (void)arg;
    lv_tick_inc(10);
}

void ui_init(void)
{
    ESP_LOGI(TAG, "Initialisation de LVGL");
    lv_init();

    lvgl_driver_init();

    s_buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    s_buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    lv_disp_draw_buf_init(&s_draw_buf, s_buf1, s_buf2, DISP_BUF_SIZE);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_driver_flush;
    disp_drv.draw_buf = &s_draw_buf;
    disp_drv.hor_res = DISP_HOR_RES;
    disp_drv.ver_res = DISP_VER_RES;
    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touch_driver_read;
    lv_indev_drv_register(&indev_drv);

    const esp_timer_create_args_t tick_args = {
        .callback = lv_tick_cb,
        .name = "lvgl_tick"
    };
    esp_timer_create(&tick_args, &s_tick_timer);
    esp_timer_start_periodic(s_tick_timer, 10 * 1000);

    lv_obj_t *tv = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 50);
    lv_obj_t *tab1 = lv_tabview_add_tab(tv, "Accueil");
    lv_obj_t *tab2 = lv_tabview_add_tab(tv, "Evenements");
    lv_obj_t *tab3 = lv_tabview_add_tab(tv, "Reglages");

    lv_obj_t *label = lv_label_create(tab1);
    lv_label_set_text(label, "Bienvenue");
    label = lv_label_create(tab2);
    lv_label_set_text(label, "Aucun evenement");
    label = lv_label_create(tab3);
    lv_label_set_text(label, "Parametres");
}

void ui_update(void)
{
    // Appel périodique pour mettre à jour LVGL.
    lv_timer_handler();
}
