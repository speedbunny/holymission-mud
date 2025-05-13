
/* boot */

inherit "/obj/armour";

void reset(int arg)
{
     ::reset(arg);
     if (!arg)
     {
         set_name("fur boots");
         set_alias("boots");
         set_short(query_name());
         set_long("Boods made of bearfur.\n");
         set_weight(1);
         set_ac(1);
         set_type("boot");
         set_value(80);
     }
}

 
