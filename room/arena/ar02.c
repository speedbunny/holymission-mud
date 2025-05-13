#define	TP	this_player()
#define TPN	TP->query_name()

inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Arena";
     long_desc= "You are in the northwestern part.\n"+
		"A gate is built into the wall, and through the gate\n"+
		"you can see a group of hungry felines watching you closely.\n"+
		"Maybe you should leave before the gate opens.\n";
     items=({ "gate", "@@long_gate" });
     dest_dir=({ "room/arena/ar03","south",
		 "room/arena/ar06","east",
		 "room/arena/ar07","southeast" });
  }
}

long_gate() {
  if ("room/arena/g01"->query_locked()) return "The gate is closed";
  else return "The gate is open";
}

init() {
  ::init();
  add_action("enter_gate","enter");
}

enter_gate(str) {
  if (str=="gate") {
     if ("room/arena/g01"->query_locked()) {
	write("You hurt yourself as you try to enter the closed gate.\n");
	say(TPN+" bumps into the closed gate.\n");
        return 1;
     }
     TP->move_player("into the felines cage#room/arena/g01");
     return 1;
  }
}


