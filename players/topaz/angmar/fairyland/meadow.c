/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "The meadow";
  long_desc =
	"You are standing in the middle of a meadow. Many different\n"+
	"kinds of flowers are growing here.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/road3","east",
         "players/topaz/angmar/fairyland/ditch","west" });

replace_program("room/room");
}
