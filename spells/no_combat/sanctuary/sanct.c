/*************************************************
 *      druid spell                              *
 *      (c)  Sourcer 1995                        *
 *************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "sanctuary" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'sanctuary'" );
   set_save_vs( NO_SAVE );
   set_guild_allowed(2,30);
   set_cost( 55 );
   set_duration_info( "level*2+60" );
   set_speed( 2 );
   set_player_help(
	"The spell has been temporary disabled\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it,level;

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

      if ( do_it ) {
		level=TP->query_level()+TP->query_legend_level();
		shad = clone_object("/spells/no_combat/sanctuary/sanct_shad");
		shad->start_shadow(TP,level);
         write( capitalize(oppo_name) + " has a holy aura.\n" );
         tell_object( oppo,"You get a holy feeling\n");
      }
      else {
         write(capitalize(oppo_name)+" seems to be uneffected by the spell.\n");
         tell_object( oppo,"You feel uneffected\n" );
      }         
   }
}
