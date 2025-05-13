inherit "/room/room";

reset(arg){
 ::reset(arg);
 if (arg) return;
 set_light(0);
 short_desc=("A dark mine");
 long_desc=("You are in the dark mine under Lankbourg mountains.\n"+
   	    "To the east you can see the light comming through\n"+
	    "a small hole. The mine continues to the west.\n");
 smell="You smell damp air.";
 no_castle_flag=1;
 dest_dir=({"/players/goldsun/lank/room/peak2","east",
	    "/players/goldsun/lank/room/mine2","west"});

 items=({"mine","The mine is damp and dark",
	 "dark mine","The mine is damp and dark",
	 "hole","A small hole to the east",
	 "light","The light is comming through hole",
	 "damp mine","The mine is damp and dark"});
 replace_program("room/room");
}
