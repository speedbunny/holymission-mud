/* Edited by Colossus 030494 */

#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("vampire");
    set_level(35);
    set_hp(2000);
    set_al(-500);
    set_ac(18);
    set_aggressive(1);
    set_wc(30);
    set_race("undead");
    set_short("Vampire");
    set_long(
      "The vampire is a tall pale man with glowing red eyes and\n"+
      "incisors that stick out of his mouth. He wears black clothes\n"+
      "and a flowing cape. He appears intent to have you as a meal.\n"+
      "This must be one of the Vampire King's minions.\n");
    set_chance(20);
    set_spell_mess1("Vampire stares into his victims eyes");
    set_spell_mess2("Vampire reaches out a hand and drains you.");
    set_spell_dam(60);
}
