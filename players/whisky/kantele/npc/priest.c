
/* priest */

inherit "obj/monster";
#include "../defs.h"
object shad;

reset(arg)
{
   object pot;

   ::reset( arg );
   
   if ( arg )
      return;

   set_race( "human" ) ;
   set_name( "evil cleric" );
   set_alias( "cleric" );
   set_level( 30 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "You see a female humanoid, which is looking evil and wraped\n"+
   "in a black robe.\n");
   set_gender( 2 );
   set_ep( 3000000 );
   set_al( -500 );
   add_money( 15000 );
   set_aggressive( 1 );
   set_number_of_arms( 1 );
   set_n_wc( 15 );
   set_int(50);
   shad = clone_object("/obj/shadows/sanct_shad");
   shad->start_shadow(this_object(),0);
   shad = clone_object("/obj/shadows/free_action_shad");
   shad->start_shadow(this_object(),0);

   change_spell( "slay living", 95, 95, 6 );
   change_spell( "paralyze", 95, 95, 5 );

   pot = clone_object( "/players/whisky/obj/hearo_potion" );
   transfer( pot, this_object() );
   CO("hook");
}

int detect_invis()
{
   return( 1 );
}

int infravision()
{
   return( 1 );
}


int cast_spell( object vic )
{
   int rnd;

/*
   if ( !query_casting() ) 
   {
 */
      rnd = random( 100 );
      if ( rnd < 3 )
         npc_process_spell( "slay living", vic );
      else if (rnd < 15) 
         npc_process_spell( "paralyze", vic );
/*
   }
*/
   return( 1 );
}


