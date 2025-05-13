inherit "room/room";

reset(arg) {
    if(!arg) {
    set_light(1);
    no_castle_flag = 1;
    short_desc = "Open Plains";
    long_desc =
"A line of hills builds to the west while the open grasslands\n"+
"stretch as far as the eye can see in all other directions.\n"+
"The grass here is knee high and very dry and brittle\n";
    dest_dir = ({
"players/ted/quest1/plains5_1", "north",
"players/ted/quest1/plains7_1", "south",
"players/ted/quest1/hills6_9", "west",
"players/ted/quest1/plains6_2", "east"
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
