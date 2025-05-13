inherit "room/room";

object griffon;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"Under some conceiling bushes sits what can only be\n"+
"described as a nest. A rather large nest, but a\n"+
"nest none the less. As you look closer you can see\n"+
"fragments of bleached white bone and shredded clothes\n"+
"line the nest.\n";
    dest_dir = ({
"players/ted/forest/forest21", "north",
"players/ted/forest/forest32", "east"
    });
  }
  if(!present("griffon")) {
    griffon = clone_object("players/ted/monsters/griffon");
    move_object(griffon, this_object());
    call_other("players/ted/random_treasure","make_item",griffon,17);
    call_other("players/ted/random_magic","make_item",griffon,17);
    call_other("players/ted/random_armor","make_item",griffon,17);
  }
}
