
/* wood axe */

inherit "/obj/weapon";

void reset(int arg)
{
     ::reset(arg);
     if (!arg)
     {
         set_name("wood axe");
         set_alias("axe");
         set_short(query_name());
         set_long("A big iron axe to chop wood with it.\n");
         set_weight(3);
         set_class(13);
         set_value(150);
     }
}

 
