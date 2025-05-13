#include "/players/tamina/defs.h"

int counter;

reset(arg) 
{
  counter = 0; 
}

id(str) 
{ 
  return str == "bush" || str == "bramble bush" || str == "bramblebush"; 
}

short() 
{ 
  return "A bramble bush"; 
}

long() 
{ 
  write("An overgrown bramble bush, sitting in the corner.\n"+
        "Perhaps there a few more brambles still to be picked?\n"); 
}

get()
{
  return 0;
}

init() 
{ 
  add_action("get_bramble","pick");
  add_action("get_bramble","get");
  add_action("get_bramble","take");
}

int get_bramble (string str) 
{
  object ob;
  
  if (str == "bramble") 
  {
    if (TP->DEX < 9) 
    {
      write("You stab yourself on a thorn!!\n");  
      say(TPN+" cuts a finger on a thorn on the bush!\n");

      HIT(6);
      return 1;
    }
    if (counter >= 5) 
    {
      write("You can't, there are no more brambles left on the bush.\n");
      return 1;
    }
    write("You pull off a bramble from the bush.\n");
    say(TPN+" picked a bramble from the bush.\n");

    ob = CLO (COBJ + "bramble");
    if (transfer(ob,TP)) move_object(ob,environment(TP));

    counter++;

    return 1;
  }
}

