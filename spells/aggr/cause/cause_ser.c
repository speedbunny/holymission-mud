/*********************************************************
 *                 druid spell                           *
 *                 (c) Sourcer 1995                      *
 *********************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"
#include "/players/sourcer/guild/druid.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "cause serious" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'cause serious' [target]" );
   set_save_vs( TOUCH );
   set_cost( 50 );
   set_guild_allowed(2,9);
   set_duration_info( "next heartbeat" );
   set_speed( 1 );
   set_player_help(
      "Causes moderate damage if the victim is touched."
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it,dam,lev;

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

      oppo_name = oppo->query_name( );
      tp_name = TP->query_name( );

      if ( do_it ) 
	{
		lev = TP->query_level();
		dam = roll_dice(4,40,lev);
		if(dam > oppo->query_hp())
        {
             tell_object(TP,"\nYour touch makes "+oppo_name+" shiver so badly"+
                " that "+oppo->query_pronoun()+" collapses \ninto a lifeless"+
                " heap.          Don't you feel ASHAMED? \n");
        }
        else tell_object(TP,"\nYour touch makes "+oppo_name+" shiver .\n");
		tell_object(oppo,capitalize(tp_name)+
		"'s touch sends pain through your bones.\n");
		oppo->hit_by_spell(dam);
        WINFO("Damage by cause serious: "+dam);
	}
      else {
         write("You MISSED "+oppo_name+" with your touch.\n");
         tell_object( oppo,capitalize(tp_name)+" missed you with his touch.\n");
		oppo->attack_object(TP);
      }         
   }
}
