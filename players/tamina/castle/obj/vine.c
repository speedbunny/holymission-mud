#include "/players/tamina/defs.h"

int counter;

reset(arg) 
{ 
  counter = 0; 
}

id(str) 
{
  return str == "vine" || str == "grape vine"; 
}

short() 
{
  return "A large Grape Vine"; 
}

long() 
{ 
  write("A large vine, attached to the trellis.\n"+
        "Perhaps there a few more grapes left to be picked?\n"); 
}

get()
{
  return 0;
}

init() { 
  add_action("get_grape","pick");
  add_action("get_grape","get");
  add_action("get_grape","take");
}

int get_grape (string str) 
{
  object ob;
  
  if (str=="grape") 
  {
    if (counter >= 4) 
    {
      write("You can't, there are no more grapes left on the vine.\n");
      return 1;
    }
    write("You pull off a grape from the vine.\n");
    say(TPN+" picked a grape from the vine.\n");

    ob = CLO (COBJ + "grape");
    if (transfer(ob,TP)) move_object(ob,environment(TP));

    counter++;

    return 1;
  }
}
