inherit "room/room";
#include "/players/saffrin/defs.h"

object board;

reset(arg) { 
  set_light(1);
  short_desc="Outer Circle of an astral plane";
  long_desc=
      "You are in a dark green circle on an astral plane.  "+
      "Glittering sparkles of mist flutter all around you.  "+
      "You can hear a soft, faint buzzing, that is whispering "+
      "magical secrets in your ears.  There is a lighter green "+
      "circle, rotating on the outer inner of the plane.  You "+
      "sense safety in the air.\n";
  property=({ "no_fight" });
  smell="There is the smell of roses.\n";
  items=({
      "circle", "A dark green circle",
      "sparkles", "Glittering sparkles flutting in the circle",
      "mist", "A mist of glittering sparkles",
      "plane", "An astral plane made up of circles",
  });
  dest_dir=({
      TOWER+"room/inner", "inner",
  });
  clone_list=({
     1, 1, "board", "/boards/guilds/mage_outer", 0,
  });
  ::reset(arg);
  replace_program("room/room");
}


