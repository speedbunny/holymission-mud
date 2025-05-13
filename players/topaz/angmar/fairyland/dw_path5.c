/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "On a path in Darkwood";
  long_desc =
	"You are on a twisty path in the legendary Darkwood. The\n"+
	"forest ends to the west.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/behind_mountain","west",
	   "players/topaz/angmar/fairyland/dw_path4","east",
	   "players/topaz/angmar/fairyland/darkwood5","north" });

replace_program("room/room");
}
