#include "/players/waldo/defs.h"
#define COST TP->query_max_sp()
int main()
{
  if (this_player()->query_sp() < this_player()->query_max_sp())
  {
    write("Not enough energy.\n");
    return 1;
    }
 
  MOVE(CLONE("/players/waldo/guild/bin/obj/magering.c"),TP);
  tell_object(TP,"You create your mage ring.\n");
  TP->restore_spell_points(-COST);
  return 1;

  }

