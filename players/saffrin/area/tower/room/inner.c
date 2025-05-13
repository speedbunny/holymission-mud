inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Inner Circle of an astral plane";
  long_desc=
      "You are in a light green circle on an astral plane.  "+
      "Glittering sparkles of mist flutter all around you.  "+
      "You can hear a soft, faint buzzing, that is whispering "+
      "magical secrets in your ears.  There is a darker green "+
      "circle, rotating on the outer circle of the plane.  You "+
      "notice a door floating in the center of the circle.\n";
  property=({ "no_fight" "no_teleport" });
  smell="There is the smell of roses.\n";
  items=({
      "circle", "A light green circle",
      "sparkles", "Glittering sparkles flutting in the circle",
      "mist", "A mist of glittering sparkles",
      "plane", "An astral plane made up of circles",
      "door", "A door floating in the middle of the circle",
  });
  dest_dir=({
      TOWER+"room/outer", "outer",
      TOWER+"room/chamber", "door",
  });
  replace_program("room/room");
  ::reset();
}

