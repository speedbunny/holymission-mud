inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Main square.";
  long_desc=
   "You are at the village's main square. The main road goes from southeast down\n" +
   "in the northwest direction. There are lots of people moving around and yelling\n" +
   "to trade their stuff which makes the place a natural marketplace. Some of them\n" +
   "make gestures to you and offer you things automatically. You can see the houses\n" +
   "of village standing proudly everywhere around. There is also a sign hanging on\n" +
   "one of the many stalls.\n";

  dest_dir=({ PATHR + "vil31.c", "west",
              PATHR + "vil32.c", "north",
              PATHR + "vil35.c", "east",
              PATHR + "vil34.c", "south",
              PATHR + "vil30.c", "northwest",
              PATHR + "vil36.c", "southeast"
             });

  items=({ "village", "The village is alive, people move and talk on the streets.",
           "houses", "The houses are made of wood and they look old.",
           "citizens", "The citizens of the village are rushing in the streets.",
           "streets", "There are people rushing in the streets, though they look a bit narrow.",
           "marketplace", "The marketplace is full of life and trade.",
           "sign", "It is an information sign, you could probably read it.",
           "stalls", "There are lots of various stalls each with a trader behind offering things."
          });

  smell="You feel various aromas coming from the many stalls.";

}

init() {
  ::init(); 
  add_action("read_sign", "read");
}

read_sign(string str1) {
  if (str != "sign") return;
  write("   Welcome in our village, brave adventurers!\n\n" +

        "                       [SHOP] [ARMORY]             \n" +
        "                           I   I                   \n" +
        "   forest-[ ]-[ ]-[ ]-[ ]-[ ]-[ ]-[WEAPONRY]       \n" +
        "                   I       I X I \                 \n" +
        "                 [INN]    [ ]-[+]-[ ]              \n" +
        "                         /   \ I X I \             \n" +
        "                      [ ]     [ ]-[ ]-[ ]          \n" +
        "                       I                 \         \n" +
        "                      [ ]                 [ ]      \n" +
        "                       I                     \     \n" +
        "                  corn fields          Dark Forest \n\n" +
        "   We are sorry about our Dark Forest's gamekeeper's death and\n" +
        "   because of the growing evil and raising number of murders we\n" +
        "   strongly recommend to avoid the Dark Forest as much as possible.\n" +
        "   We also put a reward of 500 gold coins to that person who finds\n" +
        "   and possibly destroys the evil spirit's nest in our formerly green\n" +
        "   but nowadays dark forest. May luck be with you brave adventurers!\n\n" +
        "                                The major of the city\n"
        );
  say(TPN + " thoroughly reads the sign.\n");
  return 1;
}

