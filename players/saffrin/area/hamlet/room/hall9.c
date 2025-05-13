inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle servents' dining hall";
  long_desc = 
     "You are in the small and cramped servants dining hall of the castle of Denmark.  "+

      "There is a small half broken table in the center of the room, with chairs around it."+
      "The chairs appear to be from the castle that were discarded by a member of the "+
      "royal family.  The walls are completely bare, giving the room a cold and hard feeling "+
      "to it\n";
  dest_dir=({
      HAM+"room/hall10", "northeast",
  });
  items=({
      "table", "A small wooden table that is slightly broken",
      "walls", "Cold and bare",
      "chairs","Broken down chairs",
  });
  clone_list=({
      1, 2, "guard", HAM+"npc/dguard", 0,
  });
  ::reset();
  replace_program("room/room");
}
