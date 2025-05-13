inherit "/obj/armour";

object robe;

query_mage_wear() { return 1; }
query_summoner_wear() { return 1; }

void reset(int arg) 
{
    ::reset(arg);
    if (arg == 0) 
    {
      log_file("ILLEGAL", "Archrobe cloned from " +
               previous_object()->query_name() +
               " to " + this_player()->query_real_name() + ".\n");
      log_file("ILLEGAL", "Cloned in the room " +
               file_name(environment(this_player())) + "\n");
      set_name("Robe of the Archmagi");
      set_short("Robe of the Archmagi");
      set_type("robe/armour");
      set_ac(3);
      set_long("This is a nice crafted silk robe with magic rune patterns.\n");
      set_weight(1);
      set_value(70000);
    }
}

int wear_fun(object pl)
{
    int gnr;
    gnr=pl->query_guild();
    if(gnr == 5 || gnr == 9)
    {
        robe=clone_object("/players/llort/secure/archrobe_shad");
        robe->start(this_player(),-1);
    }
    return 1;
} 

int remove_fun(object pl)
{
    if(robe) destruct(robe); 
    return 1;
}
