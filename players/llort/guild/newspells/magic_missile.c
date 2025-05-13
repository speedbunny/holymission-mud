/* ################################################################
   #								  #
   #    		Mage Magic Missile                        #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    30

level() { return 1; }
help () { return HDIRA+"magic_missile/magic_missile"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev > 21) return 0;
   return 1;
}

do_spell( arg, skill )
{
   object enemy;
   int    damage, i, lev; 
   string tpn;

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_SP(SPELL_COST);
   GET_ENEMY(arg,"At whom?\n");
   CHK_FAIL(SPELL_COST,"magic missile");
   ADDSP( -1 * SPELL_COST );

   tpn = TPN;
   lev = TPL;
   lev = (lev+1)/2;
   if(lev>10) lev=10;
   damage = 0;
   for(i=0;i<lev;i++) damage += random(20)+6;
   
   ME("   As you rais your hands, pointing at your enemy,\n   "+lev+
      "  bolts of energy shoot out, seeking their target!\n");

   YOU( enemy, "   "+tpn+" raises "+TP->query_possessive()+
               " hands, pointing at YOU!!\n"+
               "   Suddenly several energybolts shoot unerringly at you!\n");
   OTHERS( ({ TP, enemy }),
               "   "+tpn+" raises "+TPPOS+
               " hands, pointing at "+enemy->query_name()+".\n"+
               "   Suddenly several energybolts shoot unerringly at "+
               enemy->query_objective()+"!\n");

   if(enemy->shielded())
   {
       OTHERS(({}),"   But the bolts are missing the target completely!\n");
       enemy->attack_object(TP);
   }
   else
   {   HITPL( enemy, damage, 7, ({5, 12}) ); };
  
   return( 1 );
}

query_name()
{
   return( "Magic missile" );
}

query_command()
{
   return( "cast 'magic missile' [victim]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'upsyt uyxxyr'" }) +
      ({ 0 })
   );
}
