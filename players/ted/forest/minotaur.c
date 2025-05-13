inherit "room/room";

object minotaur;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"There is a straw pallet and a table in this cave.\n"+
"The overwhelming smell of cattle permeates the air,\n"+
"making it hard to breathe.\n";
    dest_dir = ({
"players/ted/forest/forest13", "south"
    });
  }
  if(!present("minotaur")) {
    minotaur = clone_object("players/ted/monsters/minotaur");
    move_object(minotaur, this_object());
    call_other("players/ted/random_armor","make_item",minotaur,15);
    call_other("players/ted/random_armor","make_item",minotaur,15);
    call_other("players/ted/random_weapon","make_item",minotaur,15);
  }
}
