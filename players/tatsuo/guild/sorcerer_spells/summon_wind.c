#define TP            (this_player())
#define S_WIND_COST      (TP->query_wis() * 2)
#define SR            "/players/patience/skill/skill_rout"

do_summonwind( arg )
{
   if ( !TP ) return( 1 );

   TP->remove_skill( "summonwind" );

   tell_object( TP,
      "------------------------------------------------------------------\n"+
      "The spell system has changed and this spell had been removed !!!!!\n"+
      "If you are a ninja, please check the guild-board, otherwise this\n"+
      "spell is lost for you !  No reimbursement \n"+
      "------------------------------------------------------------------\n" );

   return( 1 );

#if 0
   object inv;
   int    damage, i, actDamage;
   mixed  *skill;
   int    sLevel, sMaxLevel;

   skill = TP->get_skill( "summon_wind" ); /* whe the fuck had changed this??*/

   if ( !skill && !sizeof( skill ) )
      return;

   sLevel = skill[0];
   sMaxLevel = skill[1];
   if ( !sLevel || !sMaxLevel )
      return;

   if ( random(sMaxLevel) > sLevel ) {
      write( "You cannot concentrate enough to summon wind ...\n");
      return( 1 ); 
   }

   if ( arg )

   if ( !arg || arg != "wind" )
      return;

   if ( TP->query_sp() >= S_WIND_COST ) {
      damage = S_WIND_COST;
      TP->restore_spell_points( -1 * S_WIND_COST );
      
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
   /*
            "/players/patience/guild/attack_mess"->CalcDam( 
                     inv[i], inv[i]->query_name(), actDamage ); 
     this is a spell not a hit */
           if ( (2 * TP->query_wis()) > inv[i]->query_dex() )
            inv[i]->hit_player( actDamage, 5 );
           else 
            inv[i]->hit_player( (actDamage /3),5);
            TP->set_vis();
           if (inv[i] && living(inv[i]) )
            inv[i]->attack_object(TP);
         }
      }

      SR->advance_skill( TP, "summon_wind", 1, sMaxLevel );
   }
   else
      write( "You are too low on power to get one with the air.\n" );
   
   return( 1 );
#endif
}
