/* l30 */
#include "/players/qclxxiv/leaf5/leaf5room.h"
object hugerat;
object herb;
query_qnewbie() { return 1; }
FOUR_EXIT( REGION+"l33", "north",
REGION+"l35", "northwest",
REGION+"l27", "southeast",
REGION+"l29", "southwest",
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
