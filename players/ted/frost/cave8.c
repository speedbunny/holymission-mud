inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave winds and twists northwest and southwest.\n";
    dest_dir = ({
"players/ted/frost/cave9", "northwest",
"players/ted/frost/cave7", "southwest"
    });
  }
}
