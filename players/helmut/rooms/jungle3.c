inherit "room/room";

reset(arg) {
    ::reset(arg);
    if(arg) {
	return;
    }
    short_desc="Jungle";
    long_desc="The jungle is growing all around you, and you start to feel\n"+
    "claustrophobic.  There are tracks of all sorts of animals\n"+
    "around, some of the probably carnivorous.  Fortunately, most\n"+
    "of the tracks are small, and your unease abates a bit. Roars\n"+
    "from the big boys, however, quicky remind you that you might\n"+
    "be lunch. To the west, there is a small path branching off of\n"+
    "the main path.\n";
    set_light(1);
    dest_dir=({"players/helmut/rooms/jungle5","north",
      "players/helmut/rooms/jungle4","west",
      "players/helmut/rooms/oneway","south"});
    replace_program("room/room");
}
