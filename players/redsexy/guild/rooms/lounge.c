inherit "room/room";

#include "/players/redsexy/guild/guilddefs.h"

object board;

reset(arg) {
  if(!board) {
    board = clone_object("/boards/guilds/summoner_guild");
    MOVE(board, TO);
  }
  if(arg) return;
  set_light(1);
  short_desc = "Lounge";
  long_desc =
    "    This is a rather dark but very comfortable-looking room.\n" +
    "A thick black rug covers the wide floor, and soft furniture\n" +
    "and cushions provide for cozy relaxation. The room itself is\n" +
    "used for meetings between guild members and for a respite\n" +
    "from the hectic outside world.\n" +
    "    A stone staircase spirals upwards.\n";

  dest_dir = ({
    PATH + "rooms/powershop", "north",
    PATH + "rooms/armshop", "west",
    PATH + "rooms/magicshop", "south",
    PATH + "rooms/storage", "east",
  });

  items = ({
    "room", "A very comfortable meeting room / lounge",
    "rug", "Very thick and luxurious",
    "floor", "The floor is wide and covered with a huge rug",
    "furniture", "Soft black furniture",
    "cushions", "Soft black cushions",
    "staircase", "A black stone staircase leading up",
  });
}

init() {
  ::init();
  add_action("climb", "climb");
  add_action("up", "up");
}

climb(arg) {
  if(arg == "stairs" || arg == "staircase" ||
     arg == "up") {
    write("You climb the staircase.\n");
    TP->MOVEP("up the staircase#" + PATH + "room");
    return 1;
  }
  write("Climb what?\n");
  return 1;
}

up(arg) {
  if(!arg) {
    climb("up");
    return 1;
  }
}
