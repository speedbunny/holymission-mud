inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Test room";
  long_desc =
"A test room.\n";
}

init() {
  ::init();
  add_action("shadow"); add_verb("shadow");
  add_action("shadow2"); add_verb("shadow2");
}

shadow() {
  object junk;
  this_player()->new_shadow();
  if(junk) {
    write("Old shadow found.\n");
    destruct(junk);
  }
  junk = clone_object("players/ted/teds_shadow");
  junk->set_owner(this_player());
  junk->start();
  write("Ok.\n");
  return 1;
}
shadow2() {
  object junk;
  junk = clone_object("players/ted/test_shadow");
  junk->set_owner(this_player());
  junk->start();
  write("Ok Doky\n");
  return 1;
}
