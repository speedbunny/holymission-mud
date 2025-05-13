
/* robe */

inherit "/obj/armour";

void reset(int arg)
{
     ::reset(arg);
     if (!arg)
     {
         set_name("black robe");
         set_alias("robe");
         set_short(query_name());
         set_long("A long, black robe.\n");
         set_weight(1);
         set_ac(1);
         set_type("robe");
         set_value(75);
     }
}

 
