
/* ################################################################
   #								  #
   #    		Mage Fireball                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    80

level() {  return 8; }
help () {  return HDIRA+"fireball/fireball"; }
cost () {  return SPELL_COST; }

speed(lev)
{
   if(lev<10) return 3;
   if(lev<20) return 2;
   return 1;
}

do_spell( arg, skill )
{
    object inv;
    int    dice,i,j;

    CHK_SKILL();
    CHK_GHOST();
    CHK_LIGHT();
    CHK_SP(SPELL_COST);
    CHK_FAIL(SPELL_COST,"fireball");
    ADDSP(-SPELL_COST);

    inv = all_inventory( environment(TP) ) - TP->grmems_in_room();
    dice=(TPL > 20 ? 20 : TPL);

    OTHERS(({}),"A redhot globe of fire explodes in the area!\n");

    for ( i = j = 0; i < sizeof( inv ) && j<(TPL/2); i++ )
    {
        if ( living( inv[i] ) )
        {
             tell_object( inv[i], "You are burned by the explosion!\n");
             HITPL(inv[i],ROLL(dice,30,0), 5, ({ 1, 12}) );
             j++;
        }
    }
   
   return( 1 );
}

query_name()    { return "Fireball";        }
query_command() { return "cast 'fireball'"; }

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'pwtymsuu'" }) +
      ({ 0 })
   );
}
