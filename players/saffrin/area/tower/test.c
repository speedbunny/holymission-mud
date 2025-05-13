inherit "/room/room";

void reset(status arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Equipment room";
  long_desc = "\
This is the room where you can leave equipment for other\n\
druids to use.  Only guild members can access this room.\n";
  property = ({ "no_clean_up" });
  dest_dir = ({
    "/players/meecham/guild/room","east"
  });
}

#if 0
// 101297: Sauron: Removed - see code in main guild room for blocking exit.
void init() {
  ::init();
  if (this_player()->query_guild() != 2) {
    write("Sorry, druids only.\n");
    this_player()->move_player("to the church#room/church");
  }
}
#endif // 0
