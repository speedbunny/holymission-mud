inherit "obj/monster";
#include <lw.h>

void reset(int arg)
  {::reset(arg);
  if(!arg) 
    {set_name("Cashier");
    set_level(25);
    set_hp(3000);
    set_alias("cashier");
    set_race("corellian");
    set_gender(2);
    set_alt_name("corellian");
    set_short("A Cashier");
    set_wc(25);
    set_ac(20);
    set_gender(1);
    set_size(2);
    set_wimpy(0);
    set_long(lw(
    "The Corellian gambler stares at you slyly, offering to sell "+
    "credits if you want to gamble in the cantina. A credit costs "+
    "1 coin and can be purchased in lots of 5000.  You may 'buy credits' "+
    "if you fancy your chances on any of the tables here.\n"));}}

void init()
 {::init();
 add_action("buy","buy");}

status buy(string str) 
  {object credits;
  if(!str)
    {notify_fail("Buy what?\n");
    return 0;}
  if(str!="credits")
    {notify_fail("You can't buy that here!\n");
    return 0;}
  else
    {if(present("red-credits",this_player()))
      {write("The cashier says:  If you already have a holder I can't give you anymore credits. \n"+
      "Get rid of it first, carrying two would only arouse suspicion.\n");
      return 1;}
    else if(this_player()->query_money()<5000)
      {write("The Corellian shrugs and says:  Sorry, but you simply don't have enough\n"+
      "money to buy any.  I can only sell in lots of 5000.\n");
      return 1;}
    else
      {if(transfer(credits=clone_object("/players/redsexy/jedi/objects/credits"),
      this_player()))
        {write("The Correlian laughs, saying:  You can't carry\n"+
        "the credit holder if you buy it.  Come back later when you can.\n");
        if(credits)
          {destruct(credits);}        
        return 1;}
      else
        {this_player()->add_money(-5000);
        write("The cashier thanks you for your purchase.\n");
        return 1;}}}
  return 0;}


