
/* liveoak staff */

inherit "/obj/weapon";
int  heal_me;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         heal_me = 0;
         set_name("oaken staff");
         set_alias("staff");
         set_short(query_name());
         set_long("The staff of a live oak.\n");
         set_weight(1);
         set_value(30000);
         set_type(1); /* crushing */
         enable_commands();
     }
}

int weapon_class()
{
    if (environment())
        return 4 + environment()->query_wis()/3; 
    return 0;
}

int wield(string arg)
{
    if (::wield(arg))
    {
        heal_me = 1;
        set_heart_beat(1);
    }
  return 1;
}

int do_unwield(string arg)
{
     if (::do_unwield(arg))
     {
         heal_me = 0;
         set_heart_beat(0);
     }
  return 1;
} 

int drop()
{
    return (heal_me = 0);
}
    
void heart_beat()
{
     if (heal_me && objectp(environment()))
         environment()->heal_self(1 + environment()->query_wis()/10);
}
 
