
/* stick */

inherit "/obj/treasure";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_name("small magic stick");
        set_alias("stick");
        set_short(query_name());
        set_long("a small stick with a glowing silver top");
        set_weight(1);
        set_value(15);
     }
}

        
  
