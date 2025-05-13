inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle's dining hall";
  long_desc = 
      "You are in the large dining hall for lords and ladies of the castle of Denmark.  "+
      "There is a long oak table that stretches across the length of the room.  Large "+
      "benches line each side of the table.  A dais is set up against the east wall for the "+
      "king and queen to sit above the others while supping.  Two chairs lined in "+
      "dark red velvet rest behind a white marble table.\n";
  dest_dir=({
      HAM+"room/hall2", "north",
      HAM+"room/hall10", "south",
  });
  items=({
      "table", "One made from oak and the other from marble",
      "benches", "Wooden benches",
      "chairs", "Red velvet lined chairs",
      "velvet", "Dark red velvet",
      "dais", "A raised dais for the king and queen",
  });
  clone_list=({
      1, 3, "guard", HAM+"npc/dguard", 0,
  });
  ::reset();
  replace_program("room/room");
}
