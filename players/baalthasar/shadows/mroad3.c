inherit "room/room";
#include "/players/baalthasar/shadows/path.h"

  reset(arg) {
if(arg) return;

set_light(1);
  short_desc = "Along the road of mist";
  long_desc =
"     More trees are visible around the path as the mist appears to \n"+
"have lifted some.  Muffled shrieks from the west break the silence. \n"+
"You can also make out a dark gathering of shadows to the west. \n\n";

dest_dir = ({
PATH + "/mroad4", "west",
PATH + "/mroad2", "east"
});

items = ({
  "path", "The road continues to run east and west",
  "trees", "They are much thicker here",
  "tree", "They are more frequent here",
  "mist", "It's still there and still dark!",
  "shadow", "You can't make it out from here, but it blocks what \n"+
"little light comes from the western sky",
  "shadows", "You can't make them out from here, but it blocks what \n"+
"little light comes from the western sky"
});
  }

init() {
::init() ;
add_action("listen", "listen"); }
listen() {
write("The shrieks seem to surround you in the mist. \n");
return 1;
}
