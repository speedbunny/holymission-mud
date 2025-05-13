inherit "players/cashimor/inherit/quicksand";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="In the sewers";
    long_desc="You're in a sewer filled with water and sand. It sure is very\n"
            + "unpleasant down here.\n";
    items=({"sewer","It looks very old",
            "water","It feels dirty",
            "sand","You don't like the idea you might suffocate here"});
    dest_dir=({"players/cashimor/room/outside","up",
               "players/cashimor/room/tunnel","east"});
  }
}
