
/* sandworm */

inherit "/obj/monster";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        no_steal = 1;
        set_name("purple sandworm");
        set_alt_name("sandworm");
        set_short(query_name());
        set_long(
        "You see a big almost 50 feet long purple sandworm.\n"+
        "It looks extremly strong and its body is covered with\n"+
        "slime. Its teeth looks sharp and dangerous.\n");
        set_level(70);
        set_race("insect");
        move_object(clone_object("/players/whisky/obj/pois_potion"),
        this_object());
      }
}

int attack()
{
    if (::attack() && !random(6) && attacker_ob)
    {
       tell_object(attacker_ob,"The Sandworm bites you !\n");
       say("The Sandworm bites "+attacker_ob->query_name()+" !\n",
           attacker_ob);
       attacker_ob->add_poison(50);
       if (attacker_ob && living(attacker_ob))
           attacker_ob->hit_player(50+random(80));
       return 1;
    }
   return 0;
}

int query_dex()
{
    return 60;
}

int query_str()
{
    return 200;
}
 

