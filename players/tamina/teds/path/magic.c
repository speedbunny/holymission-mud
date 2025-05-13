inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0; 

    set_light(1);
    short_desc = "Ted's Magic Emporium";
    long_desc =
	"You are in Ted's Magic Emporium. A man in colorful robes\n"+
	"sits behind the counter, ready to serve you.....\n"+
	"Commands are: buy <item>, or <list>\n";

    dest_dir = ({
      TPATH + "road1","north",
    });
}

void init() 
{
    ::init();
    add_action("buy",  "buy");
    add_action("list", "list");
    add_action("no_sell", "sell");
}

int buy(object item) 
{
  if (!item)
  {
    NFAIL("Buy what?\n");
    return 0;
  }
  "/players/tamina/teds/path/magicstore"->buy(item);
  return 1;
}

int list() 
{
  "/players/tamina/teds/path/magicstore"->inventory();
  return 1;
}

int no_sell(string str)
{
  write("Ted tells you: Sorry.  We are not in the business of buying\n"+
	"		items from customers.  Try down the road...\n");
  return 1;
}

