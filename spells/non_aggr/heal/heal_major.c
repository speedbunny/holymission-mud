/********************************************************
 *             druid/cleric   spell                     *
 *             (c) Sourcer 1995                         *
 ********************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"
#include "/players/sourcer/guild/druid.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "heal major" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'heal major' [target]" );
   set_save_vs( NO_SAVE );
   set_guild_allowed(2,29);
   set_cost( 200 );
   set_duration_info( "instant" );
   set_speed( 3 );
   set_player_help(
      "This spell totally restores the target.\n"
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

      oppo_name =  oppo->query_name( );
      tp_name = TP->query_name( );

      if ( do_it ) 
	{
		cure=oppo->query_max_hp() - oppo->query_hp();
		oppo->reduce_hit_point(-cure);
		tell_object(oppo,"You are totally healed.\n");
		if(TP!=oppo) write(capitalize(oppo_name)+" is totally healed.\n");
		say(oppo_name+" is healed by "+tp_name+".\n");
		TP->set_al(TP->query_alignment()+5);
	}
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,"You feel unaffected.\n" );
      }         
}
