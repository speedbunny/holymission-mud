
/* hat */

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("straw hat");
         set_alias("hat");
         set_type("helmet");
         set_short(query_name());
         set_long("An old, worn out straw hat.\n");
         set_value(10);
         set_weight(1);
      }
}

