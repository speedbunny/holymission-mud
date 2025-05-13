inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"The trees crowd together here, all most cutting off all\n"+
"light. Strang houlings and gutteral chanting can be\n"+
"heard to the west.\n";
    dest_dir = ({
"players/ted/forest/forest22", "south",
"players/ted/forest/forest11", "west"
    });
  }
}
