
/* ################################################################
   #								  #
   #    		  Mage stength                            #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev) { return 2; }

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "strength" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'strength' [target]" );
   set_guild_allowed( 5, 7 );
   set_save_vs( NO_SAVE );
   set_cost( 60 );
   set_player_help(
"The target will increase in strength. The increment depends on the strength\n"+
"of the target and the level of the caster.");
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
       if(oppo->shad_id("strength"))
       {
	  write("Nothing seems to happen.\n");
       }
       else
       {
          tell_object( oppo, "You feel stronger now!\n");
	  sh=clone_object("/spells/no_combat/strength/strength_shad");
          sh->start_shadow(oppo, TPL * 45);
       };
   }
}
