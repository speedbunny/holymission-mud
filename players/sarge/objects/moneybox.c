inherit "obj/treasure";

string location;

int get()
  {return 1;}

int drop()
  {return 1;}

 
void reset(int arg)
  {if(arg)
    return;
  set_id("box");
  set_alias("golden box");
  set_weight(0);
  set_value(1);
  set_short("A small golden box");
  set_long("This box will generate money for you.\n"+
  "don't abuse it!!!. Twist nob to work.\n"+
  "WARNING: PLAYERS WILL TAKE DAMAGE IF THEY TWIST THIS NOB.\n"+
  "ONLY WIZARDS ARE ALLOWED TO USE THIS ITEM!!\n");}

void init()
  {::init();
  add_action("twist",   "twist");}

status twist(string str)
  {if(str!="knob")
    {notify_fail("Twist what?\n");
    return 0;}
  if(this_player()->query_level()>29)
    {this_player()->add_money(10000);
    return 1;}
  else
    {write("You are not powerful enough to use this item!\n");
    return 1;}}

string query_auto_load()
  {return "players/sarge/objects/moneybox:";}
