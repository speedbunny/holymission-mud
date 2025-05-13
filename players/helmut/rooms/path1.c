inherit "room/room";

reset(arg) {
    ::reset(arg);
    if(arg) {
	return;
    }
    short_desc="A well-hewn path";
    long_desc=
    "Clinking is coming from the north, but the jungle is much too dense\n"+
    "to pass. In fact, the only way open to you is the way back, and to\n"+
    "the west. This path has been well hewn by many former travellers,\n"+
    "and you wonder where it leads? In any event, you are still surrounded\n"+
    "by a plethora of animal sounds.\n";
    set_light(2);
    smell="You aren't sure, but you think you smell beer?";
    items=({"path","It is a well trodden path, leading back the way\n"+
      "you came, and further into the jungle",
      "jungle","It is opressive and hot, and the trees seem to\n"+
      "sway in the heat waves"});
    dest_dir=({"players/helmut/rooms/path2","west",
      "players/helmut/rooms/oneway","east"});
    replace_program("room/room");
}
