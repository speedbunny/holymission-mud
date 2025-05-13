inherit "obj/thing";

reset(arg) {
  set_name("hut");
  set_read("This hut belongs to a hermit.\n");
  set_short("A hut");
  set_long("A hut. Maybe you can enter it?\n");
}

init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
  if(!id(str)) return 0;
  this_player()->move_player("into the hut#players/cashimor/rooms/inhut");
  return 1;
}
