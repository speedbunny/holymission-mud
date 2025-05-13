inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc="Door at end of tunnel";
  long_desc="The tunnel here ends abruptly at a large door which blocks all\n"
	+ "apparent progress to the east. You can still leave west, though.\n";
  dest_dir=({ "players/moonchild/cave/drag", "west" });
  items=({ "door", "This door has no handle and is closed. There is a slot in the centre of it",
	"slot", "It looks like you could put a small gem in it" });
}

init() {
  ::init();
  add_action("open", "open");
  add_action("_put", "put");
  add_action("_put", "insert");
}

open(str) {
  if(str!="door") return;
  write("There's no handle on the door! You can't do that!\n");
  return 1;
}

_put(str) {
  string what;
  object item;
  if(!sscanf(str, "%s in slot", what)) {
    notify_fail("Huh?\n");
    return;
  }
  if(!(item=present(what, this_player()))) {
    write("You haven't got a " + str + ".\n");
    return 1;
  }
  if(!item->query_door_payment()) {
    write("It doesn't fit!\n");
    return 1;
  }
  write("You put the " + str + " into the slot in the door.\n"
	+ "The door swings open and drags you through it!\n");
  say(this_player()->query_name() + " put something into a slot in the door.\n"
	+ "Suddenly, they are dragged straight through the door!\n");
  this_player()->move_player("through the door#players/moonchild/gnome/bank");
  destruct(item);
  return 1;
}
