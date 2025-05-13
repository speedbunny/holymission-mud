/**********************************************************
 *          druid/cleric spell                            *
 *          (c) Sourcer 1995                              *
 **********************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "protection from cold" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'protection from cold' [target]" );
   set_save_vs( NO_SAVE );
   set_cost( 70  );
	set_guild_allowed(2,14);
   set_speed( 1 );
   set_player_help(
	"You become nearly invulnerable to damage from cold."
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it,time;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;


   if ( check_success( act_skill, max_skill ) ) {

      oppo_name = apply( call, oppo, "query_name" );
      tp_name = apply( call, TP, "query_name" );

    time=(TP->query_level()+TP->query_legend_level())*2+50;
    shad = clone_object("/spells/non_aggr/protection/cold");
    shad->start_shadow(oppo,time);
    if(TP!=oppo) write(oppo_name+" is protected from cold.\n");
    say(oppo_name+" shimmers white for a second.\n",oppo);
    tell_object(oppo,"You are protected from cold.\n");
   }
}
