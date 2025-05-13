/* ################################################################
   #								  #
   #    		Mage Lightning Bolt                       #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    45

level() { return 8; }
help () { return HDIRA+"lightning_bolt/lightning_bolt"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev>20) return 1;
   if(lev>12) return 2;
   return 3;
}

do_spell( arg, skill )
{
   object enemy;
   int    damage, i, lev; 

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_SP(SPELL_COST);
   GET_ENEMY(arg,"At whom?\n");
   CHK_FAIL(SPELL_COST, "lightning bolt");
   ADDSP( -1 * SPELL_COST );

   lev = TPL;
   if(lev>20) lev=20;
   damage = ROLL(lev,30,0);
   
   ME("You send a powerfull lightning bolt at "+
      capitalize(enemy->query_name())+".\n");

   YOU( enemy, TPN+" shoots a powerfull lightning bolt at YOU!!\n");
   OTHERS( ({ TP, enemy }),
           TPN+" shoots a powerfull lightning bolt at "+
           enemy->query_name()+".\n");

   HITPL(enemy,damage, 5, ({2, 12}) );
   return( 1 );
}

query_name()
{
   return( "Lightning bolt" );
}

query_command()
{
   return( "cast 'lightning bolt' [victim]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'pudcexuxd qmpe'" }) +
      ({ 0 })
   );
}
