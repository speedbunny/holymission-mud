inherit "obj/thing";

string location;

reset(arg) {
  if(!arg) {
    set_name("exit");
    set_short("An emergency exit");
    set_long("Use this exit (`out') to leave the current room.\n");
    set_can_get(0);
    location="X#room/church";
  }
}

set_location(str) {
  location=str;
}

init() {
  ::init();
  add_action("out_it","out");
}

out_it() {
  this_player()->move_player(location);
  return 1;
}
