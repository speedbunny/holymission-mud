inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A junction";
long_desc=
"You are on a road that lies just outside of Red Rock Juntion.  In the\n"+
"center of this area is a large red rock which the road goes around,\n"+
"continuing to the east.  There is a sign next to the rock.\n";
      "Here the road leads around a big red rock. A road continues to the "+
       "east, another to the north and the one that leads back to town. "+
       "There is a sign next to the rock.\n";
    dest_dir=({
      "players/kelly/rooms/vill/road4","west",
      "players/kelly/rooms/vill/road7","east",
    });
    items=({
      "rock","Maybe that's how the village got it's name",
      "sign","A wooden sign. Perhaps you should read it",
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
