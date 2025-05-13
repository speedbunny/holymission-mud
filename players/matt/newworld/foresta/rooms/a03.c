inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    A mist surrounds your ankles as you stand here. The sparse\n" +
    "light reflects strangely off of it, causing it to glisten with\n" +
    "a pale glow. You can hear a very faint hissing noise, but\n" +
    "cannot quite tell where it comes from.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a09", "west",
    NWFORESTA + "rooms/a04", "south",
    NWFORESTA + "rooms/a08", "northwest",
  });

  items = ({
    "mist", "Cold white mist, gliding just above the ground",
    "light", "Eerie whitish light that reflects off of the mist",
  });
  replace_program("/room/room");
}
