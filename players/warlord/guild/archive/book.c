id(str) { return str=="book" || str=="lvlbook"; }
query_name() { return "scroll"; }
short() { return "A clerics scroll"; }
long() { return write("The scroll is attached to the wall. Just read it.\n"); }
get() { return 0; }

init() {
add_action("read","read");
}

read(arg) {
    if ((arg=="scroll") || (arg=="level scroll")) {
    this_player()->more("/players/warlord/guild/levels.txt");
    return 1;
  }
}
