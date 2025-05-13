inherit "/obj/armour";

void reset(int arg) 
{
    ::reset(arg);
    if (arg == 0) 
    {
      set_name("Girdle of stormgiant strength");
      set_alias("girdle");
      set_short("Girdle of stormgiant strength");
      set_type("belt");
      set_ac(1);
      set_long(
          "This belt is made of an undetermineabel material with glowing\n"+
          "red runes on the surface.\n");
      set_weight(3);
      set_value(45000);
      modify_stat(0,10);
    }
}

int wear(string arg)
{
    int gnr;

    if(present(arg,this_player())!=this_object()) return 0;

    gnr=this_player()->query_guild();
    if(!(gnr == 3 || gnr == 11))
    {
        write("This is too much of a warriors armor!\n");
        return 1;
    }
    return ::wear(arg);
} 
