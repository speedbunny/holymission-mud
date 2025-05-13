inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "paralyze" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'paralyze' [opponent]" );
   set_save_vs( PETRIFICATION );
   set_save_vs_info( "for negation" );
   set_cost( 200 );
   set_duration_info( "10 rounds" );
   set_speed( 2 );
   set_guild_allowed( 8, 31 );
   set_player_help(
      "This spell will paralyze your opponent !" 
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
         write( capitalize(oppo_name) + " is PARALYZED !!!\n" );
         say( tp_name+" PARALYZES "+oppo_name+" !!!\n", oppo );
         tell_object( oppo,"You feel a numbness creeping through your bones,\n"+
                           "leaving you PARALYZED !!!\n" );
         shad = clone_object( "/spells/aggr/paralyze/paralyze_shad" );
         if ( shad ) {
            if ( TP->query_real_name() == "patience" )
               shad->start_shadow( oppo, 1000000 );
            else
               shad->start_shadow( oppo, 20 );
            shad->set_paralyzer( TP );
         }
         else
            write( "But something has gone wrong !\n" );
      }
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,"You feel a numbness creeping through your bones,\n"+
                           "but the effect fades ...\n" );
      }         
   }
}
