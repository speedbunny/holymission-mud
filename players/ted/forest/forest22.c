inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"The trees crowed together here, almost cuting off all\n"+
"the light. You get the feeling that something evil is\n"+
"watching you......nothing that you can see....but still\n"+
"you keep turning at every little sound....expecting\n"+
"something to be there.\n";
    dest_dir = ({
"players/ted/forest/forest12", "north",
"players/ted/forest/forest32", "south",
"players/ted/forest/forest21", "west",
"players/ted/path/four_way", "east"
    });
  }
}
