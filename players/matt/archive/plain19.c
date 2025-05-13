inherit "room/room";

#include "/players/matt/definitions"

object snake1, snake2;

reset(arg) {
  if(!snake1) {
    snake1 = clone_object("players/matt/monsters/greensnake");
    MOVE(snake1, TO);
              }
  if(!snake2) {
    snake2 = clone_object("players/matt/monsters/greensnake");
    MOVE(snake2, TO);
              }
  if(arg) return;
  set_light(1);
  short_desc = "Eastern Plain";
  long_desc =
    "    You stand in the middle of the plains, flat grasslands\n" +
    "stretching out in all directions. The wind blows through here,\n" +
    "ruffling the tall grass and causing it to sway gently back\n" +
    "and forth in ripples.\n" +
    "    To the south stands a dark, forbidding-looking forest;\n" +
    "the sound of rushing water fills your ears, coming from a \n" +
    "wide river bending through to the east and north.\n";

  dest_dir = ({
    "players/matt/rooms/plains/plain13", "west",
    "players/matt/rooms/plains/plain15", "northwest",
              });

  items = ({
    "grasslands", "The grass all around you constantly shifts and sways",
    "grass", "Tall prairie grass blowing in the wind",
    "water", "There is a distinct magical quality about this water",
    "river", "You can barely see to the other side of this wide river",
    "forest", "Eyes seem to look back at you",
           });
           }

init() {
  ::init();
  add_action("no_way", "east");
  add_action("no_way", "north");
  add_action("no_way2", "south");
       }

no_way() {
  write("The water rushes by very quickly, and the river is very wide.\n" +
   "Without a means of transportation you would surely drown.\n");
  return 1;
         }

no_way2() {
  write("The forest is much too thick here.\n");
  return 1;
          }

fill_it(obj) {
  write("You fill the empty prism with water.\n");
  say(TP->NAME + " fills " + TP->POS + " prism with water.\n");
  obj->set_type("water");
  obj->set_extra("Elemental Water bubbles within it.\n");
  return 1;
             }

query_diamond_fill() { return "water"; }
