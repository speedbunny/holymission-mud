inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a plain";
  long_desc="You are on a small plain. To the east the plain leads into a valley.\n"+
   "To the west the plain continues and far in the west you can see a big forest\n";

  dest_dir=({
    "players/kelly/rooms/mountains/plain1","north",
    "players/kelly/rooms/mountains/valley4n","northeast",
    "players/kelly/rooms/mountains/valley4s","southeast",
    "players/kelly/rooms/mountains/plain5","west",
    "players/kelly/rooms/mountains/plain3","south",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "valley","A valley between mountains",
   });
 
}
 
