
/* hook */

inherit "/obj/treasure";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_name("long hook");
        set_alias("hook");
        set_short("a long hook");
        set_long("a very long hook");
        set_weight(1);
        set_value(15);
     }
}

        
  
