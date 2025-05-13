
/* ################################################################
   #								  #
   #    		Mage Armor                                #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev > 21) return 0;
   return 1;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "armor" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'armor' [target]" );
   set_guild_allowed( 5, 3 );
   set_save_vs( NO_SAVE );
   set_cost( 40 );
   set_player_help(
"This spell calls forth some magic protection on the target, making it harder\n"+
"to hit.");
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
       if(oppo->shad_id("armor"))
       {
	  write("Nothing seems to happen.\n");
       }
       else
       {
	  tell_object( oppo, "You feel someone protecting you!\n");
	  sh=clone_object("/spells/no_combat/armor/armor_shad");
	  sh->start_shadow(oppo,60+TPL*3*(TP->query_wis()/3));
       };
   }
}
