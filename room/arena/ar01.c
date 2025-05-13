inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Arena West Entrance";
     long_desc= "You stand at the western entrance of an ancient\n"+
		"Roman arena and you can hear the spectators shouting and\n"+
		"whistling from above. A feeling of dread overwhelms you.\n"+
		"To the west you can see a heavy portcullis.\n";
     items=({ "portcullis","@@long_port" });
     dest_dir=({ "room/arena/ar02","northeast",
		 "room/arena/ar03","east",
		 "room/arena/ar04","southeast" });
  }
}

init() { 
  ::init();
  add_action("move","west");
}

long_port() {
  if ("room/arena/e01"->query_locked()) return "The portcullis is down";
  else return "The portcullis is up";
}

move(str) {
  if (!str) str=query_verb();
  if (str=="west") {
     if ("room/arena/e01"->query_locked()) {
        write("You run into the iron portcullis. That hurts!\n");
        return 1;
     }
     this_player()->move_player("west#room/arena/e01");
     return 1;
  }
  return ::move(str);
}
