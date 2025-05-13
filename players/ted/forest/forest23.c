inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"The trees crowd together here, almost cutting off all\n"+
"the light. As you push through the undergrowth, the\n"+
"hair on the back of your neck stands up. You turn around\n"+
"but see nothing.\n";
    dest_dir = ({
"players/ted/forest/forest13", "north",
"players/ted/forest/forest33", "south",
"players/ted/path/four_way", "west",
"players/ted/forest/forest24", "east"
    });
  }
}
