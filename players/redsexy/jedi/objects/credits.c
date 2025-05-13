inherit "obj/treasure";

int count;
object snip;

int id(string str)
  {return str=="red-credits"||str=="credits"||str=="gambling credits"||str=="carrier";}

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {count=5000;
    set_id("red-credits");
    set_alias("credits");
    set_name("carrier");
    set_alt_name("chips");
    set_weight(3);
    set_short("A small black credit carrier");
    set_value(0);}}

int query_credits()
  {return count;}

void add_credits(int arg)
  {count=count+arg;}

void long() 
  {write("You have "+count+" credits.\n");}

int drop(string str)
  {write("Before the carrier leaves your hands a snip jumps from out of nowhere and steals any remaining credits!\n");
   destruct(this_object());
   return 1;}


