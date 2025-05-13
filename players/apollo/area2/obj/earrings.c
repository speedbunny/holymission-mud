
/* earrings */

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("jeweled earrings");
         set_alias("earrings");
         set_short("jeweled earrings");
         set_long( 
         "You see big golden earrings, emitting a soft blue glow.\n");
         set_type("ear");
         set_ac(0);
         set_weight(1);
         set_value(35000);
/*
         modify_stat(5,1);
         modify_stat(2,1)
         modify_stat(4,2)
*/
      }
}

int wear_fun(object player)
{

     write("You can hear a bell in the distance.\n");
     return 1;
}

int remove_fun(object player)
{
   return 1;
}

int query_monk_wear() 
{ 
    return 1; 
}

int query_mage_wear() 
{ 
    return 1; 
}

int query_ninja_wear() 
{ 
    return 1; 
}
