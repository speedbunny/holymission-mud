/* 12.12.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "You are walking somewhere deep inside the Darkwood";
  long_desc = 
	"You are walking somewhere deep inside the Darkwood. Are you\n"+
	"lost? Will you ever see your mummy again?\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/darkwood5","west",
	   "players/topaz/angmar/fairyland/darkwood2","east",
	   "players/topaz/angmar/fairyland/dw_path4","south" });

replace_program("room/room");
}
