/* 12.11.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "In a cornfield";
  long_desc =
	"You are in a large cornfield. Cornplants grow everywhere.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/corn2","north",
         "players/topaz/angmar/fairyland/ditch","east" });

replace_program("room/room");
}
