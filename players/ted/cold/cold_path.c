inherit "room/room";

init() {
 ::init();
 add_action("north"); add_verb("north");
 add_action("south"); add_verb("south");
}

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Cold Path";
    long_desc =
"This path becomes colder the farther west you\n"+
"travel. Buildings can be seen both to the north\n"+
"and to the south.\n";
    dest_dir = ({
"players/ted/cold/cold_path2", "west",
"players/ted/path/wierd_path", "east"
    });
  }
}

north() {
 if(this_player()->query_level() <= 10) {
   this_player()->move_player("north#players/ted/cold/cold_dwarf");
   return 1;
 }
 write("You are above the tenth level.....you are to high a level.\n");
 return 1;
}

south() {
 if(this_player()->query_level() <= 10) {
   this_player()->move_player("south#players/ted/cold/cold_orc");
   return 1;
  }
 write("You are above tenth level.....you are to high a level.\n");
 return 1;
}
