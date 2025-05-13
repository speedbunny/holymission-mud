inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"The forest becomes impassible to the west, but lightens\n"+
"to the east. A small hill rises to the north and a strange\n"+
"squaking sound comes from the south.\n";
    dest_dir = ({
"players/ted/forest/forest11", "north",
"players/ted/forest/forest31", "south",
"players/ted/forest/forest22", "east"
    });
  }
}
