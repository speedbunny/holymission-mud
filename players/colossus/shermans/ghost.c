/* Edited by Colossus 022494 */

#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("ghost");
    set_level(18);
    set_hp(700);
    set_al(-300);
    set_ac(12);
    set_aggressive(1);
    set_wc(18);
    set_race("undead");
    set_short("Ghost");
    set_long(
      "The ghost is a shimmering form with chains draped around it\n"+
      "depicting how it is chained to this unnatural half-life. The\n"+
      "tone of its wails and the way it advances towards you appear\n"+
      "aggressive. It waves an ethereal hand towards you and lets\n"+
      "out a wail whose very sound cries out for vengeance.\n");
    set_chance(15);
    set_spell_mess1("Ghost touches its victim.\n");
    set_spell_mess2("Ghost drains you.\n");
    set_spell_dam(25);
}
