inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The harpy's den";
  long_desc="You're in the harpy's den.\n"+
   "You should not attack her, if you're not really tough.\n";
  dest_dir=({
	"players/bobo/krooms/mountains/ante_den","north",
  });
   move_object(clone_object("players/bobo/kmonster/harpy"),this_object());
}
 
