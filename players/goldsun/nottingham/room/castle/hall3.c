inherit "/room/room";
#include "/obj/door.h"

object obj_1, obj_2;

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Hallway");
 long_desc="You are in the hall on the first floor. There are high\n"+
	   "candlesticks by the walls and red carpet on the floor.\n"+
	   "On the wall you can see shields and swords.\n";
 
 smell="You smell torch smoke.";

 MAKE_DOORS("/players/goldsun/nottingham/room/castle/hall3","east",
          "/players/goldsun/nottingham/room/castle/abbot","west","steel",
          "no_code_902",
          "An oak door.\n", 1,0,0);
 

 dest_dir=({"/players/goldsun/nottingham/room/castle/hall2","north"});

 items=({ "candlesticks","They are made of iron",
   	  "candlestick","It is made of iron",
	  "swords","They are fixed to the wall",
          "sword","It is fixed to the wall",
	  "shields","Iron shields with Nottingham sign. They are fixed to the wall",
	  "shield","A shield with Nottingham sign is fixed to the wall",
	  "carpet","A red carpet continues to the north"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

