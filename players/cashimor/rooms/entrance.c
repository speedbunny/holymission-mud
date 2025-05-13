inherit "room/room";

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "Cave entrance";
    long_desc = "You are standing at the entrance of a green looking cave.\n";
    items = ( { "cave", "There's a strange green light inside.." } );
    dest_dir = ( { "players/cashimor/rooms/blobsite", "north" } );
  }
}
