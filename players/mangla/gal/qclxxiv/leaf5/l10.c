/* l10 */
#include "/players/qclxxiv/leaf5/leaf5room.h"
object herb;
object hugerat;
query_qnewbie() { return 1; }
THREE_EXIT( REGION+"l12", "west",
REGION+"l07", "south",
REGION+"l05", "southeast",
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
	PLACE_IN_THIS(hugerat,REGION+"hugerat");
	FRESH_IN_THIS(herb, REGION+"ironweed");	
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
