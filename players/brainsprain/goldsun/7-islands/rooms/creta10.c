inherit "/players/brainsprain/goldsun/7-islands/rooms/creta9";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
    clone_list=({ 1, 2, "pheasant", "obj/monster", ({
                                                     "set_name","pheasant",
                                                     "set_alias","monster",
                                                     "set_race","pheasant",
                                                     "set_level",1,
                                                     "set_long",
"This pheasant wobbles about through the grass.  Its long tail feathers "+
"sway and bob.  Its head has iridescent green feathers on it.  This bird "+
"appears to be involved in some intricate and complex mating dance.",
                                                     "set_short","Pheasant",
                                                     "set_ac",0,
                                                     "set_wc",5,
                           }),
                          });
 ::reset(arg);
 dest_dir= ({
	     ir+"/creta9", "north",
             ir+"/creta12","east",
             ir+"/creta13","southeast",
             ir"/creta7", "west"
	   });

}

