/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "Tunnel fork.\n";
  dest_dir = ({ "room/mine/tunnel19", "south",
	 "room/mine/tunnel21", "west",
	 "room/mine/tunnel23", "east" });

replace_program("room/room");
}
