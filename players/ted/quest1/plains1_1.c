inherit "room/room";

reset(arg) {
    if(!arg) {
    set_light(1);
    no_castle_flag = 1;
    short_desc = "Open Plains";
    long_desc =
"The forest forms a wall of trees to the north and the ground\n"+
"slopes up to the west. Open grasslands stretch as far as the\n"+
"eye can see to the east and to the south. The dry, amber grass\n"+
"and scattered clumps of Joshua trees bake in the hot sun.\n";
    dest_dir = ({
"players/ted/quest1/forest9_1", "north",
"players/ted/quest1/plains2_1", "south",
"players/ted/quest1/hills1_9", "west",
"players/ted/quest1/plains1_2", "east"
  });
     items = ({
"trees","The line of trees forms a solid wall of darkness",
"forest","The line of trees forms a solid wall of darkness",
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
