/******************************************************
*   This is the east part of the mage-summonroom      *
******************************************************/

#include "summon.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="East of the Summon room";
    long_desc="This is the eastern part of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling.\n";
    dest_dir=({ P+"summon3","north"
    	      ,P+"summon9","south"
	      ,P+"summon8","southwest"
	      ,P+"summon5","west"
	      ,P+"summon2","northwest"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    }
}
