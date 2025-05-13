inherit "room/room";

object elemental, shield;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Frozen Waste";
    long_desc =
"There is nothing as far as the eye can see\n"+
"except snow and ice.\n";
    dest_dir = ({
"players/ted/cold/snow", "west"
    });
  }
  if(!present("ice elemental")) {
    elemental = clone_object("players/ted/monsters/ice_elemental");
    call_other("players/ted/random_armor","make_item",elemental,10);
    move_object(elemental, this_object());
  }
}

