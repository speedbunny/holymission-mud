/* l19 */
#include "/players/qclxxiv/leaf5/leaf5room.h"
object rat;
object herb;
query_qnewbie() { return 1; }
TWO_EXIT( REGION+"l22", "northwest",
REGION+"l20", "west",
"Inside a dark maze",
"Inside a dark maze. Carved into the wall: Q = * !!!\n",
0 )

   /* 
init() {
   ::init();
   add_action( "do_get", "get" );
}
   */ 

extra_reset(arg) {
	PLACE_IN_THIS(rat,REGION+"rat");
	if (random(5)==3) {
			FRESH_IN_THIS(herb, REGION+"ironweed");	
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
