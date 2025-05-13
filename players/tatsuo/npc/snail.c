
/* snail */

inherit "/obj/monster";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_name("giantic snail");
        set_alt_name("snail");
        set_size(4);
        set_short(query_name());
        set_long(
        "This is an extremly giantic mutant of the famous seasnail.\n"+
        "There is slime all over its body and a big shell coves its\n"+
        "back. Its height is nearly 8 foot and its length nearly 20\n"+
        "foot. The skin the snail coves is brown and bark like.\n");
        set_level(69);
        set_race("snail");
      }
}

int attack()
{
    if (::attack() && !random(9) && attacker_ob)
    {
       tell_object(attacker_ob,"The Snail spits slime at you !\n");
       say("The Snail spits slime at "+attacker_ob->query_name()+" !\n",
           attacker_ob);
       attacker_ob->hold(attacker_ob,1 + random(3));
       if (attacker_ob && living(attacker_ob))
          attacker_ob->hit_player(50 + random(110),5,({4,10}));
       return 1;
    }
   return 0;
}

int query_dex()
{
    return 20;
}

int query_str()
{
    return 120;
}
 

