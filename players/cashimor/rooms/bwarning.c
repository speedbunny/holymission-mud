inherit "room/room";

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "Baald warning";
    long_desc = "You're in a hostile part of the mountains. When you look to\n"
              + "the north, you think you saw something move there. Maybe\n"
              + "there are very dangerous individuals living there...\n";
    items = ( { "mountains", "They're covered with snow.\n" } );
    dest_dir = ( { "players/cashimor/rooms/mountains", "west",
                   "players/cashimor/rooms/baalds", "north"
               } );
  }
}

