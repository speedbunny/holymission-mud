/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "In the tunnel into the mines.\n";
  dest_dir = ({ "room/mine/tunnel9", "east",
	 "room/mine/tunnel11", "west" });

replace_program("room/room");
}
