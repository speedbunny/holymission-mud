inherit "room/room";

int open,crys;

reset(arg) {
  open=crys=0;
  if(arg) return;
  set_light(1);
  short_desc="Bank";
  long_desc="This is a branch of the First Gnome Bank. It doesn't look very busy here,\n"
	+ "the counter is empty and no-one seems in sight. Perhaps you could break\n"
	+ "into the safe? There is also a large door to the west.\n";
  dest_dir=({ "players/moonchild/gnome/alley2", "east" });
  items=({ "counter", "It's empty, no-one seems here",
	"door", "This door has no handle and is closed. There is a slot in the centre of it",
        "slot", "It looks like you could put a small gem in it",
	"safe", "@@safe_func@@" });
  property=({ "no_teleport" });
}

init() {
  ::init();
  add_action("open", "open");
  add_action("open", "unlock");
  add_action("close", "close");
  add_action("_put", "put");
  add_action("_put", "insert");
}

open(str) {
  string what;
  object ob;
  if(!str) return;
  if(str=="door") {
    write("There's no handle on the door! You can't do that!\n");
    return 1;
  }
  if(open) {
    write("It is open, silly!\n");
    return 1;
  }
  if(str=="safe") {
    write("Open the safe with what?\n");
    return 1;
  }
  if(!sscanf(str, "safe with %s", what)) return;
  if(!(ob=present(what, this_player()))) {
    write("You don't have that!\n");
    return 1;
  }
  if(!ob->id("picklock") && !ob->id("needle")) {
    write("That won't help you to open the safe.\n");
    return 1;
  }
  if(ob->id("bent needle")) {
    write("The needle is too bent to act as a picklock.\n");
    return 1;
  }
  if(ob->id("needle")) {
    ob->set_short("A bent needle");
    ob->set_alias("bent needle");
  }
  if(crys) {
    write("You deftly pick the lock on the safe and it swings open. It's empty.\n");
    say(this_player()->query_name() + " opens the safe.\n");
    return 1;
  }
  write("You deftly pick the lock on the safe and it swings open. Something falls out.\n");
  say(this_player()->query_name() + " opens the safe. Something falls out.\n");
  move_object(ob=clone_object("players/moonchild/gnome/crystal"), this_object());
  crys=1;
  ob->set_type(4);
  return 1;
}

close(str) {
  if(str!="safe") return;
  if(open) {
    write("You close the safe.\n");
    open=0;
    return 1;
  }
  write("It is closed, silly!\n");
  return 1;
}

safe_func() {
  return open ? "It's open but empty" : "It's closed";
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
  this_player()->move_player("through the door#players/moonchild/cave/tunnel");
  destruct(item);
  return 1;
}
