inherit "players/cashimor/inherit/sand";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Chimney";
    long_desc="You seem to be in a kind of chimney. Above you is a\n"
            + "forest, and the chimney continues downward.\n";
    items=({"chimney","It looks very old",
             "forest","It looks very open"});
    set_light(1);
    dest_dir=({"players/cashimor/room/livingroom","down",
               "room/forest9","up"});
  }
}
