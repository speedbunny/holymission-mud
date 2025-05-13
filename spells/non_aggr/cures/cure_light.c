/**************************************************
 *        druid/cleric spell                      *
 *        (c) Sourcer 1995                        *
 **************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"
#include "/players/sourcer/guild/druid.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "cure light" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'cure light' [target]" );
   set_save_vs( NO_SAVE );
	set_guild_allowed(2,1);
   set_cost( 30 );
   set_duration_info( "next heartbeat" );
   set_speed( 0 );
   set_player_help(
      "A minor cure spell.\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it,cure,level;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;


   if ( check_success( act_skill, max_skill ) ) {
		do_it = 1;
      }
      oppo_name =  oppo->query_name();
      tp_name = TP->query_name();

      if ( do_it ) 
	{
        cure = roll_dice(2,40,TP->query_level());
        if(oppo->query_max_hp()-oppo->query_hp() < cure)
		{
			tell_object(oppo,"You are totally healed.\n");
            cure=oppo->query_max_hp()-oppo->query_hp();
		  if(TP != oppo) 
			    write(capitalize(oppo_name)+" is totally healed.\n");
			say(capitalize(oppo_name)+" is totally healed.\n",oppo);
		}
		else
		{
			tell_object(oppo,"You feel a bit better.\n");
			if(TP != oppo) write(capitalize(oppo_name)+" feels a bit better.\n");
		  say(oppo_name+" feels a bit better.\n",oppo);
		}
		oppo->reduce_hit_point(-cure);
		TP->set_al(TP->query_alignment()+1);
	}
}
