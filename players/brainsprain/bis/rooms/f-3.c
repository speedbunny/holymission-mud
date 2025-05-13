inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
  short_desc = "Bismarck Hunting Reserve"; 
  long_desc = "The foot path ends here abruptly and the forest envelops you. "+
              "The smell of old leaves and pine pitch fills the air.  Birds "+
              "soar above and fill the air with song.  There are fresh deer "+
              "tracks leading north.\n";
  set_light(1);
  items = ({
    "birds","Beautiful blue birds",
    "path","The foot path ends here",
    "forest","An old growth forest",
    "tracks","Heart shaped foot prints",
  });
  dest_dir = ({
    br+"/f-2.c","west",
    br+"/f-4.c","east",
    br+"/f-10.c","north",
    br+"/f-11.c","northeast",
    br+"/f-20.c","south",
    br+"/f-21.c","southeast",
 });
  ::reset(arg);

    replace_program("room/room");
}
