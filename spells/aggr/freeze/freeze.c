inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "freeze" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'freeze' [opponent]" );
   set_save_vs( PETRIFICATION );
   set_save_vs_info( "for negation" );
   set_cost( 150 );
   set_duration_info( "variable, see below" );
   set_speed( 2 );
   set_guild_allowed( 8, 25 );
   set_player_help(
      "If this spell is successfully cast your opponent will turn into\n"+
      "a statue of ice. Your victim will be unable to move. The duration of the\n"+
      "spell depends on the strength of your victim."
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
         write( capitalize(oppo_name) + " is FROZEN !!!\n" );
         say( tp_name+" FREEZES "+oppo_name+" !!!\n", oppo );
         tell_object( oppo,"You feel a chill creeping through your bones,\n"+
                           "turning you into a STATUE OF ICE !!!\n" );
         shad = clone_object( "/spells/aggr/freeze/freeze_shad" );
         if ( shad )
            shad->start_shadow( oppo, 0 );
         else
            write( "But something has gone wrong !\n" );
      }
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,"You feel a chill creeping through your bones,\n"+
                           "but the effect fades ...\n" );
      }         
   }

   if ( oppo->query_npc() )
      oppo->attack_object( TP );
}
