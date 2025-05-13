
/* kitiara */

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
   set_name( "kitiara" );
   set_alias( "witch" );
   set_level( 80 );
   set_size( 3 );
   set_short( "kitiara the witch" );
   set_long(
   "You see a female humanoid. On her finger she has long black nails\n"+
   "Her lips are purple red and her eyes glow green.\n");
   set_gender( 2 );
   set_ep( 15000000 );
   set_al( -5000 );
   add_money( 20000 );
   set_aggressive( 1 );
   set_number_of_arms( 2 );
   set_n_wc( 30 );
   set_int(120);
   set_no_steal();
   shad = clone_object("/obj/shadows/fireshield_shad");
   shad->start_shadow(this_object(),0);
   shad = clone_object("/obj/shadows/free_action_shad");
   shad->start_shadow(this_object(),0);

   change_spell( "fireball", 95, 95, 2);
   change_spell( "paralyze", 95, 95, 5 );

   pot = clone_object( "/players/whisky/obj/hearo_potion" );
   transfer( pot, this_object() );
   pot = clone_object( "/players/whisky/obj/firesh_scroll" );
   transfer( pot, this_object() );
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

   if ( !query_concentrating() )
   {
      rnd = random( 100 );
      if ( rnd < 25 )
         npc_process_spell( "fireball", vic );
      else if (rnd < 30) 
         npc_process_spell( "paralyze", vic );
   }
   return( 1 );
}


