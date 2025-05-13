inherit "room/room";

reset(arg) {
    if(!arg) {
    set_light(0);
    no_castle_flag = 1;
    short_desc = "Dark Hole";
    long_desc =
"The earthy smell of freshly dug earth and growing things pervades\n"+
"this dark hole. It is scarcely large enough for you to stand up in.\n"+
"Your not exactly sure how this hole got here, but it is here.\n";
    dest_dir = ({
"players/ted/quest1/plains7_1", "up"
  });
     items = ({
"hole","The dirt is dark with moisture and smells rich and earthy",
"dirt","The dirt is dark with moisture and smells rich and earthy",
"earth","The dirt is dark with moisture and smells rich and earthy"
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
