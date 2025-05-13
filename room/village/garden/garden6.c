inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  clone_list = ({
    1, 2, "sheep", "obj/monster", ({
      "set_name", "sheep",
      "set_level", 3,
      "set_race", "sheep",
      "set_long", "A sheep munching on some grass.\n",
    }),
  });

  set_light(1);
  short_desc = "In a beautiful garden";
  long_desc = 
    "The northeastern corner of the garden consists of little more "+
    "than grass. Apparently, Chantilly likes her sheep to have "+
    "more than enough food. The town wall blocks passage to the "+
    "north and east, however the rest of the garden is still open. "+
    "There is also a tree to the south.\n";

  items = ({
    "garden","Here the garden consists mainly of grass",
    "wall", "There is a wall directly north and east",
    "grass", "The area is covered in it",
    "tree", "There is a large apple tree to the south",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "garden5", "west",
    VILLAGE_GARDEN + "garden3", "south",
  });

  ::reset(arg);
  replace_program("/room/room");
}

