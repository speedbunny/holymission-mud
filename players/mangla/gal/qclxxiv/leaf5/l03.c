/* l03 */
#include "/players/qclxxiv/leaf5/leaf5room.h"
object herb;
object rat;

TWO_EXIT( REGION+"l03b", "northwest",
HOME+"circular/circ5", "southeast",
"Inside a dark maze",
"Inside a dark maze. On the wall is written: Beware!!! griffin to northwest!\n",
0 )

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
