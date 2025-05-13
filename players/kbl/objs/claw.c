/* Claw of the Vulture */

inherit "obj/weapon";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    name_of_weapon = "Giant Vulture Claw";
    alt_name = "claw";
    alias_name = "vulture claw";
    short_desc = "Tri-claw of a giant vulture"; 
    long_desc = "Tri-claw of a giant vulture. Looks deadly sharp. There's\n"+
                "something inscribed on the middle claw.\n";
    read_msg = "The Dark one is returning! Behold your deaths, elfs!\n"+
               "This claw will help keep away any foolish adventures\n"+
               "who wander into the giant pine. To command is to have\n"+
               "power over others! Muahahahahahahahahah!!!!\n";
    class_of_weapon = 19;
    type_of_weapon = 0;
    value = 5000;
    local_weight = 9;
    hit_func = this_object();
  }
}

weapon_hit(attacker)
{
  if(attacker->id("elf"))
  {
    write("You do MEGA damage to "+attacker->query_name()+".\n");
    say(this_player()->query_name()+" does MEGA damage to "+attacker->query_name()+".\n");
    return 40;
  }
  return 0;
}
