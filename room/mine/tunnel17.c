/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =  "The tunnel into the mines.\n";
  dest_dir = ({ "room/mine/tunnel19", "north",
	 "room/mine/tunnel16", "south",
	 "room/mine/tunnel18", "west" });

replace_program("room/room");
}
