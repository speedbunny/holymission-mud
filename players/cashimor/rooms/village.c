inherit "room/room";

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "Viking village";
    long_desc = "You are in a viking village.\n";
    items = ( { "village", "It's made of wooden buildings.\n" } );
     dest_dir = ( { "players/cashimor/rooms/mountains", "north" } );
  }
  if (!present("fural",this_object())) {
    move_object(clone_object("players/cashimor/monsters/fural"),this_object());
  }
  if (!present("gandalf",this_object())) {
    move_object(clone_object("players/cashimor/monsters/gandalf"),this_object());
  }
}
