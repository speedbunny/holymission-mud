inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Practice Room";
    long_desc =
"This room has wooden swords and shields in neat rows and\n"+
"in shelves along the walls. A round space in the center\n"+
"of the room is covered with leather and looks padded. A\n"+
"large window almost takes up the entire west wall.\n";

    dest_dir = ({
      TFIRE + "tower3", "east"
    });

    items = ({
"window","Out the window you see a large forest of petrified trees",
"windows","Out the window you see a large forest of petrified trees",
"shelf", "You see on the shelves rows of practice swords and shields.\n"+
         "You have no desire to take them, as they are made of wood",
"shelves", "You see on the shelves rows of practice swords and shields.\n"+
           "You have no desire to take them, as they are made of wood"
    });

    clone_list = 
  ({ 1, 1, "fire giant captain", "players/tamina/teds/monsters/fire_giant_captain", 0,
    -1, 1, "bastardsword", "obj/weapon",
    ({
      "set_name", "Fire Giant Bastardsword",
      "set_alias", "sword",
      "set_short", "A Fire Giant's Bastardsword",
      "set_long", "This is a finely made sword, large, strong and sharp.\n",
      "set_class", 18,
      "set_weight", 4,
      "set_value", 2500,
    }),
    -1, 1, "key", "obj/treasure",
    ({
      "set_id", "key",
      "set_alias", "fire_key",
      "set_short", "A Red Key",
      "set_weight", 1,
      "set_value", 100,
    }),
  });

    ::reset(arg);
    RPR("room/room");
}
