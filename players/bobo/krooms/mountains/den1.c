inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The unicorn's den";
  long_desc="You're in the unicorn's den.\n"+
   "You should not attack it, if you're not really tough.\n";
  dest_dir=({
	"players/bobo/krooms/mountains/ante_den","north",
  });
   move_object(clone_object("players/bobo/kmonster/unicorn"),this_object());
}
 
