inherit "room/room";

#include "/players/matt/definitions"

object man;

reset(arg) {
  if(!man) {
    man = clone_object("players/matt/guild/creatures/figure");
    MOVE(man, TO);
           }
  if(arg) return;
  set_light(1);
  short_desc = "Dim Room";
  long_desc =
    "    This is a plain, dimly-lit room. Somehow the fierce, biting\n" +
    "winds do not enter through the open doorway leading outside.\n" +
    "    Upon first inspection the room appears completely empty;\n" +
    "however, as you look more closely you notice a black-robed\n" +
    "figure watching you from the shadows.\n";
           }

init() {
  ::init();
  add_action("enter", "enter");
       }

enter(arg) {
  if(arg == "door" || arg == "doorway") {
    write("You enter the doorway.\n");
    TP->MOVEP("through the doorway#" +
	      "players/matt/rooms/mountains/circle");
    return 1;
                                        }
  write("Enter what?\n");
  return 1;
           }
