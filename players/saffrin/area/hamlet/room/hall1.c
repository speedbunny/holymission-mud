inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle's entrance";
  long_desc = 
      "You are at the entrance to the castle of Denmark.  The ceiling above you scoops "+
      "high and is lined with stained glass.  The floors are made from the finest Italian marble, "+
      "specially imported by the late King Hamlet.  To the east is the main receiving room "+
      "for the guests of the kingdom.  A hall is located to the south of here.  "+
      "There is a large marble stairway that leads down to the gardens of the castle"+
      " of Denmark.\n";
  dest_dir=({
      HAM+"room/hall2", "south",
      HAM+"room/hall3", "east",
      HAM+"room/garden5", "down",
  });
  items=({
      "ceiling", "High scooped ceiling made from stained glass",
      "glass", "Swirling desgins of green and blue",
      "floors", "Made from the finest Italian marble",
      "marble", "The finest Italian marble",
      "stairway", "A large white marble stairway",
  });
  ::reset();
  replace_program("room/room");
}
