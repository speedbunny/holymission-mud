inherit "room/room";

object yeti, crystal;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Ice Cave";
    long_desc =
"This is a frozen desolate ice cave. A chill wind\n"+
"wistles through the opening making even colder.\n";
    dest_dir = ({
"players/ted/cold/cold_top", "east"
    });
  }
  if(!present("yeti")) {
    yeti = clone_object("players/ted/monsters/yeti");
    call_other("players/ted/random_treasure","make_item",yeti,10);
    move_object(yeti, this_object());
  }
}
