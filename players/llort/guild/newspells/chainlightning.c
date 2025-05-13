
/* ################################################################
   #								  #
   #    		Mage Chainlightning                       #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    100

level() {  return 16; }
help () {  return HDIRA+"chainlightning/chainlightning"; }
cost () {  return SPELL_COST; }

speed(lev)
{
   if(lev<10) return 5;
   if(lev<15) return 4;
   if(lev<20) return 3;
   if(lev<25) return 2;
   return 1;
}

do_spell( arg, skill )
{
    object inv;
    int    dice,i;

    CHK_SKILL();
    CHK_GHOST();
    CHK_LIGHT();
    CHK_SP(SPELL_COST);
    CHK_FAIL(SPELL_COST,"chainlightning");
    ADDSP(-SPELL_COST);

    inv = all_inventory( environment(TP) ) - TP->grmems_in_room();
    dice = ( TPL > 25 ? 25 : TPL);

    write("A lightningbolt shoots form your hand toward your enemies,\n"+
          "bouncing wildly between them.\n");

    for ( i = 0; i < sizeof( inv ) && dice > 0; i++ )
    {
        if ( living( inv[i] ) )
        {
             tell_object( inv[i], TPN + " raises " + TPPOS +
                 " hand and points with the other hand at YOU !!!\n" );
             HITPL(inv[i],ROLL(dice,30,0), 5, ({ 2, 12}) );

             dice--;
        }
    }
   
   return( 1 );
}

query_name()    { return "Chainlightning";        }
query_command() { return "cast 'chainlightning'"; }

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'tkpyhryskmhyhs'" }) +
      ({ 0 })
   );
}
