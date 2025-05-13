inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Very Hot Path";
    long_desc =
"The smell of sulfer and burning fills the air.\n"+
"To the south can be seen a large pool of lava.\n"+
"While strange tree like shapes lie to the north.\n"+
"Far to the east can be seen, through the haze and\n"+
"smoke, a large smoking volcano.\n";
    dest_dir = ({
"players/ted/hot/fire_forest", "north",
"players/ted/hot/fire_south", "south",
"players/ted/hot/hot_path", "west",
"players/ted/hot/fire_path2", "east"
     });
  }
}
