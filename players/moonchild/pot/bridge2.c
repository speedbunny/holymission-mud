short() { return "However, you see a magical bridge in place of the old fallen one"; }

long() { write("You see a magical bridge leading northwest.\n"); }

id(str) { return str=="bridge"; }

init() { add_action("southeast", "northwest"); }

southeast() {
  say("As " + this_player()->query_name() + " crosses the bridge it disappears.\n");
  write("The bridge disappears as soon as you have crossed it.\n");
  this_player()->move_player("northwest#room/south/sshore26");
  destruct(this_object());
  return 1;
}
