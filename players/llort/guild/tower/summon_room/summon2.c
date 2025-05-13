/*******************************************************
*   This is the north part of the mage-summonroom      *
*******************************************************/

#include "summon.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="North of the Summon room";
    long_desc="This is the northern part of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling.\n";
    dest_dir=({ P+"summon3","east"
    	      ,P+"summon6","southeast"
    	      ,P+"summon5","south"
    	      ,P+"summon4","southwest"
    	      ,P+"summon1","west"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    }
}
