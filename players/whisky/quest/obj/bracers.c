
/* --------------------------------------------------------------------
   bracers : creator Whisky 
   They are nealy impossibel to get, because her owner is :
   ~whisky/quest/monster/danahra.c 
   Please don't copy them, because they are a kind of artifact.
   -------------------------------------------------------------------- */

#define env environment

inherit "/obj/armour";

void reset(int arg)
{
  ::reset(arg);
 
   if (arg == 0)
   { 
     set_name("bracers");
     set_alias("golden bracers");
     set_short("golden bracers");
     set_long("You see a pair of beautiful golden bracers.\n"+
              "They are enveloped by a golden aura and look\n"+
              "like they are build for a beautiful woman.\n");
     set_ac(1);
     set_weight(1);
     set_value(30000);
     set_type("arm");
   }
}

int wear_fun(object player)
{
    set_heart_beat(1);
    enable_commands();  
    return 1;
}

int remove_fun(object player)
{
    set_heart_beat(0);
    disable_commands();
    return 1;
}

void heal_slowly()
{
   if ( objectp(env()) && living(env()) ) 
        env()->heal_self(2);
}

void heart_beat()
{
    if (objectp(env()))
        heal_slowly();
}

int drop(string arg)
{
    disable_commands();
    return 0;
}

query_mage_wear()
{
   return 1;
}

query_monk_wear()
{
  return 1;
}

query_ninja_wear()
{
  return 1;
}

void fix_weight()
{
   weight = 1;
}

