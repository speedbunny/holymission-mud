/*
 * druid spell entangle
 * it's a pity there is no diference btween indoor and outdoor
 * so i can't limit the spell to outdoor use
 * (c) sourcer
 */


inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "entangle" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'entangle' [opponent]" );
   set_save_vs( PETRIFICATION );
   set_save_vs_info( "for negation" );
   set_cost( 60 );
   set_duration_info( "variable, see below" );
   set_speed( 2 );
   set_guild_allowed( 2, 15 );
   set_player_help(
	"The spell calls upon the power of the earth and the plants.\n"+
        "All the plants in the room will grow very fast and try to\n"+
	"get a grip on the target which they can render immobile for\n"+
	"quite some time.\n"
   );
}

void release( string arg, int act_skill, int max_skill )
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
		 write("As you speak the words of power the ground opens and\n"+
			"some huge vines grab "+oppo_name+".\n\n");
		 say("\nThe ground opens and some huge vines grab "+oppo_name+
			"!.\n\n",oppo);
		 tell_object(oppo,
			"\nYou are squeezed by giant vines and can't move!\n");
         shad = clone_object( "/spells/aggr/entangle/entangle_shad" );
         if ( shad )
            shad->start_shadow( oppo, (TP->query_level()+5) );
         else
            write( "But something has gone wrong !\n" );
      }
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,"You feel some vines trying to grab you but you "+
                           "manage to evade them.\n" );
      }         
   }
   oppo->attack_object( TP );
}
