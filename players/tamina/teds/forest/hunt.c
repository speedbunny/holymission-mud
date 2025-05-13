inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  if(arg) return 0;
  set_light(1);
  short_desc = "Hunters Camp";
  long_desc =
"A small cooking fire is the only sign that any one\n"+
"was ever here at all.\n";
 
   dest_dir = ({
TFOREST + "forest24", "west"
    });

    clone_list = 
  ({1, 1, "hunter", "obj/monster", 
    ({"set_name", "hunter",
      "set_race", "human",
      "set_gender", 1,
      "set_long", "This is an experienced looking hunter.\n",
      "set_level", 8,
      "set_wc", 15,
      "set_ac", 3,
      "set_al", 60, }),
    2, 1, "hunter", "obj/monster",
    ({"set_name", "hunter",
      "set_race", "human",
      "set_gender", 1,
      "set_long", "This is an experienced looking hunter.\n",
      "set_level", 10,
      "set_wc", 17,
      "set_ac", 5,
      "set_al", 50, }),
    -1, 1, "boots", "obj/armour",
    ({"set_name", "Leather Boots",
      "set_alias", "leather boots",
      "set_type", "boots",
      "set_size", 3,
      "set_short", "Soft Leather Boots",
      "set_long", "These soft leather boots come up to about mid-thigh.\n",
      "set_ac", 1,
      "set_weight", 1,
      "set_value", 250, }),
    -2, 1, "gloves", "obj/armour",
    ({"set_name", "Leather Gloves",
      "set_alias", "leather gloves",
      "set_type", "gloves",
      "set_short", "Soft Leather Gloves",
      "set_long", "These are well-tanned soft leather gloves, which are very comfortable.\n",
      "set_size", 3,
      "set_ac", 1,
      "set_weight", 1,
      "set_value", 250, }), });

    ::reset();
    RPR("room/room");
}
