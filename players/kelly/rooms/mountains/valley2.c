inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a narrow valley";
  long_desc="You're in a narrow valley that becomes wider to the west.\n"+
   "A path leads upwards to the east.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/valley3s","southwest",
    "players/kelly/rooms/mountains/valley3n","northwest",
    "players/kelly/rooms/mountains/valley1","east",
   });
   items=({
     "valley","It is small and extends from here down to west",
   });
}
 
