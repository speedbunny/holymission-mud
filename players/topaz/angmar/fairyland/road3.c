/* 12.14.93 Airborne: changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "A small road";
  long_desc = 
	"Your are standing on a small road. It continues to the north.\n"+
	"There is a meadow to the west.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/road2","south",
           "players/topaz/angmar/fairyland/crossing","north",
           "players/topaz/angmar/fairyland/meadow","west" });

replace_program("room/room");
}
