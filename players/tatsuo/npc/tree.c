
/* tree */

inherit "/obj/npc";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        no_steal = 1;
        set_name("strange tree");
        set_size(5);
        set_alt_name("tree");
        set_short(query_name());
        set_long(
        "You see a big oak tree. It has a very strong stem and big\n"+
        "branches. It looks somehow strange as its walking on it's\n"+
        "roots.\n");
        set_level(40);
        set_hp(1500);
        set_race("plant");
        set_attacks(7);
        set_attacks_change(50);
        move_object(clone_object("/players/whisky/obj/bark_scroll"),
        this_object());
      }
}

int attack()
{
    if (::attack() && !random(30) && attacker_ob)
    {
       tell_object(attacker_ob,"The Tree entangles you with its branches !\n");
       say("The Tree entangles "+attacker_ob->query_name()+" !\n",
           attacker_ob);
       attacker_ob->hold(attacker_ob,2 + random(4));
       return 1;
    }
   return 0;
}

int query_dex()
{
    return 10;
}

int query_str()
{
    return 80;
}
 

