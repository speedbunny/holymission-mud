inherit "obj/monster";
void reset(int arg){
    ::reset();

    set_name("dog");
    set_race("dog");
    set_alt_name("mastiff");
    set_gender(1);
    set_alias("dog");
    set_short("Mastiff");
    set_long(
"This huge mastiff sits and drool's looking quite droopy.  However, as "+
"it walks, its leg muscles ripple betraying its true strength.  One of "+
"its massive teeth hangs out from under its lip.\n");
    set_level(15);
    set_hp(550);
    set_al(40);
    set_ac(6);
    set_wc(20);
}
