/* h02 */
#include "/players/qclxxiv/leaf5/leaf5room.h"
#include "/players/qclxxiv/door.h"
object obj_1, obj_2;

TWO_EXIT( REGION+"h01", "northwest",
REGION+"h03", "southeast",
"Inside a dark maze",
"Inside a dark maze.\n",
0 )

   /* 
init() {
   ::init();
   add_action( "do_get", "get" );
}
   */ 

extra_reset(arg) {
   if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf5/h02","south","players/qclxxiv/leaf5/q02","north","copper","q02","An old oaken door, on it is engraved: *!oom&&.\n",1,0,1)
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
