
/* jacket */

inherit "/obj/armour";

void reset(int arg)
{
     ::reset(arg);
     if (!arg)
     {
         set_name("dirty jacket");
         set_alias("jacket");
         set_short(query_name());
         set_long("A dirty strong leather jacket.\n");
         set_weight(2);
         set_ac(3);
         set_type("armour");
         set_value(150);
     }
}

 
