
/* snake */

inherit "obj/monster";
#include "../defs.h"

void reset(int tick)
{
   ::reset( tick );

   if (tick) 
       return;

   set_race( "snake" ) ;
   set_name( "slittering snake" );
   set_alt_name( "snake" );
   set_level( 13 );
   set_size( 4 );
   set_short( query_name() );
   set_long(
   "You see a long red, green striped snake, crawling towards you.\n"); 
   set_spell_mess1("The snake winds itself !\n");
   set_spell_mess2("The snake chokes your neck !\n");
   set_spell_dam(30 + random(50));
   set_chance(20);
   set_gender( 0 );
   set_al( 0 );
   set_n_wc(18);
   set_aggressive(1);
}

int infravision()
{
   return( 1 );
}

int detect_invis()
{
   return 1;
}
