inherit "room/room";
object bear;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"This part of the cave looks like a large animal lives here.\n"+
"A massive iron chain is securely fastened to the wall with large\n"+
"iron bolts. It looks like the chain is used to keep an animal\n"+
"here. The cave becomes dryer and less icy to the north.\n";
    dest_dir = ({
"players/ted/frost/cave3", "north",
"players/ted/frost/cave1", "south"
    });
    items = ({
"chain","This massive iron chain is in good repair, with no signs of rust\n"+
        "or damage. It looks like is has been cleaned recently. It is\n"+
        "securly fastened to the cave wall. It looks like even a very\n"+
        "strong man could not pull it loose",
"bolts", "These iron bolts are sunk deep into the hard granite of the\n"+
         "cave wall. It would be almost impossible to pull them out"
    });
  }
  if(!present("cave bear")) {
    bear = clone_object("players/ted/monsters/cave_bear");
    move_object(bear, this_object());
  }
}

init() {
  ::init();
  add_action("north"); add_verb("north");
  add_action("pull"); add_verb("pull");
}

north() {
  if(present("cave bear")) {
    write("The Cave Bear blocks the entrance with his massive body!\n");
    return 1;
  }
}

pull(str) {
  if(str == "chain") {
    write("You pull as hard as you can on the chain, but nothing happens\n");
    say(capitalize(this_player()->query_name())+" pulls on the chain\n");
    return 1;
  }
}
