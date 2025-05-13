
/* ################################################################
   #								  #
   #    		Mage Haste                                #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev > 25) return 2;
   return 3;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "haste" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'haste' [target]" );
   set_guild_allowed( 5, 17 );
   set_save_vs( NO_SAVE );
   set_cost( 100 );
   set_player_help(
"The target starts to move at double speed, capable of attacking twice as\n"+
"often as normal per round.\n"+
"But beware .. It is said that there are some ill effects if u cast this spell\n"+
"too often on the same creature.");
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
       if(oppo->shad_id("haste"))
       {
	  write("Nothing seems to happen.\n");
       }
       else
       {
	  tell_object( oppo, "You start moving faster!\n");
          say(oppo->query_name_true()+" starts moving faster.\n",oppo,
              oppo,"");
	  sh=clone_object("/spells/no_combat/haste/haste_shad");
          sh->start_shadow(oppo, 60 + 6*TPL);
       };
   }
}
