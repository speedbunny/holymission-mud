/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Dead end";
  long_desc = "In the tunnel into the mines.\n";
  dest_dir = ({ "room/mine/tunnel17", "east" });

replace_program("room/room");
}
