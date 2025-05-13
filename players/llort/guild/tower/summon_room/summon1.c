/***********************************************************
*   This is the northwest part of the mage-summonroom      *
***********************************************************/

#include "summon.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Northwest of the Summon room";
    long_desc="This is the northwest corner of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling.\n";
    dest_dir=({ P+"summon2","east"
    	      ,P+"summon4","south"
	      ,P+"summon5","southeast"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    }
}
