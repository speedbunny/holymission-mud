/* 12.11.93 Airborne: Change to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "Crossing";
  long_desc = 
	"The road crossing. An old wooden sign-post says: To the east\n"+
	"goes the road to Great Lake. The road to the north leads to\n"+
	"Misty Mountain. The village is to the south.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/path1","north",
           "players/topaz/angmar/fairyland/by_lake","east",
           "players/topaz/angmar/fairyland/road3","south" });

replace_program("room/room");
}
