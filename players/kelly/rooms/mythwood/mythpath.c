inherit "room/room";

int _read(string item) {

  if (item != "sign") return 0;
    write("The sign reads :\n\n" +
          "Hello brave one! You have just entered the famous\n\n" +
          "             Mythwood\n\n");
    return 1;
}

void reset(int arg) {

    if (arg) return;
    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking on path in Mythwood.\n" +
              "There are some strange bushes.\n" +
              "A sign stands beside the path. \n";
    dest_dir=({
               "players/kelly/rooms/mythwood/mythpath2","west",
               "players/kelly/rooms/mythwood/mythpath3","east",
               "players/kelly/rooms/mythwood/mythpath4","north",
             });
    items=({
            "sign","There's something written on it",
            "bushes","Some strange bushes",
          });
}

void init() {
    ::init();
    add_action("_read", "read");
}

