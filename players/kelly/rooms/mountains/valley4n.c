inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a valley";
  long_desc="You're in a valley in the mountains.\n"+
   "To the east the valley get closer.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/valley3n","east",
    "players/kelly/rooms/mountains/valley4s","south",
    "players/kelly/rooms/mountains/plain1","northwest",
    "players/kelly/rooms/mountains/plain2","southwest",
   });
}
 
