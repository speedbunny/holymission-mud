inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "Bismarck Hunting Reserve";
  long_desc = 
    "This winding path leads into the heart of the forest.  Massive "+
    "oaks and poplars are intermixed with swaying palm trees.  These "+
    "forests are a famous hunting preserve.  Because of its unique "+
    "climate, almost any animal can be found here.\n";
  set_light(1);
  items = ({
    "oaks","Huge oak trees",
    "poplars","Huge poplar trees",
    "forest","A full growth forest",
    "trees","Swaying palm trees",
    "preserve","The hunting preserve of Count Bismarck",
    "path","A winding path through the forest",
    "palm trees","Delicate palm trees",
  });
  dest_dir = ({
    br+"/begin_path.c","west",
    br+"/f-2.c","east",
  });
  ::reset(arg);

    replace_program("room/room");
}
