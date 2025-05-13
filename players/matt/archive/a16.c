inherit "room/room";

#include "/players/matt/definitions"

object walker1, walker2;

reset(arg) {
  if(!walker1) {
    walker1 = clone_object("players/matt/monsters/windwalker");
    MOVE(walker1, TO);
               }
  if(!walker2) {
    walker2 = clone_object("players/matt/monsters/windwalker");
    MOVE(walker2, TO);
               }
  if(arg) return;
  set_light(0);
  short_desc = "Windy Clearing";
  long_desc =
    "    The howl of the wind is almost deafening in the clearing\n" +
    "you now stand in. You find it difficult to move against its\n" +
    "powerful breath, which continually changes direction and\n" +
    "makes everything around you sway and bend sickeningly.\n";

  dest_dir = ({
    "players/matt/rooms/foresta/a12", "southeast",
              });

  items = ({
    "clearing", "The clearing seems to be moving from the wind",
           });
           }

fill_it(obj) {
  write("You fill the empty prism with wind.\n");
  say(TP->NAME + " fills " + TP->POS + " prism with wind.\n");
  obj->set_type("wind");
  obj->set_extra("It vibrates as the wind within it blows around.\n");
  return 1;
             }

query_diamond_fill() { return "wind"; }

