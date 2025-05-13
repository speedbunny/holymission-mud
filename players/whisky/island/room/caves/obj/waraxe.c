
/* waraxe */

inherit "/obj/weapon";

void reset(int arg)
{
     ::reset(arg);
     if (!arg)
     {
         set_name("waraxe");
         set_alias("axe");
         set_short(query_name());
         set_long("A big iron axe to chop victims.\n");
         set_weight(2);
         set_class(16);
         set_value(450);
     }
}

 
