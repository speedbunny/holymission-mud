#define	TP	this_player()
#define TPN	TP->query_name()

inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Arena";
     long_desc= "You are in the middle of the Arena.\n"+
		"You feel that it's time to die.\n"; 
     dest_dir=({ "room/arena/ar05","north",
		 "room/arena/ar02","west",
		 "room/arena/ar03","southwest",
		 "room/arena/ar07","south",
		 "room/arena/ar10","east",
		 "room/arena/ar11","southeast" });
  }
}
