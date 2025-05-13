inherit "obj/thing";

reset(arg) {
  if(!arg) {
    set_id("bridge");
    set_short("A narrow bridge");
    set_long("This is a narrow bridge leading to the east!\n");
    set_can_get(0);
  }
}

init() {
  add_action("west","west");
}

west() {
  move_player("west#players/cashimor/rooms/onbridge");
  return 1;
}

