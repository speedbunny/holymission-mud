
/* ################################################################
   #								  #
   #    		Mage calm spell                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST 80

speed(lev)
{
    if(lev > 25) return 0;
    if(lev > 20) return 1;
    if(lev > 15) return 2;
    return 3;
}

level() {   return 11; }
help () {   return HDIRA+"calm/calm"; }
cost () {   return SPELL_COST; }

do_spell(arg,skill) {
int spnr;
object enemy;

  CHK_SKILL();
  CHK_GHOST();
  CHK_LIGHT();
  CHK_SP(SPELL_COST);
  GET_ENEMY(arg, "Calm whom ?\n"); 
  CHK_FAIL(SPELL_COST,"calm");
  ADDSP(-SPELL_COST);

  if((TPL+TPCH-enemy->query_levels()+50) < random(100)) {
    ME("You could not calm "+arg+".\n");
    OTHERS(({ TP,enemy }),TPN+" tried to calm "+arg+" but failed.\n");
    YOU(enemy,TPN+" tried to calm you but you withstood.\n");
    return 1;
  }

  enemy->stop_fight();
  enemy->stop_fight();
  enemy->stop_hunter(1);
  enemy->set_tame(TP);

  TP->stop_fight();
  TP->stop_fight();
  TP->stop_hunter(1);

  OTHERS(({ TP,enemy }),TPN+" calmed "+arg+".\n");
  ME("You calmed "+arg+".\n");
  YOU(enemy,TPN+" calmed you.\n");
  return 1;
}

query_name()
{
   return( "Calm" );
}

query_command()
{
   return( "cast 'calm' <enemy>" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'dskj'" }) +
      ({ 0 })
   );
}
