/* Claw of the HUGE bear */

inherit "obj/weapon";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    name_of_weapon = "Bear claw";
    alt_name = "claw";
    alias_name = "bear claw";
    short_desc = "Claw of a HUGE bear"; 
    long_desc = "Claw of a HUGE bear. Its deadly sharp and nasty looking.\n";
    class_of_weapon = 19;
    type_of_weapon = 0;
    value = 5000;
    local_weight = 7;
    hit_func = this_object();
  }
}

weapon_hit(attacker)
{
  if(attacker->id("doc"))
  {
    write("You do MEGA damage to "+attacker->query_name()+".\n");
    say(this_player()->query_name()+" does MEGA damage to "+attacker->query_name()+".\n");
    return 40;
  }
  return 0;
}
