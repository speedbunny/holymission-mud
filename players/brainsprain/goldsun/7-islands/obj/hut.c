inherit "/obj/thing";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"
#define IN ir+"/pub_shop"

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("small hut");
 set_alias("hut");
 set_short("A small hut");
 set_long(
"This small little hut has two tiny windows on its front facade.  "+
"There is a sign over the door.  On the sign is written: < Zuzana's hut >.\n");
 set_can_get(0);
}

init(){
 ::init();
add_action("enter","enter");
}

int enter(string str)
{
 notify_fail("Enter what?\n");
 if (str=="hut" || str=="door")
 {
  this_player()->move_player("in#"+IN);
  return 1;
 }
}
