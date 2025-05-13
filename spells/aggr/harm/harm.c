inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );
   if(tick) return;

   set_name( "harm" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'harm' [target]" );
   set_save_vs( TOUCH );
   set_cost( 100 );
   set_guild_allowed(2,24);
   set_duration_info( "instant" );
   set_speed( 2 );
   set_player_help(
      "Causes a TON of damage if the victim is touched.\n"+
	  "You can't anything with this spell, the victim is reduced to 10 HP.\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo;
   string oppo_name, tp_name;
   int    do_it,hp,lev,dam,modify;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   modify = (TP->query_level()+TP->query_legend_level() ) / 6 ;

   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,modify,0,this_object()) ) {
         case IMMUNE:      do_it = 0; break;
         case SAVED:       do_it = 0; break;
         case SAVE_FAILED: do_it = 1; break;
         default:          do_it = 1;
      }

      oppo_name = oppo->query_name( );
      tp_name = TP->query_name( );

      if ( do_it ) 
	{
		lev = TP->query_level()+TP->query_legend_level();
		dam = roll_dice(20,40,lev*3);
		tell_object(oppo,capitalize(tp_name)+
		"'s touch sends you reeling.\n");
		tell_object(TP,"Your touch sends "+oppo_name+" reeling.\n");
		if((hp=apply(call,oppo,"query_hp")) < dam)
			apply(call,oppo,"hit_by_spell",(hp-10));
		else apply(call,oppo,"hit_by_spell",dam);
		WINFO("Damage by harm: "+dam);
	}
      else {
         write("You MISSED "+oppo_name+" with your touch.\n");
         tell_object( oppo,capitalize(tp_name)+" missed you with his touch.\n");
      }         
   }
}
