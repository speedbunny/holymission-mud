inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="No dead end!";
    long_desc="You're halfway up the mountain, and you see Piak's path!\n"
            + "It's very hard to see and you're sure you're going to forget\n"
            + "the route, but now you can continue your journey through the\n"
            + "mountains!\n";
    dest_dir=({"players/cashimor/rooms/hermit","south",
               "players/cashimor/rooms/top","north"});
    items=({"path","This path is very hard to notice.."});
  }
}
