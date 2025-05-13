#define TP            (this_player())
#define S_WIND_COST   (TP->query_maxsp()*6/10)
#define SR            "/players/patience/skill/skill_rout"

do_summonwind( arg )
{
   object inv;
   int    damage, i, actDamage;
   mixed  *skill;
   int    sLevel, sMaxLevel;

   skill = TP->get_skill( "fire_shuriken" );
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
      damage = (TP->query_wis() + TP->query_int())/2;
      TP->restore_spell_points( -1 * S_WIND_COST );
      
      tell_object( this_player(),
         "You raise your hands, close your eyes and try to get one with the air.\n" +
         "You feel the air around you beginning to circulate. Suddenly the wind raises\n" +
         "and a terrible storm begins to blow, smashing all monsters to the ground !!!\n" );

      inv = all_inventory( environment(TP) );
      for ( i = 0; i < sizeof( inv ); i++ ) {
         if ( living( inv[i] ) && inv[i] != TP ) {
            actDamage = damage / 2 + random( damage / 2 );
  
            tell_object( inv[i], TP->query_name() + " raises " + TP->query_possessive() +
            " hands and closes " + TP->query_possessive() + " eyes.\n" +
            "You feel the air around you begins to circulate. Suddenly the wind raises and\n" +
            "a terrible storm begins to blow, smashing you down to the ground !!!\n" );
            "/players/patience/guild/attack_mess"->CalcDam( 
                     inv[i], inv[i]->query_name(), actDamage ); 
            inv[i]->hit_player( actDamage, 5 );
         }
      }

      SR->advance_skill( TP, "summon_wind", 1, sMaxLevel );
   }
   else
      write( "You are too low on power to get one with the air.\n" );
   
   return( 1 );
}
