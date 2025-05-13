inherit "/spells/spell";
#include "/spells/spell.h"
#include "/players/sourcer/guild/druid.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "heat armor" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'heat armor' [target]" );
   set_save_vs( MAGIC );
	set_guild_allowed(2,11);
   set_cost( HEAT_A );
   set_duration_info( "level/5 rounds +3" );
   set_speed( 2 );
   set_player_help(
      "Heats the armor of the target intensely which results in some damage.\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad, *armor1, *armor2,target;
   string oppo_name, tp_name;
   int    do_it,i,level;

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
		armor2 = ({ });
		armor1 = apply(call,oppo,"query_armour");
		for(i=sizeof(armor1)-1;i>=0;i--)
			if(objectp(armor1[i]) && !apply(call,armor1[i],"id","soul"))
				armor2 += ({ armor1[i] }) ;
		i = sizeof(armor2);
		if(i)
		{
			target = armor2[random(i)];
			level = apply(call,TP,"query_level");
			shad = clone_object("spells/aggr/heat_armor/heat_a_shad");
			apply(call,shad,"set_owner",oppo);
			apply(call,shad,"start_shadow",target,level/5+3);
			write("You notice with pleasure as "+oppo_name+"'s "+
				apply(call,target,"query_name")+" starts glowing red.\n");
			say(capitalize(oppo_name)+"'s "+apply(call,target,"query_name")+
				" starts glowing red.\n");
		}
		else
		{
			write(capitalize(oppo_name)+" has no armor.\n");
		}
	}
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,"You feel unaffected.\n" );
      }         
   }
}
