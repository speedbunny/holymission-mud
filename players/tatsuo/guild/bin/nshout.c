#include "/players/tatsuo/guild/ndef.h"

main(arg) {

object *players;
int i;

if(TP->query_sp() < NSHOUT_COST) {
  printf("You cannot summon the strength to shout to anyone.\n\r");
  return 1;
}

if(!arg) {
 printf("Nshout what?\n\r");
 return 1;
}
// players = filter_array(users(), "shout_filter",this_object());
players = sort_array(users(),"level_desc",this_object());

      for ( i = 0; i < sizeof( players ); i++ ) {
 if(players[i]->query_real_name() != TP->query_real_name())
     if(TP->query_guild() == players[i]->query_guild())
tell_object(players[i],capitalize(TPRN)+" shouts in nihonese: "+arg+"\n");
     else
  if(!TP->query_immortal()){
 tell_object(players[i],TP->query_name()+" shouts something in nihonese.\n\r");
   }
 }
printf("You shout in nihonese: "+arg+"\n\r");
 TP->restore_spell_points(-NSHOUT_COST);
 return 1;
}
