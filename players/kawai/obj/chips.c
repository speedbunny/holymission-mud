inherit "obj/treasure";

int count;

int id(string str)
  {return str=="kq1-chips"||str=="chips"||str=="casino chips";}

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {count=5000;
    set_id("kq1-chips");
    set_alias("chips");
    set_name("a stack of casino chips");
    set_alt_name("casino chips");
    set_weight(3);
    set_short("Some casino chips");
    set_value(0);}}

int query_quest_obj()
  {return 1;}

int query_chips()
  {return count;}

void add_chips(int arg)
  {count=count+arg;}

void long() 
  {write("You have "+count+" chips.\n");}

int drop(string str)
  {write("As you let go of the chips, they scatter and roll away in every direction!\n");
  destruct(this_object());
  return 1;}


