
/* cloak */

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("wool cloak");
         set_alias("cloak");
         set_type("cloak");
         set_short(query_name());
         set_long("An old, worn out wool cloak.\n");
         set_value(100);
         set_weight(3);
      }
}

