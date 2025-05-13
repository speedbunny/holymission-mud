inherit "room/room";

#include "/players/tamina/defs.h"
  object ob, wand;
  int in_progress;
  string name;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return;

  set_light(1);
  short_desc = "Arnold's Re-Charging Store";
  long_desc = 
    "You are in Arnold's Re-Charging Store.\n"+
    "This is where Arnold the Artificer re-charges all\n"+
    "those wonderful wands he has given out.\n"+
    "There is a sign on the wall.\n";

  dest_dir = ({ 
    TPATH + "road1", "east" 
  });

  items = ({
  "sign",
"Perhaps you should read it...?",
  });

  ob = present("Arnold");
  if (!ob)
  {
    ob = clone_object(TMONS + "arnold");
    move_object(ob, this_object());
  }
}

void init()
{
  ::init();
  add_action("_read", "read");
  add_action("_identify", "identify");
  add_action("_charge", "charge");
}

int _read(string str)
{
  if (!str || str != "sign")
  {
    notify_fail("Read what?\n");
    return 0;
  }
  else
  {
    write(
"\n                 Arnold's World Renowned Artificer's Shoppe\n"+
"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n"+
"    Costs of re-charging wands:\n\n"+
"    Clear Wand         1000 coins\n"+
"    Platinum Wand      1200 coins   I can also Identify  magical things,\n"+
"    Short Ruby Wand    1400 coins      for a cost of       1500 coins\n"+
"    Thin Glass Wand    1700 coins       Just type 'identify <item>'\n"+
"    Silver Wand        2500 coins\n"+
"    Deep Blue Wand     3000 coins\n\n"+
"        Just <charge wand> will do.\n\n"+
"    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    say(TPN+" reads the sign.\n");

    return 1;
  }
}

int _identify(string str)
{
  object obj, memb;
  int weight;
  string info;

  if (!ob)
  {
    write("But Arnold is not here to identify your "+CAP(str)+".\n");
    return 1;
  }
  if (!str)
  {
    notify_fail("Arnold says: Identify what?\n");
    return 0;
  }
  obj = present(str, TP);
  if (!obj)
  {
    if (present(str, environment(TP)))
    {
      write("Arnold says: Can you please pick up the "+str+"?\n");
      write("Arnold says: I can't identify it unless you carry it.\n");
      return 1;
    }
    write("Arnold says: But you aren't carrying a "+CAP(str)+"...\n");
    return 1;
  }
  if (TP->query_money() < 1500)
  {
    write("Arnold says: Hey!  You don't have enough money to pay me!!\n"+
	  "             I am not going to Identify this for you.\n");
    return 1;
  }  
  weight = obj->query_weight();
  switch(weight)
  {
    case 0:
     write("Arnold says: This object weighs nothing.\n");
    break;
    case 1:
     write("Arnold says: This object weighs almost nothing.\n");
    break;
    case 2 .. 3:
     write("Arnold says: This object is reasonably light\n");
    break;
    case 4 .. 6:
     write("Arnold says: This object is pretty heavy.\n");
    break;
    case 7 .. 9:
     write("Arnold says: OOoffh!  This object is very heavy !!\n");
    break;
    case 10:
     write("Arnold says: Aaargghhh! This thing weighs a ton !!!\n");
     write("Arnold nearly falls over due to the weight of your "+CAP(str)+"\n");
    break;
    default:
     write("Arnold says: It is too heavy for me to even pick up !!\n");
    break;
  }
  info = obj->query_info();
  if (info)
  {
    write("Arnold tells you the following information about your "+CAP(str)+":\n");
    write(info);
  }
  TP->add_money(-1500);
  return 1;
}

int _charge(string str)
{
  wand = present("wand", this_player());
  name = wand->query_short();

  if (!ob)
  {
    write("But Arnold is not here to charge your wand.\n");
    return 1;
  }
  if (!str || str != "wand")
  {
    notify_fail("Arnold says: You want me to charge what?\n");
    return 0;
  }
  if (!wand)
  {
    write("Arnold says: But you don't have a wand to charge, "+TPN+"...\n");
    return 1;
  }
  if (in_progress)
  {
    write("But Arnold is already re-charging a wand at the moment.\n");
    return 1;
  }
  switch(name)
  {
    case "A Clear Wand":
     if (TP->query_money() < 1000)
     {
       write("Arnold says: But you don't have enough money, "+TPN+".\n");
       return 1;
     }
    break;
    case "A Platinum Wand":
     if(TP->query_money() < 1200)
     {
       write("Arnold says: But you don't have enough money, "+TPN+".\n");
       return 1;
     }
    break;
    case "A Short Ruby Wand":
     if(TP->query_money() < 1400)
     {
       write("Arnold says: But you don't have enough money, "+TPN+".\n");
       return 1;
     }
    break;
    case "A Thin Glass Wand":
     if(TP->query_money() < 1700)
     {
       write("Arnold says: But you don't have enough money, "+TPN+".\n");
       return 1;
     }
    break;
    case "A Silver Wand":
     if(TP->query_money() < 2500)
     {
       write("Arnold says: But you don't have enough money, "+TPN+".\n");
       return 1;
     }
    case "A Deep Blue Wand":
     if(TP->query_money() < 3000)
     {
       write("Arnold says: But you don't have enough money, "+TPN+".\n");
       return 1;
     }
    break;
  }
  write("Arnold takes your wand from you, and disappears\n"+
        "from view...\n");
    say("Arnold the Artificer takes a wand from "+TPN+", \n"+
        "and disappears through the back of the shop.\n");

  move_object(ob, "/players/tamina/teds/storage");
  call_out("charge", 3);
  in_progress = 1;

  return 1;
}

int charge()
{
  tell_room(environment(TP), 
  "You hear a hissing, and clanging of metals...\n");
  call_out("reappear", 3);
  return 1;
}

reappear()
{
  tell_room(environment(TP), 
  "Arnold the Artificer returns with your wand re-charged.\n");
  move_object(ob, this_object());
  wand->set_charges(5 + random(3));

  switch(name)
  {
    case "A Clear Wand":
     TP->add_money(-1000);
    break;
    case "A Platinum Wand":
     TP->add_money(-1200);
    break;
    case "A Short Ruby Wand":
     TP->add_money(-1400);
    break;
    case "A Thin Glass Wand":
     TP->add_money(-1700);
    break;
    case "A Silver Wand":
     TP->add_money(-2500);
    break;
    case "A Deep Blue Wand":
     TP->add_money(-3000);
    break;
  }
  write("Arnold says: Thank you for doing business "+TPN+".\n");
  in_progress = 0;
  return 1;
}  
