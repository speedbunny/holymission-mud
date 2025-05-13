
/* earrings */

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("shampoo's bells");
         set_alias("bells");
         set_short("Shampoo's bells");
         set_long( 
         "You see big silver bells, emitting a soft green glow.\n");
         set_type("hairpin");
         set_ac(0);
         set_weight(1);
         set_value(20000);
        modify_stat(0,3);
              modify_stat(1,3);
             modify_stat(4,3);
      }
}

int wear_fun(object pl)
{
     write("You hear a bell ringing.\n");
     return 1;
}

int remove_fun(object pl)
{
   return 1;
}

// its magic so wearable for all 

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
