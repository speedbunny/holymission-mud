inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "The sounds of partying come from the south.  However, to the north is "+
    "absolute silence.  The hall is noticeably darker than you would expect "+
    "it to be.  There is only one torch in the entire area and one window.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-11.c","north",
    br+"/ch-9.c","south",
  });
  items = ({
    "hall",
    "The western hall of Castle Bismarck",
    "bismarck",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",
    "torch",
    "A sputtering torch that is bolted to the wall",
    "window",
    "A small window high up on the wall",
  });
  ::reset(arg);
  replace_program("room/room");
}
