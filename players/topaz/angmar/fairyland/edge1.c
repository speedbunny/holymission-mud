/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "Edge of the woods";
  long_desc =
	"You are at the edge of the beech woods. " 
	"The birds are singing cheerfully.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/road1","north",
           "players/topaz/angmar/fairyland/edge2","west",
           "players/topaz/angmar/fairyland/beech1","south" });

replace_program("room/room");
}
