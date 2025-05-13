inherit "/room/room";
#include "/players/tamina/defs.h"

object newspaper, top_list;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

  set_light(1);
  short_desc = "The Drunken Squire Pub";
  long_desc = 
"You are in the Drunken Squire Pub.\n"+	
"  You can order drinks here: \n\n"+
"1.   Dark Ale                :  20 coins\n"+
"2.   Super Mud       [Sober] :  90 coins \n"+
"3.   Shockwave               : 100 coins \n"+    
"4.   Merlin's Special [SP]   : 150 coins \n"+
"5.   King's Doom             : 200 coins\n\n"+
"  Or you can order food here:\n\n"+
"6.   Alka Seltzer    [Sober] :  75 Coins\n"+
"7.   Exquisite Meal          : 400 Coins\n"+
"8.   Grand Banquet           : 750 Coins\n\n"+
"   You can also <buy number> as well.\n";

      dest_dir = ({
    TPATH + "road2", "south",
    });

/*
  if (!top_list || !present(top_list)) 
  {
    top_list = CLO(OTH + "list");
    MO(top_list, TO);
  }
  if (!newspaper || !present(newspaper)) 
  {
    newspaper = CLO("obj/newspaper");
    MO(newspaper, TO);
  }
*/
}

void init() 
{
  ::init();
  add_action("order", "order");
  add_action("order", "buy");
}

int order(string str) 
{
  string name, short_desc, mess, type;
  int value, cost, strength, heal;

  if (str == "ale" || str == "dark" || str == "1")
  {
    name = "Dark Ale";
    mess = "That's good ale.";
    heal = 9;
    value = 20;
    strength = 2;
    type = "alco";
  } 
  else
  if (str == "super" || str == "mud" || str == "2")
  {
    name = "Super Mud";
    mess = "Your head spins violently as the sobering effects hit you.";
    heal = 0;
    value = 90;
    strength = -5;
    type = "alco";
  }
  else
  if (str == "shock" || str == "shockwave" || str == "3")
  {
    name = "Shockwave";
    mess = "An electric shock jolts you into drunkeness.";
    heal = 20;
    value = 100;
    strength = 11;
    type = "alco";
  } 
  else
  if (str == "merlin's" || str == "special" || str == "4")
  {
    name = "Merlin's Special";
    mess = "You feel your Magic Mana power surging through your veins.";
    heal = 75 + random(41);
    value = 150;
    strength = 6;
    type = "sp";
  } 
  else
  if (str == "king's doom" || str == "doom" || str == "5")
  {
    name = "King's Doom";
    mess = "As the shot hits your stomach, you almost pass out !";
    heal = 35 + random(16);
    value = 200;
    strength = 15 + random(5);
    type = "alco";
  }
  else
  if (str == "alka" || str == "seltzer" || str == "6")
  {
    name = "Alka Seltzer";
    mess = "Aaaaahhhh.....You feel quite refreshed !";
    heal = 0;
    value = 75;
    strength = -3;
    type = "food";
  }
  else
  if (str == "exquisite" || str == "meal" || str == "7")
  {
    name = "Exquisite Meal";
    mess = "You feel absolutely satiated after that beautiful meal !";
    heal = 20;
    value = 400;
    strength = 13;
    type = "food";
  }
  else
  if (str == "grand" || str == "banquet" || str == "8")
  {
    name = "Grand Banquet";
    mess = "You do not feel like eating again for ages after that Banquet !!";
    heal = 20 + random(16);
    value = 750;
    strength = 19;
    type = "food";
  }
  else
  {
    notify_fail("The Squire says: Sorry, we don't serve that here...\n");
    return 0;
  }

  if (TP->query_money() < value) 
  {
    write("That costs "+value+" gold coins, which you don't have.\n");
    return 1;
  }
  if (type == "alco" || type == "sp")
  {
    if (strength > (TP->LVL + 3)) 
    {
      say(TPN+" orders a "+name+", and spews it all over you!\n");
      write("You order a "+name+", try to drink it,\n"+
            "but splutter it all over the room!\n");
      return 1;
    }
    if (!this_player()->drink_alcohol(strength)) 
    {
      write("The Squire says: I think you've had enough.\n");
      say(TPN+" asks for a " +name+ " but the Squire refuses.\n");
      return 1;
    }
  }
  else
  if (type == "food")
  {
    if (strength > (TP->LVL + 3)) 
    {
      say(TPN+" orders a "+name+", but gags on the amount of food.\n");
      write("You order a "+name+", try to gulp it down,\n"+
            "but cough it everywhere !\n");
      return 1;
    }
    if (!this_player()->eat_food(strength))
    {
      write("The Squire says: You don't look as though you can eat any more...\n");
      say(TPN+" looks as though "+TP->QPRO+" is going to burst with food!!\n");
      return 1;
    }
  }
  write("You pay "+value+" coins for a "+name+".\n");
  write(mess+"\n");
  say(TPN+" orders, and drinks a "+name+".\n");

  TP->add_money(-(value + random(50)));
  if (type == "sp")
    TP->restore_spell_points(heal);
  else TP->heal_self(heal);
  return 1;
}
