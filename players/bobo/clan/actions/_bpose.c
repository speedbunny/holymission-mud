#include "/players/bobo/clan/defines.h"
int timit;int _bpose(string arg){
   if(TP->query_real_name()=="bobo") timit = 0;   if(timit) return printf("You can't pose again so soon.\n"),1;
   switch(random(6)+1){
      case 1: shout(capitalize(TP->RNAME2)+" manipulates the sun to blind all the members of clan Sunsu!\n");
      break;
      case 2:
      case 3: shout(capitalize(TP->RNAME2)+" makes the sun focus on you to cook you like steak flambe.\n");
     break;
      case 4:
      case 5 :
      case 6: shout(capitalize(TP->RNAME2)+" Takes tetsuhara's Katana and impales him with it.\n");
      break;
   }
   timit = 1;
   call_out("remove_timit",60);
   return 1;
}

remove_timit(){ timit = 0; }
