#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc="Inside the cave";
    long_desc=
      "You finally enter the cave system proper. From here you\n"+
      "can see by the light of the phosperous walls. A pile of\n"+
      "bones can be seen to one side.... and the walls seem to\n"+
      "be dented in some way.\n";

    dest_dir=({
	MYAREA+"/room/l17","south",
         MYAREA+"/room/l12","north",
	});
    items=({
      "bones","Many bones... you wonder where they come from",
      "pile","A pile of bones",
         });

    MOVE(CLONE(MYAREA+"/monster/orc"),TO);
    MOVE(CLONE(MYAREA+"/monster/orc"),TO);
    }
  }

init()
{
  ::init();
  }
