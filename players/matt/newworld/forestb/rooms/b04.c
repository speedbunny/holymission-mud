inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Silent Clearing";
  long_desc =
    "    A sudden and utter silence strikes you here. No sound, save\n" +
    "that of your breathing and your heartbeat, reaches your ears.\n" +
    "The birdsong that was so clear and pervasive before has all but\n" +
    "disappeared, and though the trees and grass are still green you\n" +
    "have the strange feeling that Death lurks nearby.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b08", "northeast",
  });

  items = ({
    "trees", "Lushly-leaved trees surround you",
    "grass", "Green grass covers the forest floor",
  });
  replace_program("/room/room");
}
