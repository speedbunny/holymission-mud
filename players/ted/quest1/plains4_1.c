inherit "room/room";

reset(arg) {
    if(!arg) {
    set_light(1);
    no_castle_flag = 1;
    short_desc = "Open Plains";
    long_desc =
"Farther to the north can be seen a dark line, low on the\n"+
"horizon. The ground slopes up to the west into a line of\n"+
"hills. Open grasslands stretch as far as the eye can see\n"+
"to the east and to the south. The dry, amber grass and\n"+
"scattered clumps of Joshua trees bake in the hot sun.\n";
    dest_dir = ({
"players/ted/quest1/plains3_1", "north",
"players/ted/quest1/plains5_1", "south",
"players/ted/quest1/hills4_9", "west",
"players/ted/quest1/plains4_2", "east"
  });
     items = ({
"hills","The hills start out small, but slowly build to\n"+
        "greater hights to the west",
"grass","The grass is about knee high here and very dry",
"joshua trees","These strange desert trees are almost like cactus"
  });
  }
}

init() {
  ::init();
  add_action("search"); add_verb("search");
}

search(str) {
   write("You don't find anything of interest.\n");
   say(capitalize(this_player()->query_name())+" searches.\n");
}
