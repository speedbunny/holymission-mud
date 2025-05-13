inherit "room/room";

object voorwerp;

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="The hermit";
    long_desc="You're on a path leading up into the moutains.\n"
            + "This is a fine spot to rest for a while...\n";
    dest_dir=({"players/cashimor/rooms/deadend","north",
               "room/plane12","south"});
    items=({"path","The path becomes more stony to the north"});
  }
    if(!present("hut",this_object())) {
      voorwerp=clone_object("players/cashimor/objects/hut");
      move_object(voorwerp,this_object());
    }
    if(!present("piak",this_object())) {
      voorwerp=clone_object("players/cashimor/monsters/piak");
      move_object(voorwerp,this_object());
  }
}

init() {
  ::init();
  add_action("rest","rest");
}

rest() {
  write("You rest at this beautiful spot...\n");
  say(this_player()->query_name()+"Sits down and rests for a while.\n");
  return 1;
}
