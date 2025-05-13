inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"The trees thin out here at the top of a small hill.\n"+
"A bubbling brook runs in front of the entrance to a\n"+
"small cave to the north.\n";
   dest_dir = ({
"players/ted/forest/minotaur", "north",
"players/ted/forest/forest23", "south",
"players/ted/forest/forest14", "east"
    });
    items = ({
"brook","A small stream filled with clear, cold water",
"cave","A dark cave entrance. You can here strange noises within"
    });
  }
}
