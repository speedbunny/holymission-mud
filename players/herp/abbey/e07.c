#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Intersection";
     long_desc=
"A narrow paths winds its way around the abbey, extending east and west from\n"+
"here.  The great gates to the abbey are to the south.  On them is a embla-\n" +
"zoned a huge rose and the words: 'stat rosa pristina nomine, nomina nuda\n" +
"tenemus'.\n";
     dest_dir=({ PATH+"/e06","north",
		 PATH+"/e08","south",
		 PATH+"/o04","west",
		 PATH+"/o05","east" });
  }
}
