inherit "/spells/spell";
#include "/spells/spell.h"
#include "/players/sourcer/guild/druid.h"

void reset( int tick )
{
   ::reset( tick );

   if(tick) return;

   set_name( "slay living" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'slay living' [target]" );
   set_save_vs( DEATHMAGIC );
   set_cost( 500 );
   set_guild_allowed(2,32);
   set_duration_info( "instant" );
   set_speed( 2 );
   set_player_help(
      "This spell will simply destroy any living being which has failed its  \n"+
	  "savings roll.\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it,mod;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;
   
   mod = TP->query_level()+TP->query_legend_level()-10;

   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,-mod,-mod/2,this_object()) ) {
         case IMMUNE:      do_it = 0; break;
         case SAVED:       do_it = 0; break;
         case SAVE_FAILED: do_it = 1; break;
         default:          do_it = 1;
      }

      oppo_name = apply( call, oppo, "query_name" );
      tp_name = apply( call, TP, "query_name" );

      if ( do_it ) 
	{
		say(capitalize(tp_name)+" simply destroys the life within "+
			oppo_name+"!\n",oppo);
		write("You SLAY "+oppo_name+" !! Don't you feel ashamed?\n");
		tell_object(oppo,"As you hear the words of power from "+
                    tp_name+" \nyou feel a massive drain on your body!\n");

// #sourcer# Until word from an arch the old value is back
// Mangla: Arch saying too strong. This spell was ridiculous. Besides this is a
//         secured dir. How did you get access to it? An arch
//         copied this spell in for Haplo there for it was approved before.
// #sourcer# 27.06 With the spell like that you can't even kill an ant!
// I am going to implement an Max-ammount of damage and let me know
// FAST what you think about it. Cause the next days i am gonna change it!
      oppo->hit_by_spell((oppo->query_hp()*4)/5);
//      oppo->hit_by_spell((oppo->query_max_hp()+1));
	}
      else {
         write(capitalize(oppo_name)+" seems to be unaffected by the spell.\n");
         tell_object( oppo,capitalize(tp_name)+" tried to SLAY you!\n" );
		 oppo->attack_object(TP);
      }         
   }
}
