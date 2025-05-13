/*********************************************************+
 *              druid spell                               *
 *              (c) Sourcer 1995                          *
 **********************************************************/
inherit "/spells/spell";
#include "/spells/spell.h"
#include "/players/sourcer/guild/druid.h"

#define E(x) environment(x)
#define TELL(x) tell_object(this_player(),x)

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "grow tree" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'grow tree' " );
   set_save_vs( NO_SAVE );
/* temporary set to 7 */
	set_guild_allowed(2,7);
   set_cost( 100 );
   set_duration_info( "LEVEL*10 rounds" );
   set_speed( 1 );
   set_player_help(
      "The spell plants a magic tree that grows to an oak.\n"+
	  "With tree travel you can enter that tree and walk to \n"+
	  "an other, similar tree."
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it,ret;
   string dctree;
   object tree;

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
	if(dctree=DC->get_tree())
	{
	  if(E(TP)->query_property("no_teleport"))
      {
            DC->delete_tree(dctree);
			TELL("The tree can't grow here.\n");
      }
	  else
		{
          say( capitalize(oppo_name) + " plants a magic sapling.\n" );
          tell_object( oppo,"You plant a magic tree!\n");
	      tree = clone_object(TREES+"little_tree");
	      move_object(tree,E(TP));
	      ret=DC->add_tree(file_name(E(TP)));
		}
	}
	else TELL("You can't create any more trees.\n");
      }
      else {
         write(capitalize(oppo_name)+" seems to be uneffected by the spell.\n");
         tell_object( oppo,"You feel uneffected\n" );
      }         
   }
}
