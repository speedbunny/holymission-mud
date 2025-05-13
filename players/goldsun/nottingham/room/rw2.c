inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("A road to the Nottingham");
 long_desc="You are on the way to the Nottingham. The road is made of\n"+
	   "stone. To the southeast you notice a town. \n";

 smell="You smell a fresh grassy air.";

 dest_dir=({ "/players/goldsun/nottingham/room/rw3","north",
   	      "/players/goldsun/nottingham/room/rw1","southeast"});

 items=({  "grass","Green grass is waving in the wind",
	   "road","A stony road to the Nottingham",
           "green grass","Nice green grass is waving in the wind"

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

