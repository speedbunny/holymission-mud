#include "/players/tatsuo/guild/ndef.h"

main(arg) {

object inroom;
int i;

if(TP->query_sp() < NSAY_COST) {
  printf("You cannot summon the strength to speak to anyone.\n\r");
  return 1;
}

if(!arg) {
 printf("Nsay what!!\n\r");
 return 1;
}
    inroom = all_inventory( environment(TP) );
      for ( i = 0; i < sizeof( inroom ); i++ ) {
 if ( living(inroom[i] ))
   if(TP->query_real_name() != inroom[i]->query_real_name())
    if(inroom[i]->query_guild() == 8 )
 tell_object(inroom[i], TPN+" says in nihonese: "+arg+".\n");
     else
 tell_object(inroom[i],TP->query_name()+" says something in nihonese.\n\r");
 }
 printf("You say in nihonese: "+arg+".\n");
 TP->restore_spell_points(-NSAY_COST);
 return 1;
}
