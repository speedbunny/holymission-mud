
/* iron club */

inherit "/obj/weapon";

void reset(int flag)
{

    ::reset(flag);
    if (flag == 0)
    {
       set_name("club");
       set_alias("iron club");
       set_short("spiked, iron club");
       set_long("You see a heavy, spiked iron club.\n");
       set_weight(4);
       set_class(20);
       set_type(1);
       set_value(300);
    }
}

int wield(string me)
{
    if (!me || !id(me))
        return 0;
    if (this_player()->query_str() > 14)
    {
       write("With all your powers, you manage to wield that heavy weapon.\n");
       return ::wield(me);
    }
    write("You don't manage to wield that heavy weapon.\n");
    return 1;
}

