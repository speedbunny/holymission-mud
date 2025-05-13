#define	TP	this_player()
#define TPN	TP->query_name()

inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Arena";
     long_desc= "You are in the western part of an ancient Roman Arena.\n"+
		"You can see hundreds of screaming spectators above you,\n"+
		"waiting for the contestants to die.\n";
     dest_dir=({ "room/arena/ar03","north",
		 "room/arena/ar07","northeast",
		 "room/arena/ar08","east" });
  }
}
