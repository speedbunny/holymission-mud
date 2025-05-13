inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "South of Hot Path";
    long_desc =
"The heat is more intense here. A large pool of lava\n"+
"is exposed to the open air south of here.\n";
    dest_dir = ({
"players/ted/hot/fire_path", "north",
"players/ted/hot/fire_troll", "south"
    });
  }
}
