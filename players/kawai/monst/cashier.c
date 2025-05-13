inherit "obj/monster";
#include <lw.h>

void reset(int arg)
  {::reset(arg);
  if(!arg) 
    {set_name("Cashier");
    set_level(25);
    set_hp(3000);
    set_alias("cashier");
    set_race("dwarf");
    set_gender(2);
    set_alt_name("dwarf");
    set_short("A Cashier");
    set_wc(25);
    set_ac(20);
    set_gender(2);
    set_size(2);
    set_wimpy(0);
    set_long(lw(
    "The cashier strolls around the casino, offering additional "+
    "chips to those who can afford.  Each chip is worth 1 coin "+
    "and can be purchased in lots of 5000.  You may 'buy chips' "+
    "if you need them.\n"));}}

void init()
 {::init();
 add_action("buy","buy");}

status buy(string str) 
  {object chips;
  if(!str)
    {notify_fail("Buy what?\n");
    return 0;}
  if(str!="chips")
    {notify_fail("You can't buy that here!\n");
    return 0;}
  else
    {if(present("kq1-chips",this_player()))
      {write("The cashier says:  Sorry, but you already have some chips.  Come\n"+
      "back when you really need some more.\n");
      return 1;}
    else if(this_player()->query_money()<5000)
      {write("The cashier says:  Sorry, but you simply don't have enough\n"+
      "money to buy any.  I can only sell in lots of 5000.\n");
      return 1;}
    else
      {if(transfer(chips=clone_object("players/kawai/obj/chips"),
      this_player()))
        {write("The cashier says:  Sorry, it seems that you can't carry\n"+
        "the chips if you purchase them.  Come back later when you can.\n");
        if(chips)
          {destruct(chips);}        
        return 1;}
      else
        {this_player()->add_money(-5000);
        write("The cashier thanks you for your purchase.\n");
        return 1;}}}
  return 0;}


