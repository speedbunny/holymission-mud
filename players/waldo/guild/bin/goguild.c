#include "/players/waldo/guild/defs.h"
int main() 
{
  object mage;
  string location;

  mage=this_player();
  
  if (file_name(environment(mage)) == "players/saffrin/guild/rooms/outer")  
  {
    write("Your keen mage senses notice that you didn't exactly "+
          "move anywhere.\n");
    return 1;
    }
  
  if (environment(mage)->query_property("no_teleport")) 
  {
    write("You are unable to find a way out of this place.\n");
    return 1;
  }
  
  present("magesoul",mage)->prev_environment(environment(mage));
  if(!mage->query_invis())
    {
      say(mage->query_name()+" utters the words 'Blast off'.\n");
      say(mage->query_name()+" is surrounded by a swirling energy ball.\n");
      say(mage->query_name()+" fades from this location.\n");
      }
  move_object(mage,"/players/saffrin/guild/rooms/outer");
  write("You utter the words 'Energize'.\n");
  write("You feel wrenched into another location.\n");
  return 1;
}
