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
    "The northwest corner of the garden consists of little more "+
    "than grass. Apparently, Chantilly likes her sheep to have "+
    "more than enough food. The town wall blocks passage to the "+
    "north and Chantilly's house blocks westward, however the rest "+
    "of the garden is still open.\n";

  items = ({
    "wall", "There is a wall directly north",
    "house", "Chanitilly's house is directly west, but there is no "+
      "entrance into it from this side",
    "garden","The flowers have given way to grass so that the sheep can graze",
    "grass", "The area is covered in it",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "garden5", "east",
    VILLAGE_GARDEN + "garden1", "south",
  });

  ::reset(arg);
  replace_program("/room/room");
}

