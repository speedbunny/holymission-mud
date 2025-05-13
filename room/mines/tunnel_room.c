inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "small room";
  long_desc =
    "You have wandered out of the mines themselves and into a small "+
    "room with rough cut walls.  Small muddy footprints track across the "+
    "floor.\n";

  items = ({
    "walls","They are made of stone because the rooms was chiselled out "+
      "of the mountain's innards",
    "footprints","They appear to have been created by a hobgoblin",
    "floor","Muddy footprints mar the smooth stone floor",
      "of the mountain innards",
  });

  dest_dir = ({
    "/players/silas/caves/tunnel1", "north",
    MINES + "tunnel05", "south",
  });

  clone_list = ({
    1, 1, "hobgoblin", "obj/monster", ({
      "set_name", "A hobgoblin",
      "set_alias_list", ({ "goblin", "hobgoblin" }),
      "set_level", 5,
      "set_race", "goblin",
      "set_size", 3,
      "set_wc", 9,
      "set_short", "A hobgoblin",
      "set_long", "This hobgoblin looks really nasty.\n",
      "add_money", 50
    }) 
  });

  ::reset(arg);
  replace_program("room/room");
}
