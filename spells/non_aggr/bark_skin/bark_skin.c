/***********************************************************
 *                 druid spell                             *
 *                 (c) Sourcer 1995                        *
 ***********************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"
#include "/players/sourcer/guild/druid.h"

int level;

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "barkskin" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'barkskin' [self]" );
   set_save_vs( NO_SAVE );
   set_cost( 50 );
	set_guild_allowed(2,4);
   set_duration_info( "level*3 + 40 rounds" );
   set_speed( 2 );
   set_player_help(
      "Covers your skin with a bark-like substance.\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
         case IMMUNE:      do_it = 0; break;
         case SAVED:       do_it = 0; break;
         case SAVE_FAILED: do_it = 1; break;
         default:          do_it = 1;
      }

      oppo_name = apply( call, oppo, "query_name" );
      tp_name = apply( call, TP, "query_name" );

      if ( do_it ) 
	{
		level = apply(call,TP,"query_level");
		write("Your skin transforms into a strong dark bark.\n");
		say(capitalize(tp_name)+"'s skin covers with bark.\n");
		shad = clone_object("/spells/non_aggr/bark_skin/bark_shad");
		apply(call,shad,"start_shadow",TP,(level*5+40)*2,level);
	}
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,"You feel unaffected.\n" );
      }         
   }
}
