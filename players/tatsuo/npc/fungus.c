
/* tree */

inherit "/obj/monster";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        no_steal = 1;
        set_name("cave fungus");
        set_alt_name("fungus");
        set_short(query_name());
        set_long(
        "You see a giantic mushroom. Its head is pink red and\n"+
        "pulsating heavily. On its top is a small wet hole. The\n"+
        "fungus is covered by an energie aura and its walking on\n"+
        "its small hairy roots.\n");
        set_level(30);
        set_hp(1100);
        set_race("plant");
        move_object(clone_object("/players/whisky/obj/bless_potion"),
        this_object());
      }
}

int attack()
{
    if (::attack() && !random(9) && attacker_ob)
    {
       tell_object(attacker_ob,
                   "Cave fungus casts a 'lightning bolt' at you !\n");
       say("Cave fungus hits "+attacker_ob->query_name()+" with "+
           "a 'lightning bolt' !\n",
           attacker_ob);
       attacker_ob->hit_player(30+random(60),5,({2,10}));
       return 1;
    }
   return 0;
}

mixed hit_player(int dam,int kind,int elem)
{
    if (kind == 5)
       return ::hit_player(dam/2,kind,elem);
    return ::hit_player(dam,kind,elem);
}

     
int query_dex()
{
    return 10;
}

int query_str()
{
    return 40;
}
 

