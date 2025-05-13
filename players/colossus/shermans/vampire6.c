/* Edited by Colossus 030594 */

#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("vampire lady");
    set_alt_name("vampire");
    set_alias("vampiress");
    set_level(20);
    set_hp(400);
    set_al(-250);
    set_ac(15);
    set_wc(25);
    set_aggressive(1);
    set_race("undead");
    set_short("Vampiress");
    set_long(
      "The vampiress at first looks like a beautiful and sexy\n"+
      "lady though the fangs reveal her true nature. She is\n"+
      "dressed in a teddy and has beautiful dark hair. From all\n"+
      "superficial appearances, she is an amazingly attractive\n"+
      "lady. You have no problem believing otherwise, however, as\n"+
      "she gazes at you with her blood-red eyes.\n");
}
