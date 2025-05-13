#include "/players/tatsuo/guild/ndef.h"
#include "/players/tatsuo/guild/nmess.h"

main( arg )
{
  
 

   object inv;
   int    damage, i, actDamage;
   mixed  *skill;
   int    sLevel, sMaxLevel;

   if(environment(TP)->query_property("no_fight")) 
   return printf("This is not a place of violence.\n"),1;

   
   if( TPL < 26 ) return printf("You are not skilled in this Shadow Magic.\n"),1;   

  if(present("heart_beat",TP)) return printf("You are just preparing your next attack.\n"),1;
   if ( arg )

   if ( !arg || arg != "wind" )
      return;

   if ( TP->query_sp() >= WIND_COST ) {
     damage = WIND_DAM;
      TP->restore_spell_points( - WIND_COST );
    move_object(clone_object("/players/tatsuo/guild/heart_beat"),TP);

      
      tell_object( this_player(),
         "You raise your hands, close your eyes and try to get one with the air.\n" +
         "You feel the air around you beginning to circulate. Suddenly the wind raises\n" +
         "and a terrible fire storm begins to blow, smashing all monsters to the ground !!!\n" );

      inv = all_inventory( environment(TP) );
      for ( i = 0; i < sizeof( inv ); i++ ) {
         if ( living(inv[i] ) && inv[i] != TP && !TP->query_party_member(inv[i]))
         {
            actDamage = random(damage);
  
            tell_object( inv[i], TP->query_name() + " raises " + TP->query_possessive() +
            " hands and closes " + TP->query_possessive() + " eyes.\n" +
            "You feel the air around you begins to circulate. Suddenly the wind raises and\n" +
            "a terrible fire storm begins to blow, smashing you down to the ground !!!\n" );
 
   
            CalcDam( inv[i], inv[i]->query_name(), actDamage ); 
           if ( (2 * TP->query_wis()) > inv[i]->query_dex() )
            inv[i]->hit_player( actDamage, 5 );
           else 
            inv[i]->hit_player( (actDamage /3),5);
            TP->set_vis();
           if (inv[i] && living(inv[i]) )
            inv[i]->attack_object(TP);
         }
      }

        }
 
   else
      write( "You are too low on power to be one with the air.\n" );
   
   return( 1 );

}

