inherit "/room/room";
#include "/players/tamina/defs.h"
#define MAX_LIST        30
#define MAX_SHOP_VALUE 1000

int value;
string name_of_item;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

    set_light(1);
    short_desc = "Store room for the magic shop"; 
    long_desc = "All things from the magic shop are stored here.\n"; 

    "/players/tamina/teds/random_magic"->make_item(TO, random(30));
    "/players/tamina/teds/random_magic"->make_item(TO, random(30));
    "/players/tamina/teds/random_magic"->make_item(TO, random(30));

  if (!present("identify")) 
  {
    MO(CLO("/players/tamina/teds/items/identify"), TO);
  }
  if (!present("staff")) 
  {
    MO(CLO("/players/tamina/teds/items/cure_staff"), TO);
  }
  if (!present("ball")) 
  {
    MO(CLO("/players/tamina/teds/items/crystal_ball"), TO);
  }
  if (!present("wand of lightning")) 
  {
    MO(CLO("/players/tamina/teds/wands/lightning"), TO);
  }
  if (!present("bag")) 
  {
    object bag;
    bag = CLO("/players/tamina/teds/items/bag_of_holding");
    MO(bag, TO);
  }
}

inventory(str) 
{
  object ob;
  int max;
  if (!str)
    str = "all";
  max = MAX_LIST;
  ob = first_inventory(TO);
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
  int value;
  value = ob->query_value();
  if (value) 
  {
    write(value * 2+value+":\t"+ob->SHT+".\n");
  }
}

value(item) 
{
  name_of_item = present(item);
  if (!name_of_item) 
  {
    return 0;
  }
  value = name_of_item->query_value();
  if (!value) 
  {
    return 0;
  }
  write("The "+item+" would cost you "+((value * 2)+value)+" coins.\n");
  return 1;
}

buy(item) 
{
  name_of_item = present(item);
  if (!name_of_item) 
  {
    write("No such item in the store.\n");
    return 0;
  }
  value = name_of_item->query_value();
  if (!value) 
  {
    write("That item has no value.\n");
    return 0;
  }
  value = (value * 2) + value;
  if (TP->query_money() < value) 
  {
    write("It would cost you "+value+" gold coins, which you don't have.\n");
    return 0;
  }
  if (transfer(name_of_item, TP)) 
  {
    write("You can't carry that much.\n");
    return 1;
  }
  TP->add_money(-value);
  TR(name_of_item, TP);
  write("Here is your "+CAP(item)+".\n");
  write("Thank you for doing business.\n");
  say(TPN+" buys "+CAP(item)+".\n");
  return 1;
}

store(item) 
{
  string short_desc;
  object ob;

  short_desc = item->SHT;
  ob = first_inventory(TO);
  while(ob) 
  {
    if (ob->SHT == short_desc) 
    {
            /* Move it before destruct, because the weight
               has already been compensated for. */
      MO(item, TO);
      destruct(item);
      return 0;
    }
    ob = next_inventory(ob);
  }
  MO(item, TO);
}
