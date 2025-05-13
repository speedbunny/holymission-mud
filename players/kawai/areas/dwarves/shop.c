inherit "room/room";

#include <lw.h>
#define TO this_object()
#define TP this_player()

string store_room;
object store_ob;
int sleeping;

string owner_desc() 
  {if(sleeping) 
    {return "The owner is sound asleep on the counter!\n";}
  return "The old dwarf stands ready to serve you! (although he looks "+
  "tired enough to collapse at any moment!)...\n";}

void reset(int arg)
  {clone_list=({1,1,"owner","obj/monster",({"set_name","the owner",
  "set_level",25,"set_alias","owner"})});
  sleeping=1;
  property ="no_fight";
  short_desc="The shop";
  set_light(1);
  long_desc="You are in the main shop of the dwarf village.   The shop is small "+
  "and dusty, and a sign hangs above the counter.\n";
  dest_dir=({"players/kawai/areas/dwarves/village4","west"});
  items=({"sign","Try reading it",
  "shop","You are standing in it",
  "counter","The counter is old an worn from years of adventurers like you carelessly\n"+
  "dropping their equipment on it without consideration for those who crafted\n"+
  "such a fine piece of furniture!",
  "furniture","Just a counter"});
  store_room="/room/store";
  catch(store_room->a_load_fun());
  store_ob=find_object(store_room);
  ::reset(arg);}

void init()
  {::init();
  add_action("list","list");
  add_action("wake","wake");
  add_action("readsign","read");
  add_action("buy","buy");
  add_action("sell","sell");
  add_action("value","value");
  add_action("lk","look");
  add_action("lk","l");
  add_action("nk","kill");}

status do_sell(object ob)
  {int value, do_destroy, weight;
  if(!(value=ob->query_value()))
    {write(ob->short()+" has no value.\n");
    return 1;}
  if(environment(ob)==TP)
    {if(ob->drop()) 
      {write("I can't take it from you.\n");
      return 1;}
    weight=ob->query_weight();
    TP->add_weight(-weight);}
  if(value>2000 || ob->query_quest_item())
    {do_destroy=1;}
  if(value>1000)
    {write("The shop is low on money ...\n");
    value=1000;}
  write("You get "+value+" gold coins.\n");
  say(TP->query_name()+" sells "+ob->short()+".\n");
  TP->add_money(value);
  if (do_destroy) 
    {write("The valuable item is hidden away.\n");
    destruct(ob);
    return 1;}
  store_ob->store(ob);
  return 1;}

status nk(string str) 
  {if(!str) 
    {notify_fail("Kill what?\n");
    return 0;}
  if(str=="owner"||str=="dwarf"||str=="old dwarf")
    {write("Sorry, this is portion of the mud is ethically coded.  Bashing\n"+
    "on old, helpless store owners is simply not allowed.  If you\n"+
    "MUST kill something, I'm sure you can find a small child or\n"+
    "woman around.\n");
    return 1;}
  return 0;}

status lk(string str)
  {if(!str) 
    {notify_fail("Look AT what?\n");
    return 0;}
  else if(str=="at owner"||str=="at dwarf"||str=="at old dwarf")
    {writelw("The old dwarf who runs this shop, while sleeping most of the time, "+
    "still looks like he has a few more fights left in him.  You can imagine "+
    "him talking for long hours about the old wars against the Grey Elves "+
    "years ago.\n"+owner_desc());
    return 1;}
  else
    {return 0;}}

status readsign(string str)
  {if(!str)
    {notify_fail("Read what?\n");
    return 0;}
  if(str=="sign")
    {write("Gunther's Shop o' Stuff!  Best wares in town!\n"+
    "Things you can do:\n"+
    "'buy item', 'sell item', 'sell all', 'list', 'list weapons'\n"+
    "'list armours' and 'value item'.\n");
    return 1;}
  else
    {return 0;}}

status wake(string str)
  {if(!str)
    {notify_fail("Wake whom?\n");
    return 0;}
  else if(str=="dwarf"||str=="owner")
    {if(!sleeping)
      {writelw("The owner looks at you and exclaims: What?!  "+
      "I'm not that old!  You don't think I can stay awake for 5 "+
      "minutes! Sheesh!  Kids today....Ugh!  Even worse!  A "+
      TP->query_race()+"!!  What's "+
      "this world coming to!  A decent dwarf can't run a shop without "+
      "being bothered by wandering hooligans.....<mumble>.\n");
      return 1;}
    writelw("As you nudge the old dwarf, he bounces up from his sleep and "+
    "starts reciting his sales pitch! \n"+
    "Old Dwarf tells you: Hello, there!  Sorry about that, I was "+
    "just...um...checking the counter for scratches!  Well, I guess "+
    "your interested in our fine wares, eh?  Well, let me just tell you "+
    "that are lightning fast courier fleet can get you any item from "+
    "any of the main shops throughout the land!  We even have good "+
    "prices too!  Feel free to look around! ");
    sleeping=0;
    return 1;}
  else
    {return 0;}}

status list(string str)
  {if(sleeping)
    {writelw("You mindlessly ask about the inventory, only to realize "+
    "that the store owner is sound asleep on the counter!\n");
    return 1;}
  write("The store owner tells you: Here's whats available...\n");
  store_ob->inventory(str);
  return 1;}

status buy(string str)
  {if (!str) 
    {notify_fail("Buy what?\n");
    return 0;}
  if(sleeping)
    {writelw("You mindlessly ask to buy something, only to realize "+
    "that the store owner is sound asleep on the counter!\n");
    return 1;}
  if(TP->query_ghost())
    {write("You have no body to carry items with you.\n");
    return 1;}
  store_ob->buy(str);
  return 1;}

status sell(string str)
  {object ob,*in;
  int i,do_destroy;  
  if(!str) 
    {notify_fail("Sell what?\n");
    return 0;}
  if(sleeping) 
    {writelw("You mindlessly ask to sell something, only to realize "+
    "that the store owner is sound asleep on the counter!\n");
    return 1;}
  if(str=="all")
    {in=all_inventory(TP);
    for (i=0;i<sizeof(in);i++)
      {if(!in[i]->drop() && in[i]->query_value())
        {do_sell(in[i]);}}
    write("Ok.\n");
    return 1;}
  if(!(ob=present(str,TP))&&!(ob=present(str,TO)))
    {write("No such item ("+str+") here.\n");
    return 1;}
  do_sell(ob);
  return 1;}

status value(string str)
  {object ob;
  int i,z;
  if(!str) 
    {notify_fail("Value what?\n");
    return 0;}
  if(sleeping)
    {writelw("You mindlessly ask for an appraisal, only to realize "+
    "that the store owner is sound asleep on the counter!\n");
    return 1;}
  z=0;
  if(!(ob=present(str,TP)) && !(ob=present(str,TO))) 
    {z=1;}
  if(z && !(ob=present(str,store_ob)))
    {write("No such item ("+str+") here or in the store.\n");
    return 1;}
  if(z)
    {write("The " + ob->short() + " would cost you " + ob->query_value() * 2
    +" gold coins.\n");
    return 1;}
  if(!(i=ob->query_value()))
    {write(ob->short()+" has no value.\n");
    return 1;}
  write("You would get "+i+" gold coins.\n");
  return 1;}

