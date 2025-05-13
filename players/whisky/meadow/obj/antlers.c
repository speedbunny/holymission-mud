inherit "/obj/armour";

void reset(int arg) 
{
    ::reset(arg);
    if (arg == 0) 
    {
      set_name("antler");
      set_alias("antlers");
      set_type("helmet");
      set_ac(1);
      set_long("They look like they came from a powerful buck.\n");
      set_weight(2);
      set_value(150);
    }
}


int wear_fun(object tp)
{
   write("Steam boils out of your nostrils !\n");                   
   say("Steam boils out of "+this_player()->query_name()+"'s nostrils.\n");
   return 1;
   }

string short()
{
   if (query_worn())
       return "Deer antlers (madly worn)";
   else
       return "Deer antlers";    
}
