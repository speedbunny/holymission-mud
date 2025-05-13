inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("cross");
  set_short("A silver cross");
  set_long("A silver cross, with chain attached. Perhaps you should wear it?\n");
  set_value(100);
  set_weight(1);
}

init() {
  ::init();
  add_action("wear", "wear");
}

wear(str) {
  if(str!="cross") return;
  write("As you put the cross on, something very strange happens ....\n");
  say(this_player()->query_name() + " suddenly disappears.\n");
  transfer(this_player(),"players/moonchild/gnome/maze4");
  "players/moonchild/gnome/prison"->extra_reset();
  destruct(this_object());
  return 1;
}
