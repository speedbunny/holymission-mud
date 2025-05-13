inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Cobblestone Path 7";
    long_desc =
"This is a cobblestone path leading north-south.\n";
    dest_dir = ({
"players/ted/path/red", "north",
"players/ted/path/path6", "south"
    });
  }
}
