/* Uglymouth 940330, changed move_object to transfer in buy_fnc */
inherit "room/room";
#include "/players/meecham/def.h"
reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Apothecary";
/*
    long_desc=
      "This tent was rented by an alchemist who has set up an apothecary.\n\
You can buy the following potions:\n\
\n\
      1. Potion of cure light wounds...........500 coins\n\
      2. Potion of cure serious wounds........1000 coins\n\
      3. Potion of cure critical wounds.......1500 coins\n\
      4. Potion of cure complete heal.........5000 coins\n\
\n\
Just <buy #>.\n";
*/
    long_desc="This used to be a shop that sold some sort of alchemy potions but it seems that the alchemist couldn`t afford the rent so it is empty now.\n(I dont really know why he could afford to pay the rent, did you see how much he charged?\n";
    dest_dir=({
      PM+"tower/bazaar","east",
    });
  }
}
 
init()
{
  ::init();
/*
  add_action("buy_fnc","buy");
*/
}
 
buy_fnc(str)
{
  string mess1,mess2,potion;
  int cost;
  if(!str) write("Yes, yes, but buy what?\n");
  else
  {  
    switch(str)
    {
      case "1":
        mess1="You buy a potion of cure light wounds.\n";
        mess2=TPN+" buys a potion of cure light wounds.\n";
        cost=500;
        potion="potion1";
        break;
 
      case "2":
          mess1="You buy a potion of cure serious wounds.\n";
          mess2=TPN+" buys a potion of cure serious wounds.\n";
          cost=1000;
          potion="potion2";
          break;
 
      case "3":
        mess1="You buy a potion of cure critical wounds.\n";  
        mess2=TPN+" buys a potion of cure critical wounds.\n";
        cost=1500;
        potion="potion3";
        break;
 
      case "4":
        mess1="You buy a potion of complete heal.\n";
        mess2=TPN+" buys a potion of complete heal.\n";
        cost=5000;
        potion="potion4";
        break;
 
      default:
        write("We don't have that.\n");
        return 1;
        break;
    }
    if(TP->query_money()<cost)
      write("You don't have enough money.\n");
    else
    {
      write(mess1);
      say(mess2);
      TP->add_money(-cost);
      transfer(CO(PM+"items/"+potion),TP);
    }
  }
  return 1;
}
 
 
