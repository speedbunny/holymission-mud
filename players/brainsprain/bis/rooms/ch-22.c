inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "A secret part of Bismarck Hall";
  long_desc =
    "This is a secret part of Bismarck Keep.  There is several piles of old "+
    "cloth lying on the floor and a rotting tapestry on the eastern wall. "+
    "Several rats skitter across the room and disappear into holes in the wall.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-23.c","south",
    br+"/ch-21.c","north",
  });
  items = ({
    "floor",
    "The floor of the room",
    "room",
    "Part of the secret hallway",
    "wall",
    "The eastern wall",
    "keep",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",
    "bismarck",
    "Castle Bismarck",
    "cloth",
    "Piles of old napkins",
    "tapestry",
    "An old, faded tapestry",
    "rats",
    "Small, brown rats",
    "holes",
    "Mouse houses",
  });
  ::reset(arg);
  replace_program("room/room");

}
