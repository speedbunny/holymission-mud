/* Ice Troll */

inherit "obj/monster";

object m_oney;

reset(arg)
{
    ::reset(arg);

    if(arg)
        return;

        set_name("ice troll");
        set_alias("troll");
        set_level(9);
        set_hp(100);
        set_wc(12);
        set_ac(3);
        set_al(-200);
        set_short("Ice Troll");
        set_long("It is a small cold-blooded ice troll.\n");
        set_aggressive(1);
        set_whimpy();
        set_spell_mess1("Ice Troll says: Freeze!");
        set_spell_mess2("The troll says: Kill all warm-blooded creatures!");
        set_chance(20);
        m_oney = clone_object("obj/money");
        call_other(m_oney, "set_money", random(300));
        move_object(m_oney, this_object());
}

