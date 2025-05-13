inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "A balcony";
  long_desc = 
      "You are on the the cool marble balcony of the ballroom for the castle of Denmark.  "+
      "There are Roman pillared columns holding up the structure with an oak rail along the "+
      "north and west sides.  The view is stunning, showing the beautiful gardens below.  "+
      "There is a marble bench with a swirling iron backing resting against the north rail.  "+
      "In the northwest corner, there is a clay pot filled with safflowers.\n";
  dest_dir=({
      HAM+"room/throne14", "south",
      HAM+"room/throne10", "east",
  });
  items=({
      "balcony#columns#structure", "Made from marble in a Roman design",
      "rail", "Made from sturdy oak",
      "view","A view of the gardens below",
      "bench", "Made from marble with an iron back",
      "back#backing", "A swirling iron backing",
      "pot#clay", "A clay pot filled with safflowers",
      "safflowers", "Golden yellow safflowers",
  });
  clone_list=({
      1, 2, "guard", HAM+"npc/dguard", 0,
  });
  ::reset();
  replace_program("room/room");
}
