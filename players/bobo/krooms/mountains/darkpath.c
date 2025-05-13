inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a dark path";
  long_desc="You're walking on a dark path, you can feel the evil coming nearer.\n"+
   "There's a small ravine leading up into a valley.\n"+
   "A sign stands beside the way.\n";
  dest_dir=({
	"players/bobo/krooms/mountains/stonepath7","south",
	"players/bobo/krooms/mountains/fernisden","up",
   });
   items=({
    "sign","It's written in the common language, thus you can read it",
   });
}
 
init() {
::init();
  add_action("read","read");
}

read(str) {
  if (str!="sign") return;
  write("The sign reads : WARNING !\n"+
        "Don't go any further if your level isn't high\n"+
        "enough. Many have tried it, but they never came back !\n");
  return 1;
}
