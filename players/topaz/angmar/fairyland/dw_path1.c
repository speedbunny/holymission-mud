/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "On a path in Darkwood";
  long_desc = 
	"You are on a twisty path in the legendary Darkwood. Many adventurers\n"+
	"have been killed here.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/dw_path2","north",
         "players/topaz/angmar/fairyland/darkw_entrance","west" });

replace_program("room/room");
}
