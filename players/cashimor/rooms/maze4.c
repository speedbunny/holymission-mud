inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(0);
    short_desc="A 3D maze";
    long_desc="You seem to have lost your sense of direction completely.\n"
            + "There are corridors everywhere!\n";
    items=({"corridors","They seem to be crawling around like ants"});
    dest_dir=({"players/cashimor/rooms/maze5","north",
               "players/cashimor/rooms/maze4","west",
	       "players/cashimor/rooms/maze1","south",
               "players/cashimor/rooms/maze1","east",
               "players/cashimor/rooms/maze3","up",
               "players/cashimor/rooms/maze2","down"});
  }
}

