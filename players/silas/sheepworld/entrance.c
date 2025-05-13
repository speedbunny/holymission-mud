inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Sheepworld Entrance";
    no_castle_flag = 0;
    long_desc = 
        "This is the entrance to a beautiful meadow which lies ahead to the\n"+
        "north. A blue portal shimmers to the south, and it it surrounded by\n"+
        "a group of towering pine trees which rustle in the wind. Pine cones\n"+
        "cover the damp ground and you feel at ease here.\n";
    dest_dir = 
        ({
        "/players/silas/sheepworld/m1", "north",
        });
    items =({
        "portal","Maybe you can enter it",
        "trees","They must be centuries old",
        "cones","Brown, scaly pine cones",
           });
    smell = "It kinda smells like Pine-Sol around here.\n";
    ::reset();
}
init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
  if (str=="portal") {
     write("Sadness overwhelms you as you leave the world of sheep.\n");
     this_player()->move_player("enters the portal#players/silas/caves/tunnel3");
     return 1;
  }
  else {
  write ("What do you want to enter?\n");
  return 1;
  }
}

query_light() {
    return 0;
}

