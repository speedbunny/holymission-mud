
/* ################################################################
   #								  #
   #    		Mage fear spell                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST 60

speed(lev)
{
    if(lev > 25) return 0;
    if(lev > 20) return 1;
    if(lev > 15) return 2;
    return 3;
}

level() {   return 12; }
help () {   return HDIRA+"fear/fear"; }
cost () {   return SPELL_COST; }

do_spell(arg,skill) {
int spnr;
object enemy;

  CHK_SKILL();
  CHK_GHOST();
  CHK_LIGHT();
  CHK_ATT();
  CHK_SP(SPELL_COST);
  GET_ENEMY(arg, "Fear whom ?\n"); 
  CHK_FAIL(SPELL_COST,"fear");
  ADDSP(-SPELL_COST);

  if(TPL<enemy->query_level() &&
     random(enemy->query_level()-TPL-TPCH)) {
    OTHERS(({ TP,enemy }),TPN+" made BOOO at "+arg+
       " but "+(enemy?enemy->query_objective():"it")+
       " seems not interested.\n");
    ME("You try to fear "+arg+" but "+(enemy?enemy->query_objective():"it")+
       " seems to withstand your atempt.\n");
    if(enemy) YOU(enemy,TPN+
                  " makes some magical gestures and cries BOOO at you.\n");
    return 1;
  }

  YOU(enemy,"You feel a sudden fear overcomes you.\n");
  enemy->run_away();
  if(!present(enemy,E(TP))) {
    OTHERS(({ TP,enemy }),TPN+" makes some gestures and "+enemy->query_name()+
       " runs away in panic.\n");
    ME("You fear "+arg+" and "+enemy->query_objective()+
       " runs away in panic.\n");
  } else { 
    OTHERS(({ TP,enemy }),enemy->query_name()+" attacks "+TPN+".\n");
    ME(enemy->query_name()+" attacks you.\n");
    enemy->attack_object(TP);
  }
  return 1;
}

query_name()
{
   return( "Fear" );
}

query_command()
{
   return( "cast 'fear' <enemy>" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'irwt'" }) +
      ({ 0 })
   );
}
