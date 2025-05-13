/* 12.12.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "You are walking somewhere deep inside the Darkwood";
  long_desc = 
 	"You are walking somewhere deep inside the Darkwood. You feel cold\n"+
	"and frightened. Maybe you should turn back?\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/darkwood3","west",
	 "players/topaz/angmar/fairyland/dw_path3","south" });

replace_program("room/room");
}
