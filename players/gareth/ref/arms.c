
/* arms of light */

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("arms of light");
         set_alias("arms");
         set_short("arms of light");
         set_long( 
         "You see some strong, iron arm splints, emitting a soft glow.\n");
         set_type("arm");
         set_ac(1);
         set_arm_light(3);
         set_weight(1);
         set_value(4000);
      }
}

int query_mage_wear() { return 1; }
int query_monk_wear() { return 1; }
int query_ninja_wear() { return 1; }
