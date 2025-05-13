inherit "room/room";

reset(arg) {
    ::reset(arg);
    if(arg) {
	return;
    }
    short_desc="Jungle";
    long_desc=
    "Well, you've bravely decided to follow the path!!! The sounds of\n"+
    "the jungle immerse you with their intensity.  Insects buzz along\n"+
    "importantly about their business, small reptiles chatter to each\n"+
    "other, and predators thunder their triumph while the prey screams\n"+
    "in terror and pain.  The path continues to the north, slightly\n"+
    "overgrown so that your knees and ankles become damp with dew as you\n"+
    "walk deeper into the jungle.\n";
    set_light(1);
    items=({"jungle","It is huge and looks impenetrable, except\n"+
      "for the path."});
    dest_dir=({
      "players/helmut/rooms/oneway","north",
      "players/helmut/rooms/jungle1","south"});
    replace_program("room/room");
}
