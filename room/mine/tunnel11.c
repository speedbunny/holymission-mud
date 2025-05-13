/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "In the tunnel into the mines.\n";
  dest_dir = ({ "room/mine/tunnel10", "east",
	 "room/mine/tunnel12", "north" });

replace_program("room/room");
}
