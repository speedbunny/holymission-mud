#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="The Abott's Office";
     long_desc=
"You have entered the office of the Abbot.  It is plain but well con-\n" +
"structed, and comfortably furnished.  The rich wood of the Abott's desk\n" +
"gleams from the attentions of his acolytes.\n";
     items=({ "door","A plain old oak door" });
     dest_dir=({ PATH+"/e20","north" });
  }
}
