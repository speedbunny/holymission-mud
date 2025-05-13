inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dark Cave";
    long_desc =
"The cave slopes up and winds back to the southwest.\n";
    dest_dir = ({
"players/ted/frost/cave12", "up",
"players/ted/frost/cave3", "southwest"
    });
  }
}
