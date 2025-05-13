inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Tower stairs");
 long_desc="You are at the staircase of a high tower in the palace.\n"+
	   "The stairs wind up and down from here and there is a passage\n"+
	   "to the south. Torches along the wall give off a smoky odour.\n";
 
 smell="You smell torch smoke.";
 property=({"has_fire"});
 dest_dir=({"/players/goldsun/nottingham/room/castle/tower3","up", 
	    "/players/goldsun/nottingham/room/castle/hall2","south",
   	    "/players/goldsun/nottingham/room/castle/tower1","down" });

 items=({ "stairs" ,"The stairs lead up and down",
	  "torches","They are attached to the wall"
	  
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

