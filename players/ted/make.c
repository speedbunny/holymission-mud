inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Familar making room";
  long_desc = "Same\n";
}

init() {
  ::init();
  add_action("make"); add_verb("make");
}

make() {
  object fam;
  fam = clone_object("players/ted/familiar");
  fam->set_owner(this_player());
  fam->set_name("pet");
  move_object(fam, this_object());
}
