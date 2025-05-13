/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "In a ditch";
  long_desc =
	"You are in a ditch. Get up, you are making yourself dirty!\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/corn1","west",
         "players/topaz/angmar/fairyland/meadow","east" });

replace_program("room/room");
}
