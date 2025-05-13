inherit "room/room";
 
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A dimly lit cavern";
  long_desc="You are in a huge underground cavern, dimly lit by torches\n"
	+ "on the walls. To the east stand two giant stone doors.\n";
  dest_dir=({ "players/moonchild/cave/c13", "north",
	"players/moonchild/cave/link", "east",
	"players/moonchild/cave/c33", "south" });
  items=({ "torches", "Burning torches are mounted in the walls",
	"walls", "The walls are made of stone",
	"writing", "Perhaps you should read it" });
  enable_commands();
}

catch_tell(str) { "players/moonchild/cave/link"->catch_tell(str); }

id(str) { return ::id(str) || str=="door" || str=="doors"; }

long(str) {
  return (str=="door" || str=="doors") ?
    "players/moonchild/cave/link"->long(str) : ::long(str);
}

init() {
  ::init();
  add_action("read", "read");
  add_action("east", "east");
}

read(str) {
  if(str!="writing") return;
  write("The writing reads \"Speak, friend\".\n");
  return 1;
}

east() {
  if(!"players/moonchild/cave/link"->query_door_open())
	write("The doors are closed.\n");
  else {
    this_player()->move_player("east#players/moonchild/cave/link");
    "players/moonchild/cave/link"->toggle_door();
  }
  return 1;
}
