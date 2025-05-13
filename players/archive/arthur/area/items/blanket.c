/*Code by Arthur for Holy Mission - 140.78.3.1 Date Done 11.4.94 */
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"

reset (arg) {
if (arg) return;
   set_id("Blanket");
  set_short("A warm blanket");
   set_alias("blanket");
   set_long("A nice warm and fuzzy blanket.\n");
   set_value(0);
   set_weight(0);
}
init() {
     add_action("use","use");
     add_action("use","apply");
     add_action("use","wear");
     ::init();
}

drop() {
    return 0;
}
use(str) {
 if(!str) return 0;
   if(str !="blanket") return 0;
   say(this_player()->query_name()+" cuddles a nice warm blanket.\n");
   write("You feel much warmer now that you are cuddling the blanket.\n");
   return 1;
  }
