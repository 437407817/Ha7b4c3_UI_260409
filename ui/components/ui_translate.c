#include "../ui.h"







static const char * const tags[] = {"Err Battery", "no error", "error", "highest voltage","lowest voltage", 
     "Diff Voltage", "Avg Voltage"};
static const char * const languages[] = {"English", "Deutsch", "Español", NULL};

static void add_static_translations(void)
{
    static const char * const translations[] = {
        "Err Battery",    "Err Battery1",     "Err Battery2",
        "no error",     "no error1",      "no error2",
        "error",   "error1", "error2",
        "highest voltage", "highest voltage1", "highest voltage2",
        "lowest voltage", "lowest voltage1", "lowest voltage2",

        "Diff Voltage", "Diff Voltage1", "Diff Voltage2",
        "Avg Voltage", "Avg Voltage1", "Avg Voltage2"  

    };

    lv_translation_add_static(languages, tags, translations);
}

 void on_language_change(lv_event_t * e)
{
    lv_obj_t * label      = lv_event_get_target_obj(e);
    const char * tag      = (const char *) lv_event_get_user_data(e);
    /* You can get the new language with `lv_event_get_param`*/
    const char * language = (const char *) lv_event_get_param(e);
    LV_UNUSED(language);

    lv_label_set_text(label, lv_tr(tag));
}

static void language_change_cb(lv_event_t * e)
{
    static char selected_lang[20];

    lv_obj_t * dropdown = lv_event_get_target_obj(e);

    lv_dropdown_get_selected_str(dropdown, selected_lang, sizeof(selected_lang));

    lv_translation_set_language(selected_lang);
}



/**
 * @title Static and dynamic translation packs
 * @brief Register two translation sources and print labels via `lv_tr`.
 *
 * A static pack provides the tags `tiger`, `lion`, `rabbit`, and `elephant` in
 * English, German, and Spanish through `lv_translation_add_static`. A dynamic
 * pack built with `lv_translation_add_dynamic` adds the tags `table` and
 * `chair` for English and German using `lv_translation_add_tag` and
 * `lv_translation_set_tag_translation`. `lv_translation_set_language("de")`
 * selects German and two labels render the `tiger` and `chair` translations
 * through `lv_tr`.
 */
void ui_translate_1(lv_obj_t *page)
{
    lv_obj_set_flex_flow(page, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(page, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    add_static_translations();
    const size_t tag_count = sizeof(tags) / sizeof(tags[0]) - 1;
    const size_t lang_count = sizeof(languages) / sizeof(languages[0]) - 1;

    /* Create a dropdown to be able to select the language */
    lv_obj_t * language_dropdown = lv_dropdown_create(page);
    lv_dropdown_clear_options(language_dropdown);

    for(size_t i = 0; i < lang_count; ++i) {
        lv_dropdown_add_option(language_dropdown, languages[i], i);
    }

    lv_obj_add_event_cb(language_dropdown, language_change_cb, LV_EVENT_VALUE_CHANGED, NULL);



    lv_translation_set_language("English");
}











