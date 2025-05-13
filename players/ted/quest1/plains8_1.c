inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(1);
    no_castle_flag = 1;
    short_desc = "Open Plains";
    long_desc =
"A dark line can be seen on the horizon to the south. The hills\n"+
"to the west are dark and gloomy. The open grasslands stretch as\n"+
"far as the eye can see to the east and to the north.\n";
    dest_dir = ({
"players/ted/quest1/plains7_1", "north",
"players/ted/quest1/plains9_1", "south",
"players/ted/quest1/hills8_9", "west",
"players/ted/quest1/plains8_2", "east"
    });
    items = ({
"hills","The hills start out low and build to great hights\n"+
        "farther to the west",
"grass","The grass is about knee high here and very dry",
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
