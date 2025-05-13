inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "Headquarters of the local militia";

  long_desc =
    "This building holds the headquarters of the local militia. "+
    "A table and some chairs stand in the room and a cupboard "+
    "hangs in a corner. In the north wall is a door with a "+
    "barred window.\n";

  dest_dir = ({
    HM_VILLAGE + "street02", "south",
  });

  items = ({
    "building","A wooden building, like most others in this village",
    "table","A deck of cards lies on it",
    "deck","A normal deck of cards, to pass the time",
    "chairs","Ordinary wooden chairs",
    "cupboard","An small cupboard, containing some empty mugs",
    "door","The reinforced wooden door suggests some kind of prison",
    "prison","Look through the window if you want to see it",
    "window","@@look_window@@",
  });

  clone_list = ({
    1, 1+random(3), "guard", "obj/monster", ({
      "set_name", "village guard",
      "set_alias", "guard",
      "set_level", 8 + random(3),
      "set_gender", 1 + random(2),
      "set_race", "human",
    }),
    -1, 1, "spear", "obj/weapon", ({
      "set_name", "spear",
      "set_class", 11,
      "set_value", 100,
    }),
    -1, 1, "cloak", "obj/armour", ({
      "set_name", "cloak",
      "set_ac", 1,
      "set_short", "A simple cloak",
      "set_type", "cloak",
      "set_value", 75,
    })
  });

  ::reset();
}

string look_window(string str) {
  string desc;

  desc = ("/room/prison")->long();
  return desc;
}
