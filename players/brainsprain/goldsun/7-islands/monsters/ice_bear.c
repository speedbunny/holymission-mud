inherit "/obj/monster";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

#define TH(x) transfer(clone_object(x),this_object())

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("ice bear");
set_race("bear");
set_short("An ice bear");
set_gender(1);
set_long(
"A huge ice bear stands up onto its rear legs as you enter the room.  "+
"His fur is white but is plastered to its body in places and stained red.  "+
"The look in its black eyes lead you to believe that his might not be sane.\n");
set_level(44+random(10));
set_wc(49);
set_ac(5);
set_size(4);
set_al(-130);
set_aggressive(1);
}

