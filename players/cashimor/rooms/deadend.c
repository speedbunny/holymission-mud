inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="Dead end?";
    long_desc="You're halfway up the mountain, but you can't see a path.\n"
            + "Since you can easily get lost in these mountains, you decide\n"
            + "to return...\n";
    items=({"mountain","It looks rather steep"});
    dest_dir=({"players/cashimor/rooms/hermit","south"});
  }
}
