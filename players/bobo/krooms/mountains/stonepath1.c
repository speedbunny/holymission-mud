inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a stony path";
  long_desc="You're walking on a stony path leading southeast to northwest.\n"+
   "The path leads around a huge rock.\n";
  dest_dir=({
	"players/bobo/krooms/mountains/stonepath3","northwest",
	"players/bobo/krooms/castle/castle_yard","southeast",
   });
   items=({
    "rock","It has a smooth surface and doesn't look terrestrial",
   });
}
 
