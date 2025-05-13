inherit "obj/weapon";
#define TP wielded_by

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    set_name("sting");
    set_alias("sword");
    set_short("Sting the elvish sword");
    set_long("This is Sting, sword of the elves. It looks very powerful.\n");
    set_class(11);
    set_hit_func(this_object());
    set_weight(2);
    set_value(2500);
}
weapon_hit(attacker){
    int dam;
    string atta;
    atta=attacker->query_name();
    dam=(wielded_by->query_level()/3-10);
    dam=(wielded_by->query_level()/3);
    switch(random(3)){
    case 0:notify("Sting glows with a blue light as "+TP->query_name()+" slashes at "+atta+".");
	break;
    case 1:notify(TP->query_name()+" cuts through "+atta+" with Sting like a hot knife through butter.");
	break;
    case 2:notify("Sting glows a brilliant blue as "+TP->query_name()+" sinks Sting deep into "+atta+".");
	break;
    }
    notify("\n");
    return dam;
}
notify(str){
    write(str);
    say(str);
}
