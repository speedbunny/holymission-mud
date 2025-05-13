inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a plain";
  long_desc="You are on a small plain. To the southeast the plain leads into a valley.\n"+
   "To the west the plain continues. To the southwest you can see a big forest\n";

  dest_dir=({
    "players/kelly/rooms/mountains/plain2","south",
    "players/kelly/rooms/mountains/valley4n","southeast",
    "players/kelly/rooms/mountains/plain4","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "valley","A valley between mountains",
   });
 
}
 
