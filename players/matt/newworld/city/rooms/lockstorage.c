inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Locker Storage Room";
  long_desc =
    "    This is the storage room for all Dyolf lockers.\n";

  dest_dir = ({
    NWCITY + "rooms/lockerroom", "back",
  });
  property = ({ "no_clean_up" });
  replace_program("/room/room");
}
