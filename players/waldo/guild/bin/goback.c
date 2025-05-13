#include "/players/waldo/guild/defs.h"

int main() 
{
  object prev_room, mage;
  mage=this_player();

  prev_room=present("magesoul",mage)->prev_environment();
  if (objectp(prev_room))
    move_object(mage,prev_room);
  else   
    move_object(mage,"guild/master"->query_room(
                     "guild/master"->query_number("mage")
                                               )
               );
  write("You have returned.\n");
  say(CAP(TP->query_real_name())+" returns from a far-away place.\n");
  command("look",TP);
  return 1;
}








