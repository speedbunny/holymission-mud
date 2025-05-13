inherit "room/room";

object treant, gem;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"This part of the forest almost looks like a garden\n"+
"The trees are in almost perfect rows and are in\n"+
"perfect shape. The sun shines brightly on a few\n"+
"daisys that have grown on the open paths between\n"+
"the trees. A small clearing lies in the center.\n";
    dest_dir = ({
"players/ted/forest/forest24", "south",
"players/ted/forest/forest13", "west"
    });
  }
  if(!present("treant")) {
    treant = clone_object("players/ted/monsters/treant");
    move_object(treant, this_object());
    call_other("players/ted/random_treasure","make_item",treant,19);
    call_other("players/ted/random_magic","make_item",treant,19);
  }
}
