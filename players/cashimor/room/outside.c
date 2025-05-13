inherit "players/cashimor/inherit/quicksand";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Outside in sand";
    long_desc="You're standing outside the house. There is a wet\n"
            + "spot of sand here.\n";
    items=({"house","It looks old, and surrounded by sand and earth",
            "spot","It seems to be the entrance to a sewer"});
    dest_dir=({"players/cashimor/room/sewer","down"});
    nodanger=1;
  }
}
