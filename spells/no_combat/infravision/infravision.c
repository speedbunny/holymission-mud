
/* ################################################################
   #								  #
   #    		Mage Infravision                          #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   return 2;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "infravision" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'infravision' [target]" );
   set_guild_allowed( 5, 7 );
   set_save_vs( NO_SAVE );
   set_cost( 40 );
   set_player_help("This spell allows you to see in the dark.");
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
       tell_object( oppo, "Your eyes glow blue.\n");
       say(oppo->query_name_true()+"'s eyes glow blue.\n",oppo,oppo,"");
       sh=clone_object("/spells/no_combat/infravision/infravision_shad");
       sh->start_shadow(oppo, TPL * 2 * 60);
   }
}
