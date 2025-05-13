inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"The forest is especially dense here, you have to push\n"+
"through undergrowth so thick you can see no more than\n"+
"an arms length in front of you.\n";
    dest_dir = ({
"players/ted/forest/forest23", "north",
"players/ted/forest/forest34", "east"
    });
  }
}
