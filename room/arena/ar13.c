inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Arena East Entrance";
     long_desc= "You stand at the eastern entrance of an ancient\n"+
		"Roman arena and can hear the spectators shouting and\n"+
		"whistling from above. The stench of decaying corpses\n"+
		"wafts over to you from the arena.\n"+
		"To the east you can see a heavy portcullis.\n";
     items=({ "portcullis","@@long_port" });
     dest_dir=({ "room/arena/ar10","northwest",
		 "room/arena/ar11","west",
		 "room/arena/ar12","southwest" });
  }
}

init() { 
  ::init();
  add_action("move","east");
}

long_port() {
  if ("room/arena/e02"->query_locked()) return "The portcullis is down";
  else return "The portcullis is up";
}

move(str) {
  if (!str) str=query_verb();
  if (str=="west") {
     if ("room/arena/e02"->query_locked()) {
        write("You run into the iron portcullis. That hurts!\n");
        return 1;
     }
     this_player()->move_player("west#room/arena/e02");
     return 1;
  }
  return ::move(str);
}
