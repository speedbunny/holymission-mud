/* 12.14.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "You are on a small road passing an inn";
  long_desc =
	"You are on a small road outside the inn Laughing Horse.\n"+
	"Laughter and clinking from glasses can be heard from east.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/inn","east",
           "players/topaz/angmar/fairyland/road1","south",
           "players/topaz/angmar/fairyland/road3","north" });

replace_program("room/room");
}
