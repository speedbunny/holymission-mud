inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "The Grand Hall of Bismarck Keep";
  long_desc =
    "A carpet of interwoven silver and purple thread runs to the head of the "+
    "table.  The center of this room is dominated by a huge table and many "+
    "chairs.  The walls are adorned with the heads of the Count's hunting "+
    "prizes, including the head of a dragon.  The Bismarck Seal is on the "+
    "back of the chair at the head of the table.  To the south is the "+
    "entrance to the throne room.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-17.c","north",
    br+"/a-2.c","south",
  });
  items = ({
    "walls",
    "The are adorned with hunting prizes",
    "room",
    "The Grand Hall of Bismarck Keep",
    "keep",
    "Castle Bismarck",
    "bismarck",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",
    "carpet",
    "An interwoven carpet of silver and purple",
    "table",
    "A long table running the length of the room",
    "chairs",
    "High backed wooden chairs",
    "seal",
    "The glyph of the HighLord",
    "prize",
    "An elk and its ilk",
    "head",
    "A dragon, sticking out his tongue",
    
  });
  clone_list = ({ 1, 2, "page", bm+"/page.c", 0,
		  1, 2, "dog", bm+"/mastiff.c", 0,
  });     
  ::reset(arg);
  replace_program("room/room");
}

