inherit "obj/weapon";

reset (arg)
{
    if (arg) return;
    set_name("slayer");
    set_short("a demon slayer");
    set_alias("sword");
    set_long(
"This is a demon slayer. It might help you in a fight against demons.\n");
    set_class(18);
    set_weight(3);
    set_value(3000);
    set_hit_func(this_object());
}

weapon_hit(attacker)
{
     int a;
    if (attacker->query_race()!="demon") return ;
    a = random(3) + 1;
    if(a==3)
    {
	write("You cut some flesh out of the "+attacker->query_name()+
        "'s body.\n");
	say(this_player()->query_name()+" cuts some flesh out of the "+
	attacker->query_name()+"'s body.\n");
	return 30;
    }
    if(a==2)
    {
	write("You hit the "+attacker->query_name()+" with a great blow.\n");
	say(this_player()->query_name()+" hits the "+attacker->query_name()+
	" with a great blow.\n");
	return 20;
    }
    if (random(10)) return 10;
    else return 200;
}

