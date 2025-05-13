/* 12.11.93 Airborne: Fixed to use room/room and replace_program */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Corridor";
  long_desc =
   "You are in a corridor deep under the ancient castle. The air\n"+
   "in here hasn't been breathed for hundreds of years.\n";
  dest_dir = ({ "players/topaz/angmar/downstairs","west",
           "players/topaz/angmar/empty","east",
           "players/topaz/angmar/dungeons","south" });
  smell = "You smell the stale musty air.";

replace_program("room/room");
}
