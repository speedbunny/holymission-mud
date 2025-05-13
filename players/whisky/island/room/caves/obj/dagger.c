
/* stone dagger */

inherit "/obj/weapon";

void reset(int arg)
{
     ::reset(arg);
     if (!arg)
     {
         set_name("stone dagger");
         set_alias("dagger");
         set_short(query_name());
         set_long("A small dagger made of granite.\n");
         set_weight(1);
         set_class(8);
         set_type(1);
         set_value(60);
     }
}

 
