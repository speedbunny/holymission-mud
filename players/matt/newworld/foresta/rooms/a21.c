inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(-1);
  short_desc = "Deep Forest";
  long_desc =
    "    The gloom here permeates your very soul, a lingering\n" +
    "dark presence that makes the air itself seem alive with it.\n" +
    "Looking about you at the dismal scene, the dark withered\n" +
    "trees, the dead branches, makes you think about leaving\n" +
    "this place.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a23", "west",
    NWFORESTA + "rooms/a20", "north",
  });

  items = ({
    "scene", "The woods are alive with evil",
    "trees", "Gnarled remains of trees",
    "branches", "Arm-like branches with fingers reaching towards you",
  });
  replace_program("/room/room");
}
