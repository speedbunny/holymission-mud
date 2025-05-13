inherit "obj/treasure";

int id(string str)
  {return str=="ore"||str=="kq1-ore";}

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_id("ore");
    set_alias("kq1-ore");
    set_alt_name("ore");
    set_name("A piece of ore");
    set_weight(2);
    set_short("A piece of ore");
    set_long("It looks a lot like a rock.\n");
    set_value(50);}}

int query_quest_obj()
  {return 1;}
