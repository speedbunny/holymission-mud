/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "Tunnel into the mines.\n";
  dest_dir = ({ "room/mine/tunnel26", "west",
	 "room/mine/tunnel29", "east" });

replace_program("room/room");
}
