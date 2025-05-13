/* 12.14.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "The path to Misty Mountain";
  long_desc =
     "You are on the path to Misty Mountain. You can see the mighty mountain\n"
     "far away.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/mountain_foot","north",
         "players/topaz/angmar/fairyland/path1","east" });

replace_program("room/room");
}
