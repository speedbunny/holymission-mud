/***********************************************************
*   This is the southeast part of the mage-summonroom      *
***********************************************************/

#include "summon.h"

reset(arg) { 
  ::reset(arg);
  if(!arg) {
    short_desc="Southeast of the Summon room";
    long_desc="This is the southeast corner of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling. You see a stair leading\n"+
              "down here.\n";
    dest_dir=({ P+"summon6","north"
    	      ,P+"summon5","northwest"
	      ,P+"summon8","west"
              ,"players/llort/guild/tower/hallway3","down"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    }
}

init() {
  ::init();
  add_action("down","down",1);
}

down()
{
  return ::move();
}
