

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("oaken ring");
         set_alias("ring");
         set_short("oaken ring");
         set_long( 
         "An old looking oaken ring.\n");
         set_type("finger");
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
int get()
{
this_player()->set_race("Oak-User");
return 1;
}
