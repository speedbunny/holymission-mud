inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,1,"dragon","/players/goldsun/lank/monster/lazy_dragon",0});
 set_light(0);
 short_desc=("A dark mine");
 long_desc=("You are in the dark mine under Lankbourg mountains.\n"+
	    "The mine continues to the east and west.\n");
 smell="You smell damp air.";
 no_castle_flag=1;
 dest_dir=({"/players/goldsun/lank/room/mine1","west",
	    "/players/goldsun/lank/room/mine3","east"});

 items=({"mine","The mine is damp and dark",
	 "dark mine","The mine is damp and dark",
	 "damp mine","The mine is damp and dark"});
 }
 ::reset();
 replace_program("room/room");
}
