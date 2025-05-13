inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave slopes sharply down to the west and becomes narrower.\n"+
"To the southeast the cave widens out a bit.\n";
    dest_dir = ({
"players/ted/frost/cave5", "down",
"players/ted/frost/cave3", "southeast"
    });
  }
}
