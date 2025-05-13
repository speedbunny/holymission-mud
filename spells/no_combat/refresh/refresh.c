/*********************************************************+
 *              druid spell                               *
 *              (c) Sourcer 1995                          *
 **********************************************************/

/*
 * restores leveld5+20 fp at a cost of 50
 */

inherit "/spells/spell";
#include "/spells/spell.h"


void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "refresh" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'refresh' [target]" );
   set_save_vs( NO_SAVE );
   set_guild_allowed(2,5);
   set_cost( 40 );
   set_duration_info( "instant" );
   set_speed( 1 );
   set_player_help(
	"You can restore a targets fatigue points with this spell."
   );
}

void release( string arg, int act_skill, int max_skill )
{
   object oppo;
   string oppo_name, tp_name;
   int    fp;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   if ( check_success( act_skill, max_skill ) ) 
	{
      oppo_name =  oppo->query_name( );
      tp_name = TP->query_name( );

	fp = roll_dice(5,TP->query_level(),20);
	if(fp > oppo->query_max_fp()-oppo->query_fp())
	{
		tell_object(oppo,"You are totally refreshed.\n");
		fp = oppo->query_max_fp()-oppo->query_fp();
		if(TP != oppo) write(capitalize(oppo_name)+" is totally refreshed.\n");
		say(capitalize(oppo_name)+" is totally refreshed.\n",oppo);
	}
	else
	{
		tell_object(oppo,"You are refreshed.\n");
		if(TP != oppo) write(capitalize(oppo_name)+" is somewhat refreshed.\n");
		say(capitalize(oppo_name)+" is somewhat refreshed.\n",oppo);
	}
	oppo->reduce_fatigue_points(-fp);
  }
}
