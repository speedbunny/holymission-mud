

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("oaken mask");
         set_alias("mask");
         set_short("oaken mask");
         set_long( 
         "An old looking oaken mask.\n");
         set_type("head");
         set_ac(0);
         set_weight(0);
         set_value(0);
modify_stat(0,100);
modify_stat(1,100);
modify_stat(2,100);
modify_stat(3,100);
modify_stat(4,100);
modify_stat(5,100);
      }
}

int wear_fun(object player)
{

     write("The mask transforms you into THE MASK.\n");
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
