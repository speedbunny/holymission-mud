inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a valley";
  long_desc="You're in a valley in the mountains.\n"+
   "To the east the valley get closer.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/valley2","northeast",
    "players/kelly/rooms/mountains/valley3n","north",
    "players/kelly/rooms/mountains/valley4s","west",
   });
}
 
