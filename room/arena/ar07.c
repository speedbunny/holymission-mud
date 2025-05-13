inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Arena";
     long_desc= "You are in the middle of the Roman Arena.\n"+
		"In the sand you see dried blood stains and\n"+
		"decaying body parts. The stench of decay is\n"+
		"nearly unbearable here.\n";
     dest_dir=({ "room/arena/ar02","northwest",
		 "room/arena/ar03","west",
		 "room/arena/ar04","southwest",
		 "room/arena/ar06","north",
		 "room/arena/ar08","south",
		 "room/arena/ar10","northeast",
		 "room/arena/ar11","east",
		 "room/arena/ar12","southeast" });
  }
}
