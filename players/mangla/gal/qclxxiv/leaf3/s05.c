/* s05 */
#include "/players/qclxxiv/leaf3/leaf3room.h"
FOUR_EXIT( REGION+"t05", "north",
REGION+"s4", "southwest",
REGION+"t06", "east",
REGION+"s06", "northeast",
"A small street",
"A small street running through an old and decayed fishing-village.\n"
+"To the north and east are some houses.\n",
1 )

towadden() { return "southwest"; }

init() {
   ::init();
   add_action( "do_get", "get" );
}

extra_reset(arg) {
   if (arg) return;
    set_nodig(1);
   items = ({
       "street" , "Just a bumpy old bricked street",
   });
}

do_get( arg ) {
   if (!arg) return 0;
   switch (arg) {
       case "street" : write("How do you plan to carry that?\n"); break;
       default: return 0;
   }
   return 1;
}
