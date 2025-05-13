inherit "/room/room";
#include "/players/tamina/defs.h"
#define MAXLIST 6

string name_of_item;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

    set_light(2);
    long_desc = "On the altar you can see:\n";
    no_obvious_msg = "";
}

inventory(str) 
{
  object ob;
  int max;
  if (!str)
    str = "all";

  max = MAXLIST;
  ob = first_inventory(TO);
  long();
  while(ob && max > 0) 
  {
    if (str == "all") 
    {
      list(ob);
      max -= 1;
    }
    ob = next_inventory(ob);
  }
}

list(ob) 
{
  write("   "+ob->SHT+"\n");
}

buy(item) 
{
  name_of_item = present(item);
  if (!name_of_item) 
  {
    write("There is no such thing on the altar.\n");
    return 0;
  }
  if (transfer(name_of_item, TP)) 
  {
    write("You can't carry that much.\n");
    return 1;
  }
  TR(name_of_item, TP);
  write("You take "+item->SHT+" from the altar.\n");
  say(TPN+" takes "+item->SHT+" from the altar.\n");
  return 1;
}

