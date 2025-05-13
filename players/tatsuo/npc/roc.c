
/* roc */

inherit "/obj/npc";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        no_steal = 1;
        set_name("gigantic eagle");
        set_alt_name("eagle");
        set_short(query_name());
        set_long(
        "You see a gigantic brown eagle. This strange creatures are\n"+
        "the famous roc birds. Their body looks very strong and brown\n"+
        "feathered. They are nearly 20 feet high and have strong sharp\n"+
        "claws.\n");
        set_level(25);
        set_hp(1000);
        set_race("bird");
        set_attacks(2);
        set_attacks_change(70);
        move_object(clone_object("/players/tatsuo/Obj/egg"),
        this_object());
      }
}

int query_dex()
{
    return 60;
}

int query_str()
{
    return 20;
}
 

