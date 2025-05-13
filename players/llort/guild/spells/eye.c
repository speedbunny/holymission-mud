
/* ################################################################
   #								  #
   #    		Mage wizards eye                          #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(str,pl) {
int spnr,i;
object ob;
string dir;

  if(!str) {
    ME("Look where ?\n");
    return 1;
  }
  dir=E(TP)->query_room("dest_dir");
  if(!dir) {
    ME("You can't see anything in that direction.\n");
    return 1;
  }

  spnr=MS->spellnr("eye");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  switch(str) {
    case "s":  str="south"; 	break;
    case "n":  str="north";	break;
    case "e":  str="east";	break;
    case "w":  str="west";	break;
    case "sw": str="southwest";	break;
    case "se": str="southeast";	break;
    case "ne": str="northeast";	break;
    case "nw": str="northwest";	break;
    case "u":  str="up";	break;
    case "d":  str="down";	break;
  }

/* works only if the room has query_dest_dir() */

  OTHERS(({ TP }),TPN+" looks concentrated "+str+".\n");
  for(i=1;i<sizeof(dir);i+=2) {
    if(dir[i]==str) {
      if((!dir[i-1])||(!(ob=find_object(dir[i-1])))) {
        ME("You lose concentration as you look in that direction.\n"+
           "There seems to be a magic barrier.\n");
        return 1; 
      }
      ME("You are overcome by a picture of the following area:\n\n");
      ob->long();
      ob=all_inventory(ob);
      for(i=0;i<sizeof(ob);i++)
        if(ob[i]->short()) ME(ob[i]->short()+"\n");
      return 1;
    } 
  }
  ME("You can't see anything there.\n");
  return 1; 
}
