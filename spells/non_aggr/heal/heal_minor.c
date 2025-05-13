/***************************************************
 *               druid/cleric spells               *
 *               (c) Sourcer 1995                  *
 ***************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "heal minor" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'heal minor' [target]" );
   set_save_vs( NO_SAVE );
   set_guild_allowed(2,23);
   set_cost( 100 );
   set_duration_info( "next heartbeat" );
   set_speed( 2 );
   set_player_help(
      "A powerful healing spell.\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it,cure;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;


   if ( check_success( act_skill, max_skill ) ) {
         do_it = 1;
      }

      oppo_name = oppo->query_name( );
      tp_name = TP->query_name( );

      if ( do_it ) 
	{
		cure=roll_dice(10,40,50);
		if(cure > TP->query_max_hp()-TP->query_hp())
			cure=TP->query_max_hp()-TP->query_hp();
		oppo->reduce_hit_point(-cure);
		tell_object(oppo,"You feel really GOOD!.\n");
		if(TP!=oppo) write(capitalize(oppo_name)+" feels really GOOD!.\n");
		say(oppo_name+" feels really GOOD!.\n");
		TP->set_al(TP->query_alignment()+4);
	}
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,"You feel unaffected.\n" );
      }         
// }    removed since did not match anything
}
