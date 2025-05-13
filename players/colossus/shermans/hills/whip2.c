#pragma strict_types

inherit "obj/weapon";

void reset(int arg){
    ::reset();
    set_name("demonwhip");
    set_alt_name("whip");
    set_alias("whip of demons");
    set_class(20);
    set_weight(1);
    set_value(3000);
    set_short("Demonwhip");
    set_long("A mighty whip prefered by demons.\n");
    set_hit_func(this_object());
}

int weapon_hit(object ob){
    if (random(100) > 70) {
	write("The whip cuts your opponent.\n");
	say("Demonwhip cuts "+ob->query_name()+".\n");
    }
    ob->add_poison(1);
    return 0;
}
