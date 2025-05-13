/********************************************************
*   This is the center part of the mage-summonroom      *
********************************************************/

#include "summon.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Center of the Summon room";
    long_desc="This is the center of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling. You notice a big pentagram\n"+
              "engraved in the stonefloor.\n";
    dest_dir=({ P+"summon2","north"
    	      ,P+"summon3","northeast"
	      ,P+"summon6","east"
	      ,P+"summon9","southeast"
	      ,P+"summon8","south"
	      ,P+"summon7","southwest"
	      ,P+"summon4","west"
	      ,P+"summon1","northwest"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "pentagram","A golden pentagram engraved in the floor",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    }
}
