#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
 
 
    set_name("spider");
    set_alias("spider");
    set_short("A hairy spider");
    set_long("A small hairy spider.\n");
    set_gender(1);
    set_level(3);
    set_aggressive(1);
    set_al(-20);
    set_chance(1);
    set_spell_mess1("throws a web at your face.");
    set_spell_mess2("nips your feet.");
    set_spell_dam(10);
}
 
