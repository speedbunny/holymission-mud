inherit "obj/weapon";
#include "/players/nylakoorub/guild/defines.h"




reset(arg)
{
    ::reset(arg);
    set_name("staff-sling");
    set_alt_name("sling");
    set_alias("4thstaff");
    /* put "4thstaff" in set_alias(), prevent mistake from other
     staffs on the mud, like mage staff - Nylakoorub 06-30-96  */
    set_hit_func(this_object());
    set_short("The Staff-Sling of the 4th Dimension");
    set_long("This is the legendary Staff-Sling of the 4th Dimension. It\n"+
      "is said to be as old as time itself. The shaft of the staff\n"+
      "is covered with magic runes. This weapon is only ment for a\n"+
      "true master of time and space.\n");
    set_weight(7);
    set_class(18);
    set_value(5000);
    set_two_handed();
}


drop(){
    destruct(this_object());
    write("Your staff returns to its own dimension until needed again.\n");
    return 1;
}


init(){
    add_action("bop","bop");
}



int bop (string str){
    if(!str) return 0;
    who= present (str, environment(this_player()));
    if (who){
	write("Your staff jumps from your hands and bops "+
	  capitalize(str)+
	  " on the head.\n");
	tell_object(who,
	  capitalize(this_player()->query_real_name())+
	  "'s staff jumps from their hands "+
	  "and bops you on the head.\n");
	bullseye=1;
	return 1;
    }
    else
	write("Who do you want to bop?\n");
    return 1;
}


weapon_hit(attacker) {
    object ob;
    string name;

    ob = present(attack, environment(this_player()));
    if (!living(ob)) return;
    name = ob->query_real_name();
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


