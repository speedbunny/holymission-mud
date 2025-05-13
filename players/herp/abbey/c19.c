#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Pantry";
     long_desc=
"This room holds the ingredients and staples to meet the immediate cooking\n"+
"needs of the Abbey cook.  All supplies are carefully secured to prevent\n"+
"pilfering by peasants and rats.  There is an incongrous basket of mangoes\n"+
"on a low shelf here.\n";
     dest_dir=({ PATH+"/c18","north" });
  }
}
