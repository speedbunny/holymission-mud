
/* helmet */

inherit "/obj/armour";

void reset(int arg)
{
     ::reset(arg);
     if (!arg)
     {
         set_name("leather helmet");
         set_alias("helmet");
         set_short(query_name());
         set_long("A strong leather helmet.\n");
         set_weight(1);
         set_ac(1);
         set_type("helmet");
         set_value(120);
     }
}

 
