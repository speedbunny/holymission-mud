
/* ################################################################
   #								  #
   #    		Mage fear spell                           #
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

   set_name( "fear" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'fear' <enemy>" );
   set_save_vs( MINDEFFECTIVE );
   set_save_vs_info( "for negation" );
   set_guild_allowed( 5, 12 );
   set_cost( 60 );
   set_player_help(
"The specified victim will be caused to flee from you if the spell is\n"+
"successful.");
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
            write(oppo_name+" laughs at your attempt to fear him.\n");
            say(TPNT+" tried to fear "+oppo_name+" but failed.\n",oppo,TP,"");
            tell_object(oppo,TPNT+" tries to fear you. BOOO\n"); 
            oppo->attacked_by(TP);
            break; 
         case SAVED:
            write(
                oppo_name+" seems scared for a moment but then turns angry.\n");
            tell_object(oppo,
               "You feel a deep fear crawling up your back\n"+
               "but then you manage to push it away.\n");
            say(TPNT+" tried to fear "+oppo_name+" but failed.\n",oppo,TP,"");
            oppo->attacked_by(TP);
            break;
         case SAVE_FAILED:
            write(oppo_name+" cries out in panic.\n");
            say(oppo_name+" cries out in panic.\n",oppo);
            tell_object(oppo,
               "You feel an overwhelming fear, urging you to RUN!\n");
            oppo->run_away();
            if(present(TP,environment(oppo)))
            {
               write(oppo_name+" seems to be cornered and attacks!\n");
               say(oppo_name+" seems to be cornered and attacks!\n",oppo);
               tell_object(oppo,"It seems you just can't flee! .. BANZAI\n");
            }
            oppo->attacked_by(TP);
            break;
         default:;
      }
   }
}
