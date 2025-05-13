inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a crossing on a stony path";
  long_desc="You're standing on a crossing of the stony path leading.\n"+
   "A dark path leads off to the north.\n"+
   "There's a hole in the rock, which you can enter to the south.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/darkpath","north",
    "players/kelly/rooms/mountains/stonepath5","southwest",
    "players/kelly/rooms/mountains/stonepath6","southeast",
    "players/kelly/rooms/mountains/ante_den","south",
   });
   items=({
    "rock","It has a smooth surface and doesn't look terrestrial",
    "hole","It is a natural hole, some trails leads into it",
   });
}
 
