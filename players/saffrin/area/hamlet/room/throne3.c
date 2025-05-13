inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "A balcony";
  long_desc = 
      "You are on the the cool marble balcony of the ballroom for the castle of Denmark.  "+
      "There are Roman pillared columns holding up the structure with an oak rail along the "+
      "south and east sides.  The view is stunning, showing the courtyard below.  "+
      "There is a marble bench with a swirling iron backing resting against the south rail.  "+
      "In the southeast corner, there is a clay pot filled with roses.\n";
  dest_dir=({
      HAM+"room/throne2", "north",
      HAM+"room/throne6", "west",
  });
  items=({
      "balcony#columns#structure", "Made from marble in a Roman design",
      "rail", "Made from sturdy oak",
      "view","A view of the courtyard below",
      "bench", "Made from marble with an iron back",
      "back#backing", "A swirling iron backing",
      "pot#clay", "A clay pot filled with roses",
      "roses", "Many different colored roses",
  });
  clone_list=({
      1, 1, "polonius", HAM+"npc/polonius", 0,
  });
  ::reset();
  replace_program("room/room");
}
