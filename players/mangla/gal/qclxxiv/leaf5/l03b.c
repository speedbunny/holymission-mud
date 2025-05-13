/* l03 */
#include "/players/qclxxiv/leaf5/leaf5room.h"
object griffin;

TWO_EXIT( REGION+"l07", "northwest",
REGION+"l03", "southeast",
"Inside a dark maze",
"Inside a dark maze.\n",
0 )

init() {
   ::init();
   add_action( "northwest", "northwest" );
   add_action( "northwest", "nw" );
}

northwest(arg) {
	if (present("griffin")) {
		write("The griffin won't let you go to the northwest.\n");
	}
	else move("northwest");
	return 1;
}

extra_reset(arg) {
	if (!griffin) {
		griffin= clone_object("players/qclxxiv/griffin");
		move_object(griffin, this_object());
	}
   if (arg) return;
    set_nodig(1);
   /* 
   items = ({
       "street" , "Just a bumpy old bricked street",
   });
   */ 
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
