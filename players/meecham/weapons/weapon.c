inherit "/obj/weapon";
#include "/players/meecham/def.h"
string owner;

set_owner(n) { owner = n; }

query_owner() { return owner; }

wield(str)
{
  if(TP->query_npc() || !TO->query_owner() || TO->query_owner()==TPR)
    ::wield();
  else
    printf("You have not earned the right to wield this weapon!\n");
  return 1;
}
