inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The centaur's den";
  long_desc="You're in the centaur's den.\n"+
   "You should not attack him, if you're not really tough.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/ante_den","north",
  });
   move_object(clone_object("players/kelly/monster/centaur"),this_object());
}
 
