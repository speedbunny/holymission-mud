/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "The tunnel slopes steeply down a hole here.\n";
  dest_dir = ({ "room/mine/tunnel25", "south",
	 "room/mine/tunnel27", "north",
	 "room/mine/tunnel28", "east" });

replace_program("room/room");
}
