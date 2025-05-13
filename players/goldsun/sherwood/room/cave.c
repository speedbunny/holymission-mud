inherit "/room/room";

reset(arg){
 ::reset(arg);
 set_light(0);
 short_desc=("A dark cave");
 long_desc=("You are in the dark cave.\n");
 smell="You smell damp air.";
 no_castle_flag=1;
 dest_dir=({"/players/goldsun/sherwood/room/Robin","out"});
 items=({"cave","The cave is damp and dark",
	 "dark cave","The cave is damp and dark",
	 "damp cave","The cave is damp and dark"});
 replace_program("room/room");
}
