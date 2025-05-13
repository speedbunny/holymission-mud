
/* ################################################################
   #								  #
   #    		Mage Stoneskin                            #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev > 21) return 2;
   return 3;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "stoneskin" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'stoneskin' [self]" );
   set_guild_allowed( 5, 10 );
   set_save_vs( NO_SAVE );
   set_cost( 100 );
   set_player_help(
"This spell makes your skin hard as stone, though it will work as an\n"+
"armour in your favour.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, sh;
   string oppo_name;

   oppo = TP;
   oppo_name = apply( call, oppo, "query_name" );

   if ( check_success( act_skill, max_skill ) )
   {
       write("Ok.\n");
       if(oppo->shad_id("stoneskin"))
       {
	  write("Nothing seems to happen.\n");
       }
       else
       {
          tell_object(oppo,"Your skin seems to harden!\n");
	  sh=clone_object("/spells/no_combat/stoneskin/stoneskin_shad");
          sh->start_shadow(oppo,  300 + TPL * 30);
       };
   }
}
