// ------------------------------------------------------------------------ 
// stunning punch
// used at the ninjas
// patience
// ------------------------------------------------------------------------ 

inherit  "/abilities/ability";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "stunning punch" );
   set_syntax( "stunpunch [opponent]" );
   set_speed( 1 );
   set_guild_allowed( 8, 42 );
   set_kind( AGGRESSIVE );
   set_cost( 100 );
   set_auto_inc();
   set_player_help( 
       "With this special ability you are able to give somebody a stunning\n"+
       "punch. If you succedd in the punch, your opponent will not be able\n"+
       "to move for the next two rounds of combat." );
}

void display_prepare( object who )
{
   ;
}

void release( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name, oppo_obj;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   oppo_name = funcall( call, oppo, "query_name" );
   tp_name = funcall( call, TP, "query_name" );

   if ( check_success( act_skill, max_skill ) ) {
      oppo_obj = oppo->query_objective();
      write( "You punch at the chest of "+oppo_name+", leaving "+oppo_obj+
             " STUNNED !\n" );
      say( tp_name+" punches at the chest of "+oppo_name+", leaving "+oppo_obj+
           " STUNNED !\n", oppo );
      tell_object( oppo, tp_name+" punches at your chest, leaving you STUNNED "+
           " !\n" );

      shad = clone_object( "/shadows/stun_shad" );
      if ( shad ) {
         shad->start_shadow( oppo, 6 );     // this is correct !
         shad->set_stunner( TP );
      }
      else
         write( "But something has gone wrong !\n" );
      TP->attack_object( oppo );
   }
   else {
      write( "You punch at the chest of "+oppo_name+", but nearly break your "+
             "own fingers.\n" );
      say( tp_name+" punches at the chest of "+oppo_name+", but nearly breaks "+
           TPPOS+" own fingers.\n", oppo );
      tell_object( oppo, tp_name+" punches at your chest but nearly breaks "+
           TPPOS+" own finger.\n" );
      oppo->attacked_by( TP );
   }
}
