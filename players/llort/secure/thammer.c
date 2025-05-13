inherit "/obj/weapon";

void reset(int flag)
{

    ::reset(flag);
    if (flag == 0)
    {
       set_name("hammer of thunderbolts");
       set_alias("hammer");
       set_short("hammer of thunderbolts");
       set_long("You see a gigantic, fine crafted stone hammer with lots of"+
                " runes on its surface.\n");
       set_weight(20);
       set_class(20);
       set_type(1);
       set_value(300000);
       set_hit_func(this_object());
    }
}

int wield(object me)
{
    if (this_player()->query_str() > 40 &&
        this_player()->query_size() > 2)
    {
       write("With all your powers, you manage to wield that heavy weapon.\n");
       return ::wield(me);
    }
    write("You don't manage to wield that heavy weapon.\n");
    return 1;
}

int weapon_hit(object vic)
{
    int ret;
    ret = 0;

    switch(random(100))
    {
        case 0..4:
            write("Your weapon humms powerfully as a lightning"+
                  "bolt shoots at your enemy.\n");
            say("A powerful lightningbolt strikes "+vic->query_name()+"!\n",
                vic);
            tell_object(vic,
                "A powerful lightningbolt ripps through your body!\n"+
                "You feel dizzy.\n");
            vic->hold(this_object(),1);
            ret = (random(100));
	    break;
        case 5..9:
            write("Your hammer fight out of your hand and delivers an "+
                  "additional blow.\n");
            say("The hammer of Thunderbolts strikes out and delivers an "+
                "additional blow!\n");
            call_out("_att_2",0,this_player());
            break;
        case 10..14:
            write("The hammer finds a weak spot in your victims armour and\n"+
                  "rips through him even harder!\n");
            ret = 10;
    }
    if(vic->query_race()=="giant") return ret+20;
}

void _att_2(object wielder)
{
    wielder->attack();
}
