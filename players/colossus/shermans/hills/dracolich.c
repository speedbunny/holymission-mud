#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("dracolich");
    set_level(50);
    set_hp(3000);
    set_al(-500);
    set_ac(20);
    set_aggressive(1);
    set_wc(50);
    set_race("undead");
    set_short("Dracolich");
    set_long("A animated skeleton of a dead dragon.\n");
    set_chance(10);
    set_spell_mess1("The Dracolich shoots a lightning bolt agains his\n"+
      "opponent");
    set_spell_mess2("The Dracolich zaps you");
    set_spell_dam(70);
}
