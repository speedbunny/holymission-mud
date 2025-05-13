inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Frozen Mountain Top";
    long_desc =
"This ice covered mountain top provides a spectacular\n"+
"view of the surrounding land. Far to the north can be\n"+
"seen a shining castle. While off to the east\n"+
"lies a smoking volcano.\n";
    dest_dir = ({
"players/ted/cold/ice_cave", "down",
"players/ted/cold/yeti", "west"
    });
  }
}
