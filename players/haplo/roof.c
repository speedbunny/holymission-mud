/*
 * Author : Galadriel
 * Date   : 2-AUG-1993
 */
#include "path.h"
inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Roof";
  long_desc="You are on the roof of Galadriel's home. From here you can\n"
        + "look out over the entire world of Holy Mission. The wind is blowing\n"
        + "fresh air in your face and you feel rather content to be here.\n";
  items=({"roof","The roof is flat, otherwise you could fall off",
        "world","All kinds of tiny figures, running through many rooms,\n"
    	+"killing innocent monsters, entering and exiting buildings, wow,\n"
    	+"it looks a bit like an ant heap"});
}
