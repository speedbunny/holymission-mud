/* s07 */
#include "/players/qclxxiv/leaf3/leaf3room.h"
FOUR_EXIT( REGION+"e03", "north",
REGION+"s06", "southwest",
REGION+"e04", "east",
REGION+"s08", "northeast",
"A small street",
"A small street. To the north and east you can see no more buildings.\n"
+"Far to the north and east you can see the dyke surrounding the hamlet.\n",
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
