inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Hot Path";
    long_desc =
"This path becomes hotter the farther east you go.\n";
    dest_dir = ({
"players/ted/path/wierd_path", "west",
"players/ted/hot/fire_path", "east"
    });
  }
}
