/* h01 */
#include "/players/qclxxiv/leaf5/leaf5room.h"
#include "/players/qclxxiv/door.h"
object obj_1, obj_2;

ONE_EXIT( /* REGION+"q01", "south", */
REGION+"h02", "southeast",
"Inside a dark maze",
"Inside a dark maze.\n",
0 )

/*
init() {
   ::init();
	add_action( "south", "south" ); 
	add_action( "do_get", "get" ); 
}
*/

extra_reset(arg) {
   if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf5/h01","south","players/qclxxiv/leaf5/q01","north","copper","q01","An old oaken door, on it is engraved: *ooo.\n",1,0,1)
	/* obj_1->set_invisible(1); */
    set_nodig(1);
   items = ({
		"lock", "A solid greenish lock, apparently old copper",
		"hinges", "Solid greenish hinges, apparently old copper",
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
