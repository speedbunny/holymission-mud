
inherit "obj/weapon";

reset(arg)
{
  if(!arg)
  {
   name_of_weapon = "Any slayer";
    alt_name = "sword";
    alias_name = "slayer";
    short_desc = "Bastard sword";
    long_desc = "Sword has threaded bands of gold and silver inlaid with\n"+
                "precious gems on the hilt. The blade is of the finest\n"+
                "metal created by Kbl. There are inscriptions on the blade.\n";
    read_msg = "Kbl created this sword as a gift to the Light Elemental.\n"+
               "LE provides hope that the future remains bright for our\n"+
               "imaginations to fly! NOT be supressed by the Darkness that\n"+
               "threathens to surround us all. Humans are the basis from\n"+
               "which darkness moves away but only through the mind can we\n"+
               "put darkness in its PLACE!\n";
    set_class(15);
   set_value(5000);
     set_weight(3);
    set_hit_func(this_object());
  }
}

weapon_hit(attacker)
{
    write("You do MEGA damage to "+attacker->query_name()+".\n");
    return 5;
}

