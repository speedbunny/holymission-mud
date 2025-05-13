#define PATH "/players/kawai/areas/games/"
#include <lw.h>

int id(string str)
  {return str=="ticket"||str=="purple ticket";}

int get(string str) 
  {return 1;}

int drop(string str) 
  {return 0;}

string short()
  {return "A purple ticket";}

string query_name()
  {return "A purple ticket";}

void long()
  {write("This ticket is valid for one-time travel to the Grand Wizard's Challenge.\n"+
  "Those wishing to enter may  'tear ticket' for transportation.\n");}

void init() 
  {add_action("tear","tear");}

void reset(int arg);

status tear(string str) 
  {if(!str) 
    {notify_fail("Tear what?\n");
    return 0;}
  if(str=="ticket")
    {if(environment(this_player())->query_property("lab"))
      {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
      "Escape is not that easy!  Your ticket is no good here...\n"));
      return 0;}
    write("As you tear the ticket, the world around you blurs...\n");
    this_player()->move_player("in a whirlwind of smoke and fire...",PATH+"start");
    destruct(this_object());
    return 1;}
  else 
    {notify_fail("You can't tear that!\n");
    return 0;}}

 
