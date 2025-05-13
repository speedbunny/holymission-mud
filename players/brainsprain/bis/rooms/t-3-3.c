inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Third floor of northwestern tower";
  long_desc =
    "This is the Count's bedroom.  The floor is covered by a giant cushion and "+
    "there are down-filled pillows scattered about the floor.  There is a "+
    "table in the center of the room with several objects and a large vat "+
    "on it. Along the northern wall is a rickety staircase leading up.\n";
  set_light(1);
  dest_dir = ({
    br+"/t-3-2.c","down",
    br+"/t-3-4.c","up",
  });
  items = ({
    "floor",
    "The floor of the count's bedroom",
    "table",
    "It is blacked and pitted from something",
    "bedroom",
    "The count's bedroom",
    "cushion",
    "A massive bed",
    "pillows",
    "Thick, downy pillows",
    "wall",
    "Northern wall of the tower",
    "tower",
    "The northwestern tower",
    "staircase",
    "A rickety staircase",
    "objects",
    "You are too young to know what these are",
    "vat",
    "Some one must have chapped lips, thats an awful lot of vasoline",
  });
  clone_list = ({ 1, 2, "eunuch", bm+"/eunuch.c", 0, });
  ::reset(arg);
  replace_program("room/room");
}

