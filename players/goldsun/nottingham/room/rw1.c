inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Town road");
 long_desc="A road going to the Nottingham. The town is to the east.\n"+
	   "The green grass growing on the sides of the road. The road\n"+
	   "continuest to the northwest and east.\n";

 smell="You smell a fresh grassy air.";

 dest_dir=({ "/players/goldsun/nottingham/room/rw2","northwest",
   	      "/players/goldsun/nottingham/room/o_w_g","east"});

 items=({  "grass","Green grass is waving in the wind",
	   "road","A stony road to the Nottingham",
           "green grass","Nice green grass is waving in the wind",
	   "town","It looks like Nottingham"

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

