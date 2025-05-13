inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a plain";
  long_desc="You are on a small plain.\n"+
   "To the west you can see a big forest\n";

  dest_dir=({
    "players/kelly/rooms/mountains/plain5","south",
    "players/kelly/rooms/mountains/plain1","east",
    "players/kelly/rooms/entwood/edge4","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
   });
 
}
 
