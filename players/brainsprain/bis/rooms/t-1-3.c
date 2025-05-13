#include "doorroom.h"
#include "/players/brainsprain/bis/bisdef.h"
inherit DOOR_ROOM;

void reset(int arg) {
  clone_list = ({ 1, 1, "princess", bm+"/prin.c", 0 });
  ::reset (arg);
  short_desc = "The princesses bedroom";
  long_desc =
    "Bright colors make this room shine!  A four poster bed sits along the "+
    "northern wall.  A huge wardrobe filled with dresses of all colors and "+
    "styles cover the eastern wall.  Stuffed animals and expensive dolls "+
    "are neatly stacked along the western wall.  The floor is covered with "+
    "thick, plush, pink carpet.\n";
  set_light(1);
  dest_dir = ({
    br+"/t-1-2.c","down",
  });
  items = ({
    "room",
    "The princesses bedroom",
    "wall",
    "It is painted pretty colors",
    "bed",
    "A huge four poster bed",
    "wardrobe",
    "A massive wardrobe containing the princesses dresses",
    "dresses",
    "Dresses of all colors and designed for any occasion",
    "animals",
    "Finely crafted stuffed animals that any child would love",
    "dolls",
    "Expensive china dolls",
    "floor",
    "It is covered in a thick, soft carpet",
    "carpet",
    "A thick, soft carpet",
    "metal door", "",
  });
  set_door("metal door");
  set_door_dependent("metal door", br+"/t-1-2.c");
  replace_program(DOOR_ROOM);
}

