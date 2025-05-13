inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave winds and twists northeast and south.\n";
    dest_dir = ({
"players/ted/frost/cave8", "northeast",
"players/ted/frost/cave6", "south"
    });
  }
}
