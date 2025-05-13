inherit "room/room";

#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage Tower Research Library";
  long_desc =
      "You are in the research library of the Mage Tower.  All the walls are "+
      "lined with bookshelves and rows of dusty books.  There is a desk in the middle "+
      "of the room with an open book resting on top of it.  The books is about "+
      "spells.  A large chair sits behind the desk.  In the northwest corner, "+
      "there is a step ladder.\n";

  dest_dir=({
       TOWER+"room/hall3", "west",
  });
  items=({
      "bookshelves", "Filled with books on spells, castings, and potions",
      "books", "Dusty books about spells, castings, and potions",
      "rows", "Rows of dusty books on spells, castings, and potions",
      "desk", "A large oak desk with a book on top",
      "chair", "A large oak chair",
      "ladder", "Step ladder used for reaching books on the top shelf",
      "book", "Try reading it",
  });
}

init() {

  ::init();
  AA("read","read");
 return 1;
}

read(str) {

  if(str!="book") return 0;
     cat(TOWER+"books/library");
     say(TPQN +" reads a book.\n");
  return 1;
}
