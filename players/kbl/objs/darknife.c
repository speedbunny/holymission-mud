/* Dark Knife, slayer of DOC (Demons Of Chaos) */

inherit "obj/weapon";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    name_of_weapon = "Darknife";
    alt_name = "knife";
    alias_name = "darknife";
    short_desc = "Chaos darknife";
    long_desc = "Long thin dark crystal knife glows with a special internal\n"+
                "power. It feels really chaotic-evil. You see some symbols\n"+
                "written on the side of the blade.\n";
    read_msg = "To those with enough power to possess me I will help you\n"+
               "destroy the DOC. Wield my power against the dark crystaline\n"+
               "beings who threaten to take over the MUD!\n";
    class_of_weapon = 17;
    type_of_weapon = 0;
    value = 1000;
    local_weight = 9;
    hit_func = this_object();
  }
}

weapon_hit(attacker)
{
  if(attacker->id("doc"))
  {
    write("You do MEGA damage to "+attacker->query_name()+".\n");
    say(this_player()->query_name()+" does MEGA damage to "+attacker->query_name()+".\n");
    return 60;
  }
  return 0;
}
