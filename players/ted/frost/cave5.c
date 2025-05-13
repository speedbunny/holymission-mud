inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave is very narrow here. Passages leave west and up.\n";
    dest_dir = ({
"players/ted/frost/cave6", "west",
"players/ted/frost/cave4", "up"
    });
  }
}
