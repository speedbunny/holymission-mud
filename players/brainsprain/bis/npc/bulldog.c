inherit "obj/monster";
void reset(int arg){
    ::reset();

    set_name("dog");
    set_race("dog");
    set_alt_name("bulldog");
    set_gender(1);
    set_alias("dog");
    set_short("Bulldog");
    set_long(
"This dog's small size and droopy face make it look harmless and docile. "+
"However the scars on his face and lack of a right eye mark him as a "+
"fierce scraper.  His white and brown hide shifts back and forth as he "+
"struts, his front legs bowed out.\n");
    set_level(5);
    set_hp(110);
    set_al(40);
    set_ac(1);
    set_wc(7);
}

