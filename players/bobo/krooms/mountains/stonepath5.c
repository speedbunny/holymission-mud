inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a stony path";
  long_desc="You're walking on a stony path leading southwest to northeast.\n"+
   "The path leads around a huge rock.\n";
  dest_dir=({
	"players/bobo/krooms/mountains/stonepath7","northeast",
	"players/bobo/krooms/mountains/stonepath3","southwest",
   });
   items=({
    "rock","It has a smooth surface and doesn't look terrestrial",
   });
}
 
