inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a stony path";
  long_desc="You're walking on a stony path leading southeast to northeast.\n"+
   "The path leads around a huge rock.\n"+
  "There is a path leading down into a small valley to the west.\n";
  dest_dir=({
	"players/bobo/krooms/mountains/valley1","west",
	"players/bobo/krooms/mountains/stonepath5","northeast",
	"players/bobo/krooms/mountains/stonepath1","southeast",
    "players/kelly/rooms/mountains/valley1","west",
    "players/kelly/rooms/mountains/stonepath1","southeast",
   });
   items=({
     "path","This path hasn't been gone a long time, who knows why",
     "valley","It is small and lead from here down to a plain area",
    "rock","It has a smooth surface and does not look terrestrial",
   });
}
 
