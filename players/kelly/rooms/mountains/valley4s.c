inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a valley";
  long_desc="You're in a valley in the mountains.\n"+
   "To the east the valley get closer.\n"+
   "To the west lies a small plain area.\n";

  dest_dir=({
    "players/kelly/rooms/mountains/valley3s","east",
    "players/kelly/rooms/mountains/valley4n","north",
    "players/kelly/rooms/mountains/plain2","northwest",
    "players/kelly/rooms/mountains/plain3","southwest",
   });
  
   items=({
     "area","It's a small and grassy plain, some clouds are hanging in the sky",
   });
 
}
 
