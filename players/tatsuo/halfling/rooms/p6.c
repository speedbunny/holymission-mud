inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg) {

  if(!present("guard")){ MO(CO(HMON+"guard"),TO); }
  if(!present("halfling")){ MO(CO(HMON+"halfling"),TO); 
                         MO(CO(HMON+"halfling"),TO); 
                         MO(CO(HMON+"halfling"),TO); 
                         MO(CO(HMON+"halfling"),TO); 
                         MO(CO(HMON+"child"),TO); }
  if(!present("child")){
                         MO(CO(HMON+"woman"),TO);  
                         MO(CO(HMON+"child"),TO); 
                         MO(CO(HMON+"woman"),TO);  
                         MO(CO(HMON+"woman"),TO);  
                         MO(CO(HMON+"woman"),TO); 
                         MO(CO(HMON+"woman"),TO); 
                 

  if(arg) return;
   
       ::reset(arg);

        long_desc =   "This appears to be the center of the bustling "+
                      "halfling village.  A long bridge extends over the southward "+
                      "flowing river to the west.  A number of larger hobbit holes "+
                      "populate the enbankment to the east, and the cobblestone path "+
                      "continues to the south.  A flowered wreath is sitting on a "+
                      "large stone, in the middle of town square.  Several hobbit "+
                      "holes lie eastward.\n"; 
      short_desc = "In the halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p7","south", HPATH+"p5","north",
                HPATH+"h3","northeast", HPATH+"h4", "east"
                HPATH+"h5","southeast", HPATH+"bridge","west" });

  items = ({ ({"holes","Hobbit holes","hobbit holes"}),
             "They lie in all directions to the east",
             "street","Filled with small stuff, ya know, for halflings",
             "town","A quaint halfling village",
             "river","There appears to be a bridge spanning it",
             "wreath","Laid here in honor of our lost townsfolk",
             "stone","It appear to be a monument, there are names carved on it",
             "names","The names of the townsfolk killed by local kobolds"
          });



   replace_program("room/room");
}





