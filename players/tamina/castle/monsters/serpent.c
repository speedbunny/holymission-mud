#include "/players/tamina/defs.h"

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_name("Sea Serpent");
     set_alt_name("serpent");
     set_alias("sea");
     set_short("Sea Serpent");
     set_long(
"This is a great beast, that lives undisturbed in the moat of Camelot.\n"+
"It is very long, being about 20 feet in length, with a long tail.\n"+
"It's mouth is full of very sharp teeth.\n");
     set_level(29);
     set_gender(1);
     set_al(-350);
     set_aggressive(1);
     set_wc(30);
     set_ac(14);
     set_spell_mess2("The Sea Serpent shoots a bolt of water at you !!\n");
     set_spell_mess1("A bolt of water shoots out from the Sea Serpent's mouth !!\n");
     set_spell_dam(35);
     set_chance(17);
     add_money(2500);

    }

}
