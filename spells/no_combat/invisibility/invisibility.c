
/* ################################################################
   #								  #
   #    		Mage Invisibility                         #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev > 25) return -1;
   return 0;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "invisibility" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'invisibility' [target]" );
   set_guild_allowed( 5, 4 );
   set_save_vs( NO_SAVE );
   set_cost( 40 );
   set_player_help(
"This Illusion makes you invisible to normal livings for an hour.\n"+
"\nNote: you can use the 'visible' command to turn visible before!");
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
       if(oppo->query_invis())
       {
	  write("Nothing seems to happen.\n");
       }
       else
       {
	  tell_object( oppo, "You vanish!\n");
          say(oppo->query_name_true()+" fades out of sight!\n",oppo,oppo,"");
	  sh=clone_object("/spells/no_combat/invisibility/invis_shad");
          sh->start_shadow(oppo, 600);
       };
   }
}
