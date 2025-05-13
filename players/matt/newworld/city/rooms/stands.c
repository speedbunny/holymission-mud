inherit "/room/room";

#include "lw.h"
#include "/players/matt/defs.h"

#define ARENA (NWCITY + "rooms/arena")

void reset(int arg) {
  if(arg) return;
  enable_commands();
  set_light(1);
  short_desc = "Stands of the Arena";
  long_desc =
    "    Fans of the bloodsport surround you by the hundreds here.\n" +
    "Many levels of long stone benches encircle the Arena below,\n" +
    "providing you with an excellent view of the proceedings.\n";
  dest_dir = ({
    NWCITY + "rooms/mainst04", "out",
  });
  items = ({
    "arena", "@@arena_desc@@",
    "Arena", "@@arena_desc@@",
    "fans", "Hundreds of enthusiastic fans",
    "levels", "Many levels of circular stone benches around the Arena",
    "benches", "Stone benches that make up the stands of the Arena",
    "view", "@@arena_desc@@",
    "proceedings", "@@arena_desc@@",
  });
}

void init() {
  ::init();
}

void arena_desc() {
  return ARENA->query_glads();
}

void catch_tell(string str) {
  TELLR(ARENA, lw("Stands-> " + str));
}
