inherit "room/room";

object dragon, gem;

init() {
  ::init();
  add_action("west"); add_verb("west");
}

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Ice Filled Cave";
    long_desc =
"This cold cave is made of ice. Huge ice stalagtites\n"+
"hang from the ceiling. Large gouge marks can be seen\n"+
"on the walls and floor. A strange rumbling comes from\n"+
"the west.\n";
    dest_dir = ({
"players/ted/cold/ice_cave", "east"
    });
  }
if(!present("snow dragon")) {
  dragon = clone_object("players/ted/monsters/snow_dragon");
  call_other("players/ted/random_treasure","make_item",dragon,19);
  call_other("players/ted/random_treasure","make_item",dragon,19);
  move_object(dragon, this_object());
 }
}


west() {
 if(present("snow dragon")) {
  write("The dragon keeps you from going west.\n");
  return 1;
 }
 call_other(this_player(),"move_player","west#players/ted/cold/steel_drag");
 return 1;
}
