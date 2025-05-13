
/* ################################################################
   #								  #
   #    		Mage calm spell                           #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
    if(lev > 25) return 0;
    if(lev > 20) return 1;
    if(lev > 15) return 2;
    return 3;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "calm" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'calm' <enemy>" );
   set_save_vs( MINDEFFECTIVE );
   set_save_vs_info( "for negation" );
   set_guild_allowed( 5, 11 );
   set_cost( 80 );
   set_player_help(
"The specified victim will be calmed and will stop attacking you.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo;
   string oppo_name;

   oppo = check_target( arg );
   if ( !oppo ) {
      return;
   }
   if ( !valid_living( oppo ) ) {
      return;
   }

   oppo_name = apply( call, oppo, "query_name" );

   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
         case IMMUNE:
            write("You could not calm "+oppo_name+".\n");
            say(TPNT+" tried to calm "+oppo_name+" but failed.\n",oppo,TP,"");
            tell_object(oppo,TPNT+" stupidly tried to calm you. Good joke!\n"); 
            oppo->attacked_by(TP);
            break; 
         case SAVED:
            write(
                oppo_name+" looks puzzled for a moment but then recovers "+
                oppo->query_possessive()+" wits.\n");
            tell_object(oppo,
                "You feel dizzy for a moment, but it fades away quickly.\n");
            say(TPNT+" tried to calm "+oppo_name+" but failed.\n",oppo,TP,"");
            oppo->attacked_by(TP);
            break;
         case SAVE_FAILED:
            write(oppo_name+" looks around with a puzzled expression.\n");
            say(oppo_name+" looks arround with a puzzled expression.\n",oppo);
            tell_object(oppo, "Suddenly you feel very peaceful!\n");
	    oppo->stop_fight();
	    oppo->stop_fight();
	    oppo->stop_hunter(1);
	    oppo->set_tame(TP);

	    TP->stop_fight();
	    TP->stop_fight();
	    TP->stop_hunter(1);
            break;
         default:;
      }
   }
}
