

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Pool";
    no_castle_flag = 0;
    long_desc = 
        "The water in the pool turns a bit warmer here, but you can't figure out why.\n"
        + "Then you look at the water below you and notice a strange greenish glow. \n"
        + "Small waves from the pool lap up against a shore to the west and you can\n"
        + "continue swimming to the north or the east.\n";
    items = ({
         "glow","Maybe you should dive and investigate it"
 
            });
    dest_dir = 
        ({
        "/players/silas/caves/pool2b", "north",
        "/players/silas/caves/pool1", "east",
        "/players/silas/caves/shore", "west",
        });
    smell = "The air here has a stuffy quality to it.\n";
}
init() {
  ::init();
  add_action("dive","dive");
}

dive(str) {
  if (str!="pool") {
     write("You dive into the chilly waters.\n");
     this_player()->move_player("dives#players/silas/caves/unpool");
     return 1;
     }
}


