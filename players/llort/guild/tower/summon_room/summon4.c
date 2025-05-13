/******************************************************
*   This is the west part of the mage-summonroom      *
******************************************************/

#include "summon.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="West of the Summon room";
    long_desc="This is the western part of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling.\n";
    dest_dir=({ P+"summon1","north"
    	      ,P+"summon2","northeast"
    	      ,P+"summon5","east"
    	      ,P+"summon8","southeast"
    	      ,P+"summon7","south"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    }
}
