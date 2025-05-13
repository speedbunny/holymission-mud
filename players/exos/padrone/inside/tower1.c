inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Bottom of the watchtower";
  long_desc =  "You are at the bottom of the watchtower,\n" 
	 "which is the smaller of the two towers in Padrone's castle.\n" 
	 "This is a circular room with walls and floor made of stone.\n" 
	 "A narrow wooden staircase leads up into the gloom.\n";
  dest_dir = ({ "players/padrone/inside/gate_room", "east",
	 "players/padrone/inside/tower2", "up" });

replace_program("room/room");
}
