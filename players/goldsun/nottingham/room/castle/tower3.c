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
 dest_dir=({"/players/goldsun/nottingham/room/castle/witchroom","up", 
	    "/players/goldsun/nottingham/room/castle/hall4","south",
   	    "/players/goldsun/nottingham/room/castle/tower2","down" });

 items=({ "stairs" ,"The stairs lead up and down",
	  "torches","They are attached to the wall",
	  "wall","It looks very strange. Maybe you can push it"
        });

 }
 ::reset(arg);
}

init(){
 ::init();
 add_action("push","push");
}

int push(string str){
 notify_fail("Push what ?\n");
 if (str=="east wall"){       /*  !!! this have to be "east wall" */
   this_player()->move_player("suddenly#/players/goldsun/nottingham/room/castle/secret");
   return 1;
 }
 return 0;
}

