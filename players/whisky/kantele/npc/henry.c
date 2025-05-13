
/* henry */

inherit "obj/npc";
#include "../defs.h"

void reset(int tick)
{
   ::reset( tick );

   if (tick) 
       return;

   set_race( "undead" ) ;
   set_name( "henry" );
   set_level( 12 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "Henry the ghostly butler is here !\n");
   set_gender( 0 );
   set_al( -10 );
   add_money( 500 );
   set_n_wc( 8 );
   CO("key1");
   set_dodge(15);
   set_attacks(1);
   set_attacks_change(20);
}

int infravision()
{
   return( 1 );
}

