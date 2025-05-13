inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle's stairwell";
  long_desc = 
      "You are at the stairwell to the castle of Denmark's ballroom.  The stairs scoop up in "+
      "a widening flare.  Each step was hand carved from the finest marble to be found in the "+
      "mines of Botswana.  The banister is made from carved cherry wood, designed by the "+
      "great scupltor, DiLaman.  At the base of the stairs are statues of lions on either side, "+
      "guarding the castle with their menacing stance.\n";
  dest_dir=({
      HAM+"room/hall14", "northwest",
      HAM+"room/throne1", "up",
  });
  items=({
      "stairs#step", "Stairs made from the finest marble",
      "marble", "Hand carved marble from Botswana",
      "banister", "Made from cherry wood and carved to perfections",
      "statues#lions", "Statues of lions in a menacing stance",
  });
  clone_list=({
      1, 1, "marcellus", HAM+"npc/marcellu", 0,
      1, 1, "bernardo", HAM+"npc/bernardo", 0,
  });
  ::reset();
  replace_program("room/room");
}
