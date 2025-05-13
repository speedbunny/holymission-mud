// 050897: Sauron: Added a check for a no_sneak property in the env.

#include "/players/brainsprain/guild/headers.h"
/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Sneak =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int main(string arg) {
  object          ob;
  
  if (THIEF->query_ghost()) {
    write("You could move through walls, you don't need to sneak.\n");
    return 1;
  }
  
  CHK_ATT();
  
  if (!arg){
    command("help sneak", this_player());
    return 1;
  }
  
  switch (arg) {
  case "n":         arg = "north";       break;
  case "s":         arg = "south";       break;
  case "w":         arg = "west";        break;
  case "e":         arg = "east";        break;
  case "u":         arg = "up";          break;
  case "d":         arg = "down";        break;
  case "nw":        arg = "northwest";   break;
  case "ne":        arg = "northeast";   break;
  case "sw":        arg = "southwest";   break;
  case "se":        arg = "southeast";   break;
  }
  
  if (!THIEF->query_invis()) {
    write("You would be noticed.\n");
    return 1;
  }
  
  if (environment(THIEF)->query_property("no_sneak")) {
    write("You don't feel agile enough to sneak here.\n");
    return 1;
  }
  
  if (environment(THIEF)->move(arg))
    return 1;
  
  ob = present("castle", environment(THIEF));
  if (ob = present("castle", environment(THIEF)) && ob->move(arg))
    return 1;
  write("You bang your head.\n");
  THIEF->reduce_hit_point(random(20) + 1);
  return 1;
}





