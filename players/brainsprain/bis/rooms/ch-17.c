inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "Bismarck Hall & Entrance to the Grand Hall";
  long_desc =
"The first thing you notice as you enter the hallway is that the rug "+
"changes to purple as it leads south to the grand hall.  A stream of "+
"peasants and nobles filter in and out of the chamber.  To the east "+
"the hall gets darker and the red carpet beings again.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-18.c","east",
    br+"/ch-16.c","west",
    br+"/grnd_hl.c","south",
  });
items = ({
  "hallway",
  "The northern hallway",
  "chamber",
  "The grand hall of Castle Bismarck",
  "hall",
  "The grand hall of Castle Bismarck",
  "grand hall",
  "The grand hall of Castle Bismarck, where all citizens go to talk to the Count",
  "rug",
  "The red carpet of welcome, turning purple to the south",
  "peasants",
  "People rushing by",
  "nobles",
  "Nobles rushing by",
});

clone_list = ({ 1, 3, "guard", bm+"/guard.c", 0 });

   ::reset(arg);

    replace_program("room/room");
}
