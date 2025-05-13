
/* ################################################################
   #								  #
   #    		Mage Scry spell                           #
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

   set_name( "scry" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'scry' [target]" );
   set_guild_allowed( 5, 10 );
   set_save_vs( NO_SAVE );
   set_cost( 100 );
   set_player_help("This spell allowes you to see into a adjective room.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, sh;
   string oppo_name;

   if(!arg) oppo = TP;
   else oppo = check_target( arg );
   if ( !oppo ) {
      return;
   }
   if ( !valid_living( oppo ) ) {
      return;
   }

   oppo_name = apply( call, oppo, "query_name" );

   if ( check_success( act_skill, max_skill ) )
   {
       write("Ok.\n");
       tell_object( oppo, "Your eyes start glowing green.\n");
       say(oppo->query_name_true()+"'s eyes start glowing green.\n",
           oppo,oppo,"");
       sh=clone_object("/spells/no_combat/scry/scry_shad");
       sh->start_shadow(oppo,TPL*60);
   }
}
