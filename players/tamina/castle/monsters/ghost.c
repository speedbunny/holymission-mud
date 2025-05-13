/*  This is a vicious Ghost  */

#include "/players/tamina/defs.h"

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_name("ghost");
     set_short("A wailing ghost");
     set_long(
  "A supernatural force that takes control of ordinary items, \n"+
  "and uses them to attack their foes.\n");
     set_level(21);
     set_gender(1);
     set_al(-200);
     set_aggressive(1);
     set_hp(970);
     set_wc(21);
     set_ac(10);
     set_spell_mess2("The Ghost runs its arms through your armour effortlessly\n");
     set_spell_mess1("The Ghost freezes its foe!\n");
     set_spell_dam(33);
     set_chance(5);
     add_money(100);
     load_a_chat(21, ({
   "The Ghost makes your hair stand on end in fright!\n",
   "The Ghost's cries makes your blood run cold.\n" }) );

    }

}
