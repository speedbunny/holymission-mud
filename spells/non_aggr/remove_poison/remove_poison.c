/**********************************************************
 *          druid/cleric spell                            *
 *          (c) Sourcer 1995                              *
 **********************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"

/* SOMEONE had the pleasure to change the ammount to cure 
   1 Poison... ridiculous.
   Would you please be so kind to leave a note IF you have
   to change anything!!  #sourcer#
*/

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "remove poison" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'remove poison' [target]" );
   set_save_vs( NO_SAVE );
   set_cost( 70  );
	set_guild_allowed(2,9);
   set_duration_info( "instant" );
   set_speed( 1 );
   set_player_help(
      "This spell partially cures poison.\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it,poison;

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
		if(poison=oppo->query_poisoned())
		{
			write("You partially cure the effects of poison on "+oppo_name+".\n");
			tell_object(oppo,"You don't feel so poisoned anymore.\n");
			apply(call,oppo,"add_poison",-100);
		}
		else write(capitalize(oppo_name)+" is not poisoned.\n");
	}
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,"You feel unaffected.\n" );
      }         
   }
}
