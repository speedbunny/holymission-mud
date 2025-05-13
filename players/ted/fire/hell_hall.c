inherit "room/room";

object hell_hound;

init() {
  ::init();
  add_action("do_north"); add_verb("north");
}

reset(arg) {
  int i;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "An Unusual Passageway";
    long_desc =
"This stone passageway has small iron gates set flush with\n"+
"the ground. Right now all of them are open, letting the\n"+
"hell hounds they contain roam free!\n";
    dest_dir = ({
"players/ted/fire/throne", "north",
"players/ted/fire/ante_room", "south"
    });
  }
  if(!present("hell hound")) {
    i = 0;
    while(i <= 4) {
      i ++;
      hell_hound = clone_object("players/ted/monsters/hell_hound");
      move_object(hell_hound, this_object());
    }
  }
}

do_north() {
 if(present("hell hound")) {
  write("The Hell Hound blocks your way!\n");
  return 1;
 }
}
