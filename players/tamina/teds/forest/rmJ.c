inherit "room/room";

#include "/players/tamina/defs.h"

object tiger;

void reset(int arg) {
  if(arg) return 0;

  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"The forest is especially dense here, you have to push\n"+
"through undergrowth so thick you can see no more than\n"+
"an arms length in front of you.\n";

    dest_dir = ({
    TFOREST + "rmP", "north",
    TFOREST + "rmE", "south",
    TFOREST + "rmK", "east",
    });

    clone_list = ({
  1, 1, "tiger", "obj/monster", 
({"set_name", "tiger", 
  "set_short", "Jungle Tiger", 
  "set_long", 
    "This is a fierce looking Jungle Tiger.  It looks hungry.\n", 
  "set_level", 26,
  "set_wc", 30,
  "set_ac", 14, 
  "set_aggressive", 1,
  "set_spell_mess1", "The tiger's claws slash.\n",
  "set_spell_mess2", "The tiger's claws slash your face.\n",
  "set_spell_dam", 25,
  "set_chance", 15,}), });

    ::reset(arg);
    replace_program("room/room");
}
