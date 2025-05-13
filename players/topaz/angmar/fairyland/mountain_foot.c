/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "The foot of Misty Mountain";
  long_desc =
	"Misty Mountain towers high before you. You feel very small.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/path2","south",
         "players/topaz/angmar/fairyland/mountain","up" });

replace_program("room/room");
}
