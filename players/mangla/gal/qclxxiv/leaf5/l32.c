/* l32 */
#include "/players/qclxxiv/leaf5/leaf5room.h"
object herb;
object rat;
query_qnewbie() { return 1; }
FOUR_EXIT( REGION+"l36", "northwest",
REGION+"l31", "southwest",
REGION+"l28", "southeast",
REGION+"l33", "northeast",
"Inside a dark maze",
"Inside a dark maze. Someone has written on a wall: THIS IS SERIOUS!!!!\n"
+"DON'T ENTER Q's ROOMS, UNLESS YOU KNOW WHAT'S IN IT AND HOW TO PREPARE!!!!\n",
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
