/* 12.15.93 Airborne: changed to room/room */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "On a rock-ledge";
  long_desc = 
	"You are on a rock ledge. Nothing has been here in a while.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/mountain","west" });
::reset();
replace_program("room/room");
}
