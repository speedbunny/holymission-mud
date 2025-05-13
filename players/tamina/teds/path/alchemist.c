inherit "room/room";

#include "/players/tamina/defs.h"

object list, potion;
string name, short_desc, mess;
int value, cast, heal, counter;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
    counter = 0;
    set_light(1);
    short_desc = "Ye Olde Alchemist Shoppe";
    long_desc =
"You are in Ye Olde Alchemist Shoppe.\n"+
"The shelves are packed with potions of every size and color.\n"+
"A list of prices hanging over the counter reads:\n\n"+
"    Potion of <Sobering>....................:   500 coins\n"+
"    Potion of Cure <light> wounds...........:  1000 coins\n"+
"    Potion of Cure <serious> wounds.........:  2000 coins\n"+
"    Potion of Cure <critical> wounds........:  5000 coins\n"+
"    Potion of Complete <heal>...............: 15000 coins\n\n"+
"By looking at the shelves, you might be able to see how many\n"+
"potions we have for sale.\n";

    dest_dir = ({
      TPATH + "road1", "south"
    });

    items = ({
  "shelves",
"They are filled with all manner of potions and vials and bottles and "+
"beakers of every known colour and shape...\n"+
"@@query_left@@",
  "potions",
"They are multitudinous in quantity, and size, and colour",
  "bottles",
"You can see them all over the Shoppe",
    });

    if (!list || !present(list))
    {
      list = CLO(OTH + "age_list");
      MO(list, TO);
    }
  }
}

void init() 
{
  ::init();
  add_action("order", "order"); 
  add_action("order", "buy");
}

int order(string str)
{
  if (counter > 10)
  {
    write("Sorry, but we have run-out of potions at the moment...\n");
    return 1;
  }
  if (TP->query_money() < value) 
  {
    write("That costs "+value+" coins, which you do not have.\n");
    return 1;
  }
  switch (str)
  {
    case "sober":
    case "sobering":
    potion = clone_object("/players/tamina/teds/inherits/potion");
    potion->set_name("sobering potion");
    potion->set_alias("sobering");
    potion->set_short("Potion of Sobering");
    potion->set_mess("You feel a shock in your head as the world clears.\n");
    potion->set_weight(1);
    potion->set_value(100);
    potion->set_heal(0);
    potion->set_into(-7);
    potion->set_pois(-5);
    value = 200;
    name = "sobering";
      break;

    case "light":
    potion = clone_object("/players/tamina/teds/inherits/potion");
    potion->set_name("light potion");
    potion->set_alias("light");
    potion->set_short("Potion of Cure Light Wounds");
    potion->set_mess("You feel a little better.\n");
    potion->set_weight(1);
    potion->set_value(150);
    potion->set_heal(30 + random(15));
    potion->set_into(3);
    potion->set_pois(-3);
    value = 1000;
    name = "light";
      break;

    case "serious":
    potion = clone_object("/players/tamina/teds/inherits/potion");
    potion->set_name("serious potion");
    potion->set_alias("serious");
    potion->set_short("Potion of Cure Serious Wounds");
    potion->set_mess("You feel better.\n");
    potion->set_weight(1);
    potion->set_value(600);
    potion->set_heal(60 + random(35));
    potion->set_into(6);
    potion->set_pois(-6);
    value = 2000;
    name = "serious";
      break;

    case "critical":
    potion = clone_object("/players/tamina/teds/inherits/potion");
    potion->set_name("critical potion");
    potion->set_alias("critical");
    potion->set_short("Potion of Cure Critical Wounds");
    potion->set_mess("You feel quite rejuvenated.\n");
    potion->set_weight(1);
    potion->set_value(1350);
    potion->set_heal(100 + random(50));
    potion->set_into(10);
    potion->set_pois(-10);
    value = 5000;
    name = "critical";
      break;

    case "heal":
    case "complete heal":
    potion = clone_object("/players/tamina/teds/inherits/potion");
    potion->set_name("complete heal potion");
    potion->set_alias("heal");
    potion->set_short("Potion of Complete Heal");
    potion->set_mess("You feel totally healed !!\n");
    potion->set_weight(1);
    potion->set_value(6000);
    potion->set_heal(1000);
    potion->set_into(15);
    potion->set_pois(-15);
    value = 15000;
    name = "heal";
      break;

    default:
    NFAIL("What is it you want to buy?\n");
    return 0;
  }
  if (TR(potion, TP))
  {
    write("You can't carry this extra weight.\n");
    return 1;
  }
  TP->add_money(-value);
  write("You pay "+value+" for a "+potion->SHT+".\n");
  say(TPN+" purchases a Potion.\n");
  counter++;
  return 1;
}

int query_counter()
{
  return counter;
}

string query_left()
{
  return "There are still "+(10-query_counter())+" potions on the shelves";
}
