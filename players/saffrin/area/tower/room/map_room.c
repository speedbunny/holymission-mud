inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="The Mage Mapping Room";
  long_desc=
    "You are standing in the mapping room of the mage tower. "+
    " There are several shelves all around the room.  Books, "+
    "scrolls, and papers scattered about.  This room is very "+
    "cluttered and dirty.  It is extremely musty in here, "+
    "considering it is a mapping room.\n";
  smell="There is an odor of must in the air\n";
  property=({ "no_fight", "no_teleport" });
  items=({
      "shelf","Alot of dusty shelves",
      "shelves","Alot of dusty shelves",
      "books","Old, rotted books, one of them is glowing",
      "book", "A book whose glow draws you to it",
      "glow", "A green glow that begs to be read",
      "papers","Old papers that are crumbling with age",
      "scrolls","The scrolls that look water damaged"
  });
  dest_dir=({
      TOWER+"room/hall2", "south",
  });
  ::reset();
}

init() {

  ::init();
  AA("search","search");
  AA("read", "read");
  AA("push","push");
}

search(str) {

  if(str!="room") return 0;

  ME("As you look closer, you realize you can see no more "+
     "than before.\n");
  return 1;
}

push(str) {

  if(str="glow") {
      ME("You are suddenly teleported to a special place.\n");
      TP->MP(" vanishes in a green glow#"+TOWER+"room/inner");
   return 1;
  }
 return 0;
}

read(str) {

  if(str="glow") {
      ME("The glow reads: Push Me.\n");
      say(CQN+" reads a glow.\n");
    return 1;
  }
 return 0;
}
