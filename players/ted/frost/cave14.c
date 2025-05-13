inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The floor of the cave is paved and the walls are lined with\n"+
"cut marble. You think you hear the sound of running water.\n";
    dest_dir = ({
"players/ted/frost/cave15", "north",
"players/ted/frost/cave13", "south"
    });
  }
}
