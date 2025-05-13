
/* ################################################################
   #								  #
   #    		    Mage pose                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

doit(arg,pl) {
int spnr;
  if(TPL<15) return;
  spnr=MS->spellnr("pose");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  OTHERS(({ TP }),TPN+" makes some magical gestures.\n");
  if(TPL<25) {
    shout(TPN+" sends a fireball in the sky.\n");
    ME("You send a fireball in the sky.\n");
  } else if(TPL<29) {
    if(arg) {
      shout(TPN+" summons a firework, writing "+arg+" in the sky.\n");
      ME("You summon a firework, writing "+arg+" in the sky.\n");
    } else {
      shout(TPN+" summons a firework in the sky.\n");
      ME("You summon a firework in the sky.\n");
    }
  } else {
    if(arg) {
      shout(TPN+" rises towards the sky, inside of a gigantic torrent"+
                " of fire.\n" + capitalize(TP->query_pronoun()) +
                " burns the world with the words: "+arg+"\n");
      ME("You rise towards the sky, inside of a gigantic torrent"+
         " of fire.\nYou burn the world with the words: "+arg+"\n");
    } else {
      shout(TPN+" rises towards the sky, inside of a gigantic torrent"+
                " of fire.\nAs " + TP->query_pronoun() +
                " points to heaven lightning springs out"+
                " from his hands.\n");
      ME("You rise towards the sky, inside of a gigantic torrent"+
         " of fire.\nAs you point to heaven lightning springs out"+
         " from your hands.\n");
    }
  }
  return 1;
}
