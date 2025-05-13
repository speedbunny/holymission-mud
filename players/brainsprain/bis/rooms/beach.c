inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "A well maintained road"; 
  long_desc = 
    "This stretch of road is lined with exotic shrubs whose flowers bloom "+
    "with an intensity that you have never before seen.  The golden "+
    "road gleams as if it was just washed.  From the north comes the "+
    "sounds of civilization.\n";
  
  set_light(1);
  
  items = ({
    "road",
    "A golden road",
    "flowers",
    "Exotic flowers, amazing to behold",
    "shrubs",
    "Thick, rich shrubs",
  });
  
  dest_dir = ({
    br+"/begin_path","north",
  });
  ::reset(arg);
  replace_program("room/room");
}
