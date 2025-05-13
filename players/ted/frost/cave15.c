inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave is almost a hallway now. The floor and walls are lined\n"+
"with cut slabs of white marble.\n";
    dest_dir = ({
"players/ted/frost/cave16", "northwest",
"players/ted/frost/cave14", "south"
    });
  }
}
