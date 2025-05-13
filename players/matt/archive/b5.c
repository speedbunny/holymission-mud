inherit "room/room";

#include "/players/matt/definitions"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mud Hole";
  long_desc =
    "    You stand in a mud hole, knee-deep in wet brown muck.\n" +
    "It is very difficult to move freely, as the mud seems to\n" +
    "pull you down every time you try. There is a certain gloom\n" +
    "over this place, a pall of sadness that you cannot ignore.\n";

  dest_dir = ({
    "players/matt/rooms/forestb/b9", "southeast",
              });

  items = ({
    "mud", "A deep layer of brownish mud",
    "hole", "The entire area is covered with mud and sludge",
           });
           }

fill_it(obj) {
  write("You fill the empty prism with mud.\n");
  say(TP->NAME + " fills " + TP->POS + " prism with mud.\n");
  obj->set_type("earth");
  obj->set_extra("It contains raw elemental Earth.\n");
  return 1;
             }

query_diamond_fill() { return "mud"; }
