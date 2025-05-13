
/* ################################################################
   #								  #
   #    		Mage True Sight                           #
   #                                          		          #
   ###############################################(C) Llort######## */
/* druid too */

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

   set_name( "true sight" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'true sight' [target]" );
   set_guild_allowed( 5, 25 );
   set_save_vs( NO_SAVE );
   set_cost( 80 );
   set_player_help(
"True sight allowes you to see hidden and invisible creatures, and allows\n"+
"you to see in the dark.");
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
       tell_object( oppo, "Your eyes glow silver.\n");
       sh=clone_object("/spells/no_combat/true_sight/true_sight_shad");
       sh->start_shadow(oppo, TPL * 1 * (this_player()->query_wis()));
   }
}
