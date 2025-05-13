/*
 * druid spell
 * (c) sourcer
 */

inherit "/spells/spell";
#include "/spells/spell.h"


void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "summon" );
   set_kind( NON_AGGRESSIVE );
   set_guild_allowed(2,5);
   set_syntax( "cast 'summon' <target>" );
/*   set_guild_allowed(2,7); */
   set_guild_allowed(2,30);
   set_save_vs( NO_SAVE );
   set_cost( 80 );
   set_speed(0);
   set_player_help(
"This spell has been disabled!\n"
);
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, sh,mob;
   string oppo_name;

   oppo = check_target( arg );
   if ( !oppo ) {
      return;
   }
   if ( !valid_living( oppo ) ) {
      return;
   }

   oppo_name = apply( call, oppo, "query_name" );

   if ( check_success( act_skill, max_skill ) )
   {
		mob=clone_object("/players/sourcer/guild/mobs/minor_fire");
		mob->set_owner(TP);
		move_object(mob,environment(this_player()));
		mob->wellcome(this_player());
		mob->set_stay_time(this_player()->query_level()*4+100);
		TP->add_follower(mob,0);
   }
}
