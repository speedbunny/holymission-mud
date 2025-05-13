inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("moonblade");
    set_alias("sword");
    set_alt_name("blade");
    set_class(19);
    set_hit_func(this_object());
    set_weight(7);
    set_value(7500);
    set_light(10);
    set_short("A glowing Moonblade");
    set_long("This ancient sword is made of condensed moon essence.\n"+
      "It is a powerful faerie sword.  Long ago it was entrusted\n"+
      "to a pegataur guardian, and has remained there for generations.\n");
}

weapon_hit(attacker) {
    object ob;
    string name;
    
    ob=present(attacker,environment(this_player()));
    if (!living(ob)) return;
    name=ob->query_name();
    switch(random(7)) {
    case 0:
	write("The sword fires a beam of moonlight at "+name+"!\n");
	tell_object(ob,"You are hit with a beam of moonlight!\n");
	say(this_player()->query_name()+" fires a beam of moonlight at "+name+"!\n");
	return 20;
	break;
    case 1:
	write("The moonblade flashes with incredible brilliance!\n");
	tell_object(ob,"The moonblade flashes brilliantly.\n");
	say("The moonblade flashes brilliantly.\n");
	this_player()->heal_self(10);
	return 10;
	break;
    case 2:
	write("The sword spins at "+name+"!\n");
	tell_object(ob,this_player()->query_name()+" spins his sword at you!\n");
	say("The moonblade spins at "+name+".\n");
	return 10;
	break;
    default:
	return 0;
	break;
    }
}
