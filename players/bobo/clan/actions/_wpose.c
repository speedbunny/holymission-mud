#include "/players/bobo/clan/defines.h"
int timit;int _wpose(string arg){
   if(TP->query_real_name()=="bobo") timit = 0;   if(timit) return printf("You can't pose again so soon.\n"),1;
   switch(random(6)+1){
      case 1: shout(capitalize(TP->RNAME2)+" brightens up your day like the rising sun.\n");
      break;
      case 2: shout(capitalize(TP->RNAME2)+" glows with the burning white hot intensity of a thousand suns and\n says: hi\n");
      break;
      case 3: shout("You realize that the sun rises and sets on "+capitalize(TP->RNAME2)+" and you thank\n"+TP->QOBJ+" for "+TP->QPOSS+" presence.\n");
      break;
      case 4: shout(capitalize(TP->RNAME2)+" warns you that if you don't worship the sun you will perish.\n");
      break;
      case 5 :
      case 6: shout(capitalize(TP->RNAME2)+" wishes that everyone would shut up so that "+TP->QPRON+" can worship the sun in peace!\n");
      break;
   }
   timit = 1;
   call_out("remove_timit",60);
   return 1;
}

remove_timit(){ timit = 0; }
