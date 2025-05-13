inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Second floor of northwestern tower";
  long_desc =
    "The walls of this room are draped with fine silk.  Along the northern "+
    "wall is a desk and a bookshelf containing the Count's collection of rare "+
    "books.  The staircase continues up to the next level and down to the "+
    "ground floor.  To the southeast is an open door. \n";
  set_light(1);
  dest_dir = ({
    br+"/t-3-1.c","down",
    br+"/t-3-3.c","up",
    br+"/sec-1.c","southeast",
  });
  items = ({
    "wall",
    "It is draped in silk",
    "walls",
    "They are draped with fine silk",
    "door",
    "A door leading the way to Duke Jasper's room",
    "staircase",
    "A spiral staircase leading up and down the tower",
    "silk",
    "The finest silk in all the land",
    "desk",
    "The Count's desk",
    "bookshelf",
    "A bookshelf containing many books of lost lore",
  });
  ::reset(arg);
  replace_program("room/room");
}


