/* s08 */
#include "/players/qclxxiv/leaf3/leaf3room.h"
FOUR_EXIT( REGION+"e05", "north",
REGION+"s07", "southwest",
REGION+"e06", "east",
REGION+"s09", "northeast",
"A small street",
"A small street. At some distance the dyke surrounds you from the northwest\n"
+"to the southeast. To the southwest some buildings can be seen.\n",
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
		"dyke", "A steep gray old dyke",
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
