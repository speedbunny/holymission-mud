inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Cobblestone Path 3";
    long_desc =
"A cobblestone path leading north-south.\n";
    dest_dir = ({
"players/ted/path/four_way", "north",
"players/ted/path/path2", "south"
    });
  }
}
