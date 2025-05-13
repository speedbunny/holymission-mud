inherit "/obj/weapon";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("weapon");
    set_short("A weapon");
    set_long("A test weapon");
    set_hit_func(this_object());
}

int weapon_hit(object attacker) {
    tell_object(this_player(), "You slice through "+attacker->query_name()+" horribly!\n");
    tell_object(attacker, this_player()->query_name()+" slices horribly through your body!\n");
    if(0)
	write("lala");
    return random(10);
}
