
/* ################################################################
   #								  #
   #    		Mage Shield                               #
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

   set_name( "shield" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'shield' [target]" );
   set_guild_allowed( 5, 1 );
   set_save_vs( NO_SAVE );
   set_cost( 30 );
   set_player_help(
"This spell create a shield of magic around the target. It offers some\n"+
"protection, and nullifies all magic missile attacks.");
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
       if(oppo->shad_id("shield"))
       {
	  write("Nothing seems to happen.\n");
       }
       else
       {
	  tell_object( oppo, TPN+" surrounds you with a strong forcefield!\n");
	  sh=clone_object("/spells/no_combat/shield/shield_shad");
	  sh->start_shadow(oppo,60+TPL*3*(TP->query_wis()/3));
       };
   }
}
