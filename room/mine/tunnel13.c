/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "End of tunnel.\n";
  dest_dir = ({ "room/mine/tunnel12", "south" });

replace_program("room/room");
}
