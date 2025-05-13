inherit "room/room";
#include "/players/baalthasar/shadows/path.h"

  reset(arg) {
if(arg) return;

set_light(1);
  short_desc = "The long road through the mist";
  long_desc =
"     You travel countless steps through the ever black mist, spotting \n"+
"occasional trees on the pathside.  The trees become more dense to the west. \n\n";

dest_dir = ({
PATH + "/mroad3", "west",
PATH + "/mroad", "east"
});

items = ({
  "tree", "The trees here seem to be warped and darkened upon further inspection",
"trees", "The trees here seem to be warped and darkened upon further inspection",
"mist", "The mist curls about the warped branches of the trees"
});
}
