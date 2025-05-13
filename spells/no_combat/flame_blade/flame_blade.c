/*******************************************************
 *        druid  spell                                 *
 *        (c) Sourcer 1995                             *
 *******************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"
#include "/players/sourcer/guild/druid.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "flameblade" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'flameblade' [self]" );
   set_save_vs( NO_SAVE );
	set_guild_allowed(2,10);
   set_cost( FLAME_B );
   set_duration_info( "level*10+20 rounds" );
   set_speed( 1 );
   set_player_help(
      "Creats a flaming blade\n."
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo,weap;
   string oppo_name, tp_name;
   int    do_it;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;


   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
         case IMMUNE:      do_it = 0; break;
         case SAVED:       do_it = 0; break;
         case SAVE_FAILED: do_it = 1; break;
         default:          do_it = 1;
      }

      oppo_name = apply( call, oppo, "query_name" );
      tp_name = apply( call, TP, "query_name" );

      if ( do_it ) 
	{
		if(apply(call,TP,"query_wielded"))
		{
		write("As you are already wielding a weapon the spell fizzles.\n");
		say("A blade made of fire appears in the air but vanishes instantly.\n");
		}
		else
		{
		say(capitalize(tp_name)+" grabs a flaming sword from the air!\n");
		write("You create a flameblade.\n");
		weap=clone_object("/spells/no_combat/flame_blade/flameblade");
        transfer(weap,TP);
        weap->set_level(TP->query_level()+TP->query_legend_level());
		}
	}
      else {
         write(capitalize(oppo_name)+" seems to be uneffected by the spell.\n");
         tell_object( oppo,"You feel uneffected\n" );
      }         
   }
}
