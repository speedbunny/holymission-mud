inherit "room/room";
#include "/players/saffrin/defs.h"

object board;

reset(arg) {
  if(!arg) {
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
  MOVE(CLONE("/boards/guilds/mage_outer"),TO);
  }
}

init() {
    ::init();

    if(TP && TPGUILD !=5 && !TPWIZ) {
      say("Hey, that isn't a mage!!!!\n");
      printf("Sorry, Mages only!\n");
       TP->MP("to the church#room/church");
      return;
  }
}

