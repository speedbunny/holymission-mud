/* e02 */
#include "/players/qclxxiv/leaf3/leaf3room.h"
ONE_EXIT( REGION+"s2", "west",
"An empty place",
"An empty place. To the south and east you look up to the steep dyke.\n",
1 )

towadden() { return "west"; }

/*
init() {
   ::init();
   add_action( "do_get", "get" );
}
*/

extra_reset(arg) {
   if (arg) return;
 /*   set_nodig(1); */
   items = ({
		"dyke", "A steep gray old dyke",
   });
}

/*
do_get( arg ) {
   if (!arg) return 0;
   switch (arg) {
       case "street" : write("How do you plan to carry that?\n"); break;
       default: return 0;
   }
   return 1;
}
*/
