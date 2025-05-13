/* 12.11.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "Somewhere in Darkwood";
  long_desc =
	"You are walking somewhere in the Darkwood. You jump at the sound\n"+
	"of a twig snapping.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/dw_path2","west" });

replace_program("room/room");
}
