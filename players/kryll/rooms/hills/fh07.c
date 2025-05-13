inherit "/room/room";

#include "/players/kryll/rooms/room_defs.h"
#include <material.h>
#include <objects.h>

void reset(int arg) {
  short_desc="An alcove in the foothills";
  long_desc=
    "This alcove is definitely a great place to set up an ambush, "+
    "but it appears that its inhabitants are either too lazy to "+
    "move or just dead. The path is back to the west.\n";

  set_light(1);

  items=({
    "mountain", "The mountain to the north is the tallest mountain " +
      "around and the peak is obscured by the clouds",
    "clouds", "Large fluffy things floating in the sky",
    "foothills", "Rough, rocky hills",
    "rocks", "They block all the other exits",
    "path", "It is natural and not cut",
    "alcove", "A small area inside the rock. It is perfect for an "+
      "ambush",
   });

  smell="\nThe foul smell of kobold surrounds you.\n\n";

  dest_dir=({
    HILLS + "fh08", "east",
    HILLS + "fh06", "south",
  });

  clone_list = ({
    1, 6, "Kobold Warrior", KOBOLDS + "k_warrior", 0,
    -1, 1, "shortsword", "obj/weapon", ({
      "set_name", "shortsword",
      "set_alias_list", ({ "sword" }),
      "set_short", "A shortsword",
      "set_long", "A regular shortsword. There is nothing special "+
        "about it.\n",
      "set_class", 13,
      "set_type", SLASH,
      "set_material", METAL,
      "set_value", 100,
      "set_size", 2,
      "set_weight", 2,
    }),
    -1, 1, "leather jacket", "obj/armour", ({
      "set_name", "leather jacket",
      "set_alias_list", ({ "jacket", "leather" }),
      "set_short", "A leather jacket",
      "set_long", "A small jacket made of leather.\n",
      "set_type", "armour/arm",
      "set_size", 2,
      "set_material", LEATHER,
      "set_value", 50,
      "set_ac", 2,
      "set_weight", 5,
    }),
  });

  ::reset(arg);
  replace_program("room/room");
}
