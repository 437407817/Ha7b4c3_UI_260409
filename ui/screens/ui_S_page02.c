




#include "../ui.h"

// #include "ui_S_page01.h"



lv_obj_t * ui_S_page02_screen = NULL;

lv_obj_t * ui_Home_espresso_header_header1 = NULL;













// 页面切换回调函数
static void back_to_page1_event_cb(lv_event_t *e) {
    lv_disp_load_scr(ui_S_page01_screen);
}

void ui_S_page02_screen_init(void) {
    ui_S_page02_screen = lv_obj_create(NULL);
    
    // 创建返回按钮
    lv_obj_t *back_btn = lv_button_create(ui_S_page02_screen);
    lv_obj_set_size(back_btn, 120, 40);
    lv_obj_align(back_btn, LV_ALIGN_CENTER, 0, 0);
    
    // 创建按钮标签
    lv_obj_t *back_btn_label = lv_label_create(back_btn);
    lv_label_set_text(back_btn_label, "Back to Page 1");
    lv_obj_center(back_btn_label);
    
    // 添加点击事件回调
    lv_obj_add_event_cb(back_btn, back_to_page1_event_cb, LV_EVENT_CLICKED, NULL);


    ui_Home_espresso_header_header1 = ui_Container_header_create(ui_S_page02_screen);
    lv_obj_set_x(ui_Home_espresso_header_header1, 0);
    lv_obj_set_y(ui_Home_espresso_header_header1, 0);

    lv_obj_add_flag(ui_comp_get_child(ui_Home_espresso_header_header1,
                                      UI_COMP_CONTAINER_HEADER_CONTAINER_HEADER_PANEL_CONTAINER_LEFT_CONTAINER), LV_OBJ_FLAG_HIDDEN);    /// Flags

    lv_label_set_text(ui_comp_get_child(ui_Home_espresso_header_header1,
                                        UI_COMP_CONTAINER_HEADER_CONTAINER_HEADER_PANEL_LABEL_TITLE), "Choose your coffee");



}



void ui_S_page02_screen_destroy(void) {
    if(ui_S_page02_screen) lv_obj_del(ui_S_page02_screen);
    ui_S_page02_screen = NULL;
}

void ui_S_page02_screen_relocalize(void) {
    // Add relocalization code if needed
}