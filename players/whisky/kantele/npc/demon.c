
/* demon */

inherit "obj/npc";
#include "../defs.h"

void reset(int tick)
{
   ::reset( tick );

   if (tick) 
       return;

   set_race( "demon" ) ;
   set_name( "household demon" );
   set_alt_name("demon");
   set_level( 25 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "You see a grey skinned creature with a head like an octopus.\n"+
   "This creature has no eyes but tentacles everywhere. On it's \n"+
   "arms and legs it has big red claws.\n");
   set_gender( 0 );
   set_n_wc(30);
   set_al( 0 );
   set_aggressive(1);
   set_attacks(3);
   set_attacks_change(100);
}

int infravision()
{
   return( 1 );
}

int detect_invis()
{
   return 1;
}
