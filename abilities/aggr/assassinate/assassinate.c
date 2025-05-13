// ------------------------------------------------------------------------ 
// assassinate
// used at the ninjas
// patience
// ------------------------------------------------------------------------ 

inherit  "/abilities/ability";
#include "/spells/spell.h"

void display_msg( int dam, string tp_name, string oppo_name, object oppo );

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "assassinate" );
   set_syntax( "assassinate [opponent]" );
   set_speed( NEXT_HB );
   set_guild_allowed( 8, 20 );
   set_kind( AGGRESSIVE );
   set_cost( 50 );
   set_auto_inc();
   set_player_help( 
      "Assassination is the art of killing somebody very quickly. A high\n"+
      "skill in this special ability will make an almost deadly opponent." );
}

void display_prepare( object who )
{
   ;
}

void release( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   int    dam, oldMonstHP, wc, newMonstHP, holdTime;
   string oppo_name, tp_name;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   oppo_name = funcall( call, oppo, "query_name" );
   tp_name = funcall( call, TP, "query_name" );

   if ( oppo->query_attack(TP) == TP ) {
      write( "You try to assassinate "+oppo_name+", but "+TPPRO+" reminds your"+
             " last attack, and is on guard.\nYou failed.\n" );
      oppo->attacked_by( TP );
   }
   else if ( TP->query_attack() && 
             environment(TP) == environment(TP->query_attack()) ) {
      write( "You cannot assassinate somebody while fighting.\n" );
   }
   else if ( !(TP->query_wielded_weapon(0)) ) {
      write( "You need a weapon in your right hand to assassinate somebody ..."+
             "\n" );
      oppo->attacked_by( TP );
   }
   else if ( !(TP->is_invis_for(oppo)) ) {
      write( "You opponent has seen you !!! This might end bad ...\n" );
      oppo->attacked_by( TP );
   }
   else if ( check_success( act_skill, max_skill ) ) {
      oldMonstHP = oppo->query_hp();
      wc = (TP->query_wielded_weapon(0))->weapon_class();
      dam = wc*(random(wc)+1)+act_skill+TP->query_str();
      dam = oppo->hit_by_ability(dam,2);
      if ( TP->query_immortal() )
         write( "----- effective damage: "+dam+" -----\n" );
      if ( !oppo || oppo->query_ghost() ) {
         write( "You place your weapon in the back of opponent,\n"+
              "resulting in a strange noise, a lot of gore and a CORPSE !!!\n");
         say( "You suddenly hear a strange noise, blood spilling around and\n"+
              oppo_name+" lies flat on the ground, unmoving ...\n" );
      }
      else {
         write( "You move behind "+oppo_name+" and ASSASSINATE this creep !\n");
         tell_object( oppo, "You feel a piercing pain in your spine !!!\n" );
         say( tp_name+" moves behind "+oppo_name+" and ASSASSINATES this "+
              "creep !!!\n", oppo );
         newMonstHP = oppo->query_hp();
         holdTime = (oldMonstHP-newMonstHP)*10/newMonstHP;
         if ( holdTime > 0 ) {
            holdTime = holdTime > 3 ? 3 : holdTime;
            holdTime++;
            shad = clone_object( "/shadows/stun_shad" );
            if ( shad ) {
               shad->start_shadow( oppo, holdTime );
               shad->set_stunner( TP );
            }
            else
               write( "But something has gone wrong !\n" );
            write(oppo_name+" is STUNNED by the sheer power of your hit !!!\n");
            tell_object(oppo,"You are STUNNED by the sheer power of the hit "+
                             "!!!\n");
            say(oppo_name+" is STUNNED by the sheer power of the hit !!!\n",
                             oppo );
            TP->attack_object( oppo );
         }
      }
   }
   else {
      write( "You try to assassinate "+oppo_name+", but in the last second\n"+
             oppo->query_pronoun()+" recognizes you and avoids the hit !\n" );
      tell_object( oppo, tp_name+" tried to assassinate you, but you can avoid"+
                   " the hit !\n" );
      oppo->attacked_by( TP );
   }

   TP->unhide();
}
