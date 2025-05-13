/***********************************************************
*   This is the southwest part of the mage-summonroom      *
***********************************************************/

#include "summon.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Southwest of the Summon room";
    long_desc="This is the Southwest corner of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling.\n";
    dest_dir=({ P+"summon4","north"
    	      ,P+"summon5","northeast"
	      ,P+"summon8","east"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    }
}
