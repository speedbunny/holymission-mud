
/* matilda */

inherit "obj/npc";
#include "../defs.h"

void reset(int tick)
{
   ::reset( tick );

   if (tick) 
       return;

   set_race( "undead" ) ;
   set_name( "matilda" );
   set_level( 18 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "You see a ghostly appearance of a fat female dressed like a cook !\n");
   set_gender( 2 );
   set_al( -90 );
   set_aggressive(1);
   add_money( 300 );
   CO("kitchen_knife");
   init_command("wield knife");
   set_attacks(2);
   set_attacks_change(30);
}

int infravision()
{
   return( 1 );
}

