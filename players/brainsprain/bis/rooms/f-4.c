inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {

  short_desc = "Bismarck Hunting Reserve";  
     long_desc = "The foot path ends here abruptly and the forest envelops you.  The smell of "+
                 "old leaves and pine pitch fill the air.  Birds soar about and sing their "+
                 "songs.   A wall of trees rises up to east and stops any further travel in "+
                 "that direction.\n";
  set_light(1);
  items = ({
    "path","The foot path ends here",
    "forest","An old growth forest",
    "birds","Beautiful blue birds",
    "tracks","Heart shaped foot prints",
    "trees","A huge stand of trees",
  });
  dest_dir = ({
    br+"/f-3.c","west",
    br+"/f-11.c","north",
    br+"/f-21.c","south",
    br+"/f-10.c","northwest",
 });
  ::reset(arg);

    replace_program("room/room");
}
