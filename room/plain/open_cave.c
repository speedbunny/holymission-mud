inherit "/room/room";

#include "/room/room_defs.h"

int no_clean_up() { return 1; }

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "Open cave";

  long_desc =
    "You are in a wide open cave, lit by the sunlight "+
    "pouring in from the east. It looks as if this cave "+
    "was carved out on purpose. Perhaps the note posted " +
    "here could shine some light on this situation.\n";

  dest_dir = ({
    PLAIN + "plain12", "east",
  });

  property = ({ "no_clean_up" });
  items = ({
    "note", "It reads: If entrance gone, 'reenter' \n" +
      "will bring it back",
    "cave", "It looks man-made as opposed to natural",
    "sunlight", "It lights up the cave",
  });
}

void init() {
  ::init();
  "players/mangla/guild/entrance"->fake_funk();
  add_action("_entrance", "reenter");
}

status _entrance() {
  call_other("/players/mangla/guild/entrance", "???");
  return 1;
}
