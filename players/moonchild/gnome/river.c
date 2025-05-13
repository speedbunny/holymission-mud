inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Swimming in a river";
  long_desc="You are swimming in an underground river. You could dive\n"
	+ "down or you could get back to dry land to the northwest.\n";
  dest_dir=({ "players/moonchild/gnome/eroad2", "northwest" });
  property=({ "no_teleport" });
}

init() {
  ::init();
  add_action("dive", "dive");
}

dive() {
  this_player()->move_player(", diving down#players/moonchild/gnome/inriver");
  return 1;
}
