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

   set_name( "tree travel" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'tree travel' [target]" );
   set_save_vs( NO_SAVE );
	set_guild_allowed(2,1);
   set_cost( 20 );
   set_duration_info( "10 rounds" );
   set_speed( 0 );
   set_player_help(
      "This spell enables the living to walk through tree."
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

      if ( do_it ) {
         write( capitalize(oppo_name) + " shimmers green for a moment.\n" );
         tell_object( oppo,"You feel groovy!\n");
         shad = clone_object( "/spells/no_combat/tree_travel/travel_shad" );
         if ( shad ) {
            shad->start_shadow( oppo, (apply(call,TP,"query_level")*2+20) );
         }
         else
            write( "But something has gone wrong !\n" );
      }
      else {
         write(capitalize(oppo_name)+" seems to be uneffected by the spell.\n");
         tell_object( oppo,"You feel uneffected\n" );
      }         
   }
}
