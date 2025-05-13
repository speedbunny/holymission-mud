/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "On a path in Darkwood";
  long_desc =
	"You are on a twisty path in the legendary Darkwood. You can see\n"+
	"gleaming eyes stare at you from the shadows.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/darkwood2","north",
	   "players/topaz/angmar/fairyland/dw_path2","south",
	   "players/topaz/angmar/fairyland/dw_path4","west" });

replace_program("room/room");
}
