/* 12.13.92 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "Edge of the woods";
  long_desc =
	"You are at the edge of the beech woods. You can hear the sounds of\n"+
	"birds singing.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/edge1","east",
           "players/topaz/angmar/fairyland/beech2","south" });

replace_program("room/room");
}
