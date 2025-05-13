inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave drops off to the west and continues to the east.\n";
    dest_dir = ({
"players/ted/frost/cave13", "east",
"players/ted/frost/cave11", "down"
    });
  }
}
