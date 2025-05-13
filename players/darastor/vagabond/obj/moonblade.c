inherit "obj/weapon";
#include "/players/exos/defs.h"
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("moonblade");
    set_alias("sword");
    set_alt_name("blade");
    set_class(19);
    set_hit_func(TO);
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
    
    ob=present(attacker,ENV(TP));
    if (!living(ob)) return;
    name=ob->QNAME;
    switch(random(7)) {
    case 0:
	write("The sword fires a beam of moonlight at "+name+"!\n");
	TELL(ob,"You are hit with a beam of moonlight!\n");
	say(TPN+" fires a beam of moonlight at "+name+"!\n");
	return 20;
	break;
    case 1:
	write("The moonblade flashes with incredible brilliance!\n");
	TELL(ob,"The moonblade flashes brilliantly.\n");
	say("The moonblade flashes brilliantly.\n");
        TP->heal_self(10);
	return 10;
	break;
    case 2:
	write("The sword spins at "+name+"!\n");
	TELL(ob,TPN+" spins his sword at you!\n");
	say("The moonblade spins at "+name+".\n");
	return 10;
	break;
    default:
	return 0;
	break;
    }
}
