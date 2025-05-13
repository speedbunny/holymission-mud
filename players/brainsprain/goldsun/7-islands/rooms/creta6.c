inherit "/room/room";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 set_light(1);
 short_desc=("Large plain");
 long_desc=
"A large green plain spreads from the north coast to the west coast. The "+
"high grass blows in the coastal wind.  Several trees and bushes dot the "+
"plain.  To the southeast you can see Madaros, the highest peak on the "+
"island.\n";

 smell="A smell of herbs.";

 dest_dir=({
   ir+"/creta5","north",
   ir+"/creta7","south",
   ir+"/creta3","west",
	   });

 items=({"plain",long_desc,
   "grass","This high grass blows in the coastal wind",
   "trees","They dot the plain",
   "bushes","Thick sagamore bushes",
	 "island",long_desc,
         "madaros","The highest peak on the island",
         "mountain","Madaros is to the southeast.",
         });
 }
 ::reset(arg);
 replace_program("room/room");
}


  
  
