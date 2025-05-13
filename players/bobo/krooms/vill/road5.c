inherit "/room/room";

void reset (int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A junction of roads.";
   long_desc=
	"Here the road leads around a big red rock.  A road continues to "+
	"the east, another to the north and the one that leads back to town."+
	"  There is a sign next to the rock.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/road7","east",
	"/players/bobo/krooms/vill/road4","west",
   });
   items=({
	"rock","Maybe that's how the village got its name",
	"sign","A wooden sign,  Perhaps you should read it",
   });
}

void init() {
   ::init();
   add_action("_read","read");
}

status _read(string str) {
   if (str=="sign" || str=="the sign") {
    printf("East road   ->  Calanport\n");
    printf("West road   ->  Red Rock Junction\n");
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}
