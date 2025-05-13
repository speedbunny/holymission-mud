inherit "players/cashimor/inherit/water";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="In the sewers";
    long_desc="You're in a tunnel filled with something that feels like "
            + "dirty water. It sure is very unpleasant down here.\n";
    items=({"tunnel","It looks very old",
            "water","It feels dirty and streams quickly to the east"});
    dest_dir=({"players/cashimor/room/sewer","west",
               "players/padrone/outside/tunnel1","east"});
  }
}

init() {
  ::init();
  add_action("west_it","west");
}

west_it() {
  write("You can't move west, the water is moving too quickly.\n");
  say(this_player()->query_name()+" tries to go west, but fails.\n");
  return 1;
}

subtract_sand() {
  return 1;
}
