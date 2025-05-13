// ------------------------------------------------------------------------ 
// disarm
// used at the ninjas
// patience
// ------------------------------------------------------------------------ 

inherit  "/abilities/ability";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "disarm" );
   set_syntax( "disarm [opponent]" );
   set_speed( NEXT_HB );
   set_guild_allowed( 8, 15 );
// Added by Mangla.
   set_guild_allowed( 4, 20 );
   set_kind( AGGRESSIVE );
   set_cost( 20 );
   set_auto_inc();
   set_player_help( 
      "This ability enables you to disarm your opponent. It can only be used\n"+
      "when you are fighting. If the disarm is successfull, your opponent\n"+
      "will drop the wielded weapon." );
}

void display_prepare( object who )
{
   ;
}

void release( string arg, int act_skill, int max_skill )
{
   object oppo, weap;
   string oppo_name, tp_name;
   int    size;

   // ----- am i fighting ? -------------------------
   if ( !funcall( call, TP, "query_attack" ) ) {
      write( "You can only disarm in combat.\n" );
      return;
   }

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   // ----- is it my opponent ? -----------------------
   if ( oppo != funcall( call, TP, "query_attack" ) ) {
      write( "You can only disarm your opponent !\n" );
      return;
   }

   // ----- no stealing allowed ? ---------------------
   if (oppo->query_no_steal() || environment(TP)->query_property("no_steal")) {
      write( "It is impossible to disarm "+oppo->query_name()+" !\n" );
      return;
   }

   // ----- get the weapon ----------------------------
   weap = 0;
   size = funcall( call, oppo, "query_number_of_arms" ) - 1;
   while ( size >= 0 && !weap ) {
      weap = funcall( call, oppo, "query_wielded_weapon", size );
      size--;
   }

   oppo_name = funcall( call, oppo, "query_name" );
   tp_name = funcall( call, TP, "query_name" );

   if ( check_success( act_skill, max_skill ) && weap ) {
      if ( transfer( weap, environment(oppo) ) )
         write( "It is impossible to disarm "+oppo_name+" !\n" );
      else {
         write( "You make a nifty fighting move and DISARM your opponent !\n" );
         say( tp_name+" makes a nifty fighting move and disarms "+oppo_name+
              " !\n", oppo );
         tell_object( oppo, tp_name+" makes a nifty fighting move and DISARMS "+
              "you !\n" );
      }
   }
   else {
      write( "You make a nifty fighting move but nearly fall on your butt !\n");
      say( tp_name + " makes a nifty fighting move but nearly falls on "+TPPOS+
           "butt.\n" );
   }
}
