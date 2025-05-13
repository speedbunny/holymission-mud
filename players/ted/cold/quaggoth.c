inherit "room/room";

object quaggoth;
int i;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Frozen Wasteland";
    long_desc =
"There is nothing as far as the eye can see\n"+
"except snow and ice.\n";
    dest_dir = ({
"players/ted/cold/snow", "east"
    });
  }
  i = random(5);
  if(!present("quaggoth")) {
    while(i < 8) {
      i ++;
      quaggoth = clone_object("players/ted/monsters/quaggoth");
      call_other("players/ted/random_treasure","make_item",quaggoth,8);
      move_object(quaggoth, this_object());
    }
  }
}
