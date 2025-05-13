inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a stony path";
  long_desc="You're walking on a stony path leading southwest to northwest.\n"+
   "The path leads around a huge rock.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/stonepath6","northwest",
    "players/kelly/rooms/mountains/stonepath2","southwest",
   });
   items=({
    "rock","It has a smooth surface and doesn't look terrestrial",
   });
}
 
