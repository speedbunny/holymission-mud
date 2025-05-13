/*  This is a Maze monster  */

#include "/players/tamina/defs.h"

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_name("stalker");
     set_short("A Stalker");
     set_long(
"An ominous, dark figure that flits through shadows with a \n"+
"deathly silence.\n");
     set_level(25);
     set_race("demon");
     set_gender(1);
     set_al(-100);
     set_aggressive(1);
     set_hp(1000);
     set_wc(30);
     set_ac(12);
     set_spell_mess2("The Stalker drums his fist into your face!\n");
     set_spell_mess1("The Stalker thumps his opponent in the jaw!\n");
     set_spell_dam(50);
     set_chance(10);
     add_money(1500);
     set_move_at_reset(1);

   }

}
