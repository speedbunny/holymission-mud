inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("A path to the Nottingham");
 long_desc="You are on your way to the Nottingham. Far to the north you\n"+
	   "can see a big forest. The grassy road continues to the north\n"+
	   "and south.\n";  

 smell="You smell a fresh grassy air.";

 dest_dir=({ "/players/goldsun/nottingham/room/rw4","north",
   	      "/players/goldsun/nottingham/room/rw2","south"});

 items=({  "forest","A big forest far to the north",
           "road","The grassy road. It looks very nice",
	   "grass","The grass is waving in the wind",
	   "path","A path to the south and north",
           "green grass","Nice green grass is waving in the wind"

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

