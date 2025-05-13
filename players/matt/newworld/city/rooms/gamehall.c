inherit "/room/room";

#include "/players/matt/defs.h"

string games_list;

reset(arg) {
  if(arg) return;
  games_list = ({ "battleship", });
  set_light(1);
  short_desc = "Hall of Games";
  long_desc =
    "    This is a large hall filled with all sorts of tables and\n" +
    "booths containing various games. It is very crowded here, as\n" +
    "many people push and shove to be next to play. There is a list\n" +
    "posted on the far wall.\n";

  dest_dir = ({
    NWCITY + "rooms/mainst04", "south",
  });

  items = ({
    "hall", "This is a game room",
    "tables", "The tables have games on them",
    "booths", "You can play games in the different booths",
    "games", "There is a large variety of games here",
    "people", "Many people crowd the room",
    "list", "A large list you could read",
  });
}

init() {
  ::init();
  add_action("read", "read");
  add_action("play", "play");
}

read(arg) {
  if(arg == "list") {
    write("You read the list. It says:\n\n");
    write("    Welcome to Matt's famous Hall of Games. Here you can play\n");
    write("any of a variety of games simply by typing \"play <game>\".\n");
    write("The current list of games is:\n");
    write("  - battleship\n");
    write("\nEnjoy!      - Matt\n");
    return 1;
  }
}

play(arg) {
  if(member_array(arg, games_list) != -1) {
    if((NWCITY + "rooms/" + arg)->query_full()) {
      write("That game is occupied at the moment.\n");
      return 1;
    }
    write("You enter the " + CAP(arg) + " Room.\n");
    TP->MOVEP("into the " + CAP(arg) + " Room#" +
	      NWCITY + "rooms/" + arg);
    return 1;
  }
}
