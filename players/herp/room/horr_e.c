id(str) { return str=="shop" || str=="house" || str=="door"; }
short() { return "There's a door leading into a strange wooden house"; }
long() {
  write("It looks open ...\n");
}
init() { add_action("enter","enter"); }
enter(str) {
  if (id(str)) {
     this_player()->move_player("into the house#players/herp/room/horror");
     return 1;
  }
}

reset(arg) {
  if (!arg) move_object(this_object(),"room/plane4");
}
