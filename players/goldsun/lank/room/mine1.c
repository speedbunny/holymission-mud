inherit "/room/room";

reset(arg){
 ::reset(arg);
 if (arg) return;
 set_light(0);
 short_desc=("A dark mine");
 long_desc=("You are in the dark mine under Lankbourg mountains.\n"+
   	    "To the west you can see the light comming through\n"+
	    "a small hole. The mine continues to the east.\n");
 smell="You smell damp air.";
 no_castle_flag=1;
 dest_dir=({"/players/goldsun/lank/room/peak1","west",
	    "/players/goldsun/lank/room/mine2","east"});

 items=({"mine","The mine is damp and dark",
	 "dark mine","The mine is damp and dark",
	 "hole","A small hole to the west",
	 "light","The light is comming through hole",
	 "damp mine","The mine is damp and dark"});
 replace_program("room/room");
}
