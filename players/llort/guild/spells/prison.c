
/* ################################################################
   #								  #
   #    		Mage prison spell                         #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;
object prisoner;

  if(!arg) {
    ME("Jail whom ?\n");
    return 1;
  }

  spnr=MS->spellnr("prison");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  if(!(prisoner=present(arg,E(TP)))) {
    write(arg+" is not here.\n");
    return 1;
  }
  if(!living(prisoner)) {
    ME("The "+arg+"isn't impressed about your attempt.\n");
    OTHERS(({ TP }),TPN+" tries to cast a spell on "+arg+" but fails.\n");
    return 1;
  }
  if(prisoner->query_npc()) {
    ME("You can't do that on monsters.\n");
    return 1;
  } 

  if(E(TP)->query_property("no_teleport")) {
    ME("The spell fizzles as you crash against an invisible " +
      "wall of force.\n");
    OTHERS(({ TP }),TPN+" seems to get a bit transparent, but suddenly "+
      TP->query_pronoun()+" becomes solid again.\n");
    return 1;
  }

  if(PRISON_CHANCE>random(100)) {
    ME("You cast prison on "+prisoner->query_name()+".\n"); 
    OTHERS(({ TP }),TPN+" casts a spell.\n");
    YOU(prisoner,"Suddenly a black hole appears and sucks you in.\n");
    OTHERS(({ prisoner }),"Suddenly a black hole appears and sucks "+
        prisoner->query_name()+" in.\n");
    move_object(prisoner,PRISON);
    tell_room(PRISON,prisoner->query_name()+" arrives out of a black hole.\n");
    YOU(prisoner,"After a while you are thrown out of the hole again.\n\n");
    find_object(PRISON)->free_pris(prisoner,JAIL_TIME);
    command("look",prisoner);
  } else {
    ME("You cast prison on "+prisoner->query_name()+".\n"); 
    ME(prisoner->query_name()+" notices your attempt.\n");
    YOU(prisoner,TPN+" tried to cast a spell on you but failed.\n");
    OTHERS(({ TP,prisoner }),TPN+" casts a spell.\n");
  }
  return 1;
}
