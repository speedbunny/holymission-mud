inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg){

  short_desc = "A sandy beach";
  long_desc =
"The surf crashes onto the beach and eddies in huge pools.  Hermit crabs "+
"crawl to and fro through the sand.  The cry of some sea bird can be heard "+
"over the sound of the waves hitting the beach.  The sun beats down on the "+
"beach and the heat rises off the sand.\n";
  set_light(1);
  dest_dir = ({
   sr+"/isla2","east",
  });
  items = ({
    "sun",
    "It is directly overhead",
    "sand",
    "It covers the entire beach",
    "bird",
    "A sea bird",
    "waves",
    "Small waves crash onto the beach",
    "surf",
    "Small waves crash onto the beach",
    "beach",
    "The beach of Spiral Island",
    "spiral island",
    "The island you are standing on",
    "island",
    "Spiral Island",
    "pools",
    "All sorts of life teem in these pools",
    "crabs",
    "Aren't they cute!",
  });
}

