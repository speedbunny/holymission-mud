inherit "room/room";

reset(arg) {
    ::reset(arg);
    if(arg) {
	return;
    }
    short_desc="Deep Jungle";
    long_desc="The path ahead continues to the north and west, but\n"+
    "as you turn around, you notice that the path back is\n"+
    "gone!!!  You are trapped, and must find another way\n"+
    "out. Strangely enough, you hear some weird clinking\n"+
    "noises coming from the northwest.\n";
    set_light(1);
    items=({"path","The path starts to become more well travelled here",
      "jungle","It has swallowed the path back!"});
    dest_dir=({"players/helmut/rooms/jungle3","north",
      "players/helmut/rooms/path1","west",
      "players/helmut/rooms/skelpath","east"});
    replace_program("room/room");
}
