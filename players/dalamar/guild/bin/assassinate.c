 



#include "/players/tatsuo/guild/ndef.h"


main( arg )
{
   int    failed, damage, chance, wc, oldMonstHP, newMonstHP, holdTime;
   object *who;
   string oppoName;
  
  if(environment(TP)->query_property("no_fight")){ 
  return printf("This is not a place of violence.\n"),1; }
  
  if(TPL < 22) return printf("You lack the knowledge to accomplish this.\n"),1;
   failed = 0;
   
   if ( !arg ) {
      write( "Assassinate who?\n" );
      return( 1 );
   }
   
   who = present( arg, environment( TP ) );

   if ( !who || !living(who) || who->query_ghost() ) {
      write( "You only can assassinate somebody, who you can see and who is alive.\n" );
      return( 1 );
   }
   
   if ( TP->query_sp() < ASSASS_COST ){ 
        printf("You are too weakened to attempt to assassinate.\n");
        return 1;
   }
  
   if ( !(TP->is_invis_for(who)) ) {
      write("Bad timing!!! You are not camouflaged, this might end bad !!!\n" );
      failed = 1;
   }
   else if ( who->query_attack(this_player()) == this_player() ) {
      write( "You try to assassinate " + capitalize(who->query_name()) +
             ", but " + who->query_pronoun() + " remembers your\n"+
             "last attempt, so you fail !!!\n" );
      failed = 1;
   }
   else if ((TP->query_attack() && present(TP->query_attack(),environment(TP))))
 
   {
      write( "Assassinate while fighting!? Strange.\n" );
      failed = 1;
   }

        else if ( !(TP->query_wielded()) ) {
      write( "Without a weapon ? Strange concept ...\n" );
      failed = 1;
   }

   if ( failed ) {
      write( "You make some noise and run unprotected into the enemies "+
             "attack !!!\n" );
      who->attack_object( TP );
      TP->set_vis();
      return( 1 );
   }

            
   if ( random(who->query_level()*2) < ASSASSKILL ) {
      
            
        oldMonstHP = who->query_hp();

      wc = TP->query_wielded()->weapon_class();
      damage = wc*random((wc+1)/2)+TP->query_dex()*2+TP->query_str(); 
      oppoName = who->query_name();
      damage = who->hit_player(damage,2); 
      TP->restore_spell_points(- ASSASS_COST);      TP->add_exp(damage);
       TP->set_vis();
      if ( TP->query_immortal() )
         write( "----- effective damage of assassinate: " + damage +"\n");

      if ( !who ) {
         write( "You place your weapon in the back of your opponent,\n"+
                "resulting in a strange noise, a lot of gore and a CORPSE !\n");
         say( "You suddenly hear a strange noise, blood spilling around and\n"+
               oppoName+" lies in a flat position, unmoving.\n");
         return( 1 );
      }
      write("You move behind your opponent and ASSASSINATE this creep!!!\n");
      tell_object( who, "You feel a piercing pain in your spine !!!\n" );
      say( TP->query_name()+" moves behind "+who->query_name()+" and "+
           "ASSASSINATES this creep !!!\n", who );

      // --- handle the stun
      newMonstHP = who->query_hp();
      holdTime = (oldMonstHP-newMonstHP)*10/oldMonstHP;
      if ( holdTime > 0 ) {
         holdTime = holdTime > 5 ? 5 : holdTime;
         holdTime++;
         who->hold( this_object(), holdTime );
         write( who->query_name()+" is STUNNED by the sheer power of your hit "+
                "!!!\n" );
         tell_object( who, "You are stunned by the sheer power of the hit!\n");
         say(who->query_name()+" is STUNNED by the sheer power of the hit !\n",
             who );
         who->stop_fight();
         who->stop_fight();
      }
  "/players/tatsuo/guild/soul"->rm_invis();
      return( 1 );
   }

      write( "You try to assassinate your enemy, but in the last second " + 
           who->query_pronoun() + " recognizes you and can avoid the hit.\n"); 
   tell_object( who, capitalize( TP->query_real_name() ) +
         " tried to assassinate you.\nBut you recognize the attempt and " +
         "can avoid the hit.\n" );

   who->attack_object( TP );
  TP->set_vis();
  destruct(present("camouflager",TP));
   return( 1 );
}




