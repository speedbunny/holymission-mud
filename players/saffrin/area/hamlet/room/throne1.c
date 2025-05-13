inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle's stairwell";
  long_desc = 
      "You are at the stairwell to the castle of Denmark's lower floor.  The stairs scoop down in "+
      "a widening flare.  Each step was hand carved from the finest marble to be found in the "+
      "mines of Botswana.  The banister is made from carved cherry wood, designed by the "+
      "great scupltor, DiLaman.  At the top of the stairs are statues of lions on either side, "+
      "guarding the castle with their menacing stance.\n";
  dest_dir=({
      HAM+"room/throne2", "south",
      HAM+"room/throne4", "west",
      HAM+"room/hall15", "down",
  });
  items=({
      "stairs#step", "Stairs made from the finest marble",
      "marble", "Hand carved marble from Botswana",
      "banister", "Made from cherry wood and carved to perfections",
      "statues#lions", "Statues of lions in a menacing stance",
  });
  ::reset();
  replace_program("room/room");
}
