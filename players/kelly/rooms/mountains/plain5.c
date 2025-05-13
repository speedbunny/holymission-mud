inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a plain";
  long_desc="You are on a small plain. It continues the the east and north.\n"+
   "To the south and west you can see a big forest\n";

  dest_dir=({
    "players/kelly/rooms/mountains/plain4","north",
    "players/kelly/rooms/mountains/plain2","east",
    "players/kelly/rooms/entwood/edge1","south",
    "players/kelly/rooms/entwood/edge3","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
   });
 
}
 
