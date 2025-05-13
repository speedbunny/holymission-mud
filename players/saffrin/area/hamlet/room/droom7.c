inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
   set_light(1);
   short_desc = "Costume shop";
   long_desc = 
      "You are in the costume shop of the theatre.  This is where the players sew "+
      "costumes for the shows they appear in.  There are several wooden shelves that "+
      "are filled with material lining the north wall.  Wooden boxes filled "+
      "pins and needles are all over the place.  Along the east wall are several "+
      " shelves pilled high.  They are filled with scraps of cloth in various"+
      " colors.  A wooden ladder is resting against the shelves.  "+
      "A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom3", "northwest",
  });
  hidden_dir=({
      HAM+"room/shake1", "up",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "planks", "Long wooden planks covering several holes in the floor",
      "material#scraps#cloth", "Several colors and styles",
      "shelves", "Shelves filled with material and scraps of cloth",
      "ladder", "A small wooden ladder you might be able to go up",
      "boxes", "Wooden boxes filled with pins and needles",
  });
  clone_list=({
      1, 3, "player", HAM+"npc/player", 0,
  });
  ::reset();
  replace_program("room/room");
}
