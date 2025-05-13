inherit "room/room";

#include "/players/tamina/defs.h"

object dragon, sword;

void reset(int arg) 
{
  dragon = present("steel dragon");
  if (!dragon)
  {
    dragon = clone_object("obj/monster");

    dragon->set_name("steel dragon");
    dragon->set_race("dragon");
    dragon->set_gender(1);
    dragon->set_level(24);
    dragon->set_long("A massive Steel Dragon.\n");
    dragon->set_wc(31);
    dragon->set_ac(8);
    dragon->set_aggressive(1);
    dragon->set_spell_mess1("The Steel Dragon spits steel splinters.\n");
    dragon->set_spell_mess2("The Dragon spits steel splinters at you !!\n");
    dragon->set_spell_dam(42);
    dragon->set_chance(50);

    sword = clone_object(TWP + "giant_slayer");

    transfer(sword, dragon);
    move_object(dragon, this_object());
  }
  if (arg) return 0;

    set_light(1);
    short_desc = "Huge Cavern";
    long_desc =
"This huge cavern has been dug out of the solid\n"+
"rock. Huge gouge marks can been seen where\n"+
"steel claws have ripped out chunks of rock.\n";

    dest_dir = ({
   TCOLD + "ice_drag", "east"
    });

}
