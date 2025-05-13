inherit "obj/armour";

/********************************************************************/
                 /* DRUNKEN SAILORS */
/********************************************************************/

#define TP this_player()
#define TO this_object()
#define TPN TP->query_name()
#define TPR TP->query_real_name()
#define TPS TP->query_short_name()
#define TPL TP->query_level()
#define TPI TP->query_int()
#define TPW TP->query_wis()
#define E environment
#define ETP E(TP)
#define SAY(i) tell_room(E(TP),i)

/*********************************************************************/

int att;
if (!TPA) { att=0; }
#define CHK_SP(i);\
if (TP->query_spell_points()<i) {\
write("You are to low on mental power !\n");\
return 1;\
}
#define CHK_GHOST();\
if (TP->query_ghost()) {\
write("You can't cast your mental power in an immaterial state.\n");\
return 1;\
}
#define SPCOST(i)  (TP->query_wizard() ? spells[i][2] : spells[i][2])
#define SPLVL(i)   spells[i][3]
#define SPELLMAX   1
/**********************************************************************/

reset(arg);
  ::reset(arg);
if (arg) return;
  set_name("jacket");
  set_alias("sailors jacket");
  set_short("A sailors jacket");
  set_long(".............");
people

/* ################################################################
   #								  #
   #    		  Mage meditate                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

doit(arg,pl) {
int spnr,tim,meditate;
object med;

  if(!arg) {
    ME("How long ?\n");
    return 1;
  } 
  
  spnr=MS->spellnr("meditate");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  sscanf(arg,"%d",tim);
  meditate=(tim-1)*60+random(120)+1;
  if(meditate<=0) {
    ME("You are not able to concentrate that hard.\n");
    return 1;
  }
  move_object(med=clone_object("players/llort/guild/obj/meditator"),TP);
  med->set_dur(meditate,SOUL);
  OTHERS(({ TP }),TPN+" sits down in the lotus-position.\n");
  ME("You sit down in the lotus-position.\n");
  return 1;
}
