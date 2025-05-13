/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "On a path in Darkwood";
  long_desc =
	"You are walking on a twisty path in the legendary Darkwood. You are\n"+
	"lucky to have survived so far.\n"; 
  dest_dir = ({ "players/topaz/angmar/fairyland/darkwood3","north",
	  "players/topaz/angmar/fairyland/dw_path5","west",
	  "players/topaz/angmar/fairyland/dw_path3","east",
	  "players/topaz/angmar/fairyland/darkwood4","south" });

replace_program("room/room");
}
