short() { return "However, you see a magical bridge in place of the old fallen one"; }

long() { write("You see a magical bridge leading southeast.\n"); }

id(str) { return str=="bridge"; }

init() { add_action("southeast", "southeast"); }

southeast() {
  say("As " + this_player()->query_name() + " crosses the bridge it disappears.\
n");
  write("The bridge disappears as soon as you have crossed it.\n");
  this_player()->move_player("southeast#room/south/sislnd1");
  destruct(this_object());
  return 1;
}
