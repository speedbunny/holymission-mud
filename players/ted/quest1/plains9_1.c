inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(1);
    no_castle_flag = 1;
    short_desc = "Open Plains";
    long_desc =
"The hills to the west are almost to small to be called hills, they\n"+
"are simply mounds rising from the earth. The feted smell of rotting\n"+
"vegitation comes from the southwest. A dark line of trees blocks the\n"+
"sunlight to the south.\n";
    dest_dir = ({
"players/ted/quest1/plains8_1", "north",
"players/ted/quest1/forest1_1", "south",
"players/ted/quest1/hills9_9", "west",
"players/ted/quest1/plains9_2", "east"
    });
    items = ({
"hills","The hills start out low and build to great hights\n"+
        "farther to the northwest",
"forest","The branches of the trees overhang one another, almost\n"+
         "blocking all light to the south"
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
