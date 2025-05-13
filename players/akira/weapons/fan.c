inherit "/obj/weapon";
#include "/spells/spell.h"
object who;
int bullseye;

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_name("Fan of the Jade Emperor");
    set_short("Fan of the Jade Emperor");
    set_alias("fan");
    set_long("This is the legendary Fan of the Jade Emperor of the\n"+
      "Heavens. It is said that this fan was a gift given to\n"+
      "Lord Tokugawa, so that he might bring peace to the realm.\n"+
      "The fan is made from the finest jade, and it doesn't\n"+
      "look like it would make a very good weapon. Never the\n"+
      "less, it is a very beautiful weapon.\n");
    set_weight(2);
    set_value(20000);
    set_info( "nin");
    modify_resistance(POISON, 30);
    modify_immunity(POISON, 10);
    set_class(18);
    set_hit_func(this_object());
}

int weapon_hit(object victim){
    if(victim->query_race()=="dragon") {
        write("The Fan Glows A Brilliant Green As It Strikes!\n");
        say(this_player()->query_name()+"'s fan glows a brillian green!\n");
	return 100;
    }
    if(random(100)/2) {
	write("The fan opens and a mighty bolt of power shorts forth!\n");
	say(this_player()->query_name()+"'s shoots forth a might bolt of power!\n");
	return 50;
    }
}

void init(){
::init();
    add_action ( "fan", "fan");
}

int fan (string str){
    if(!str) return 0;
    who=present(str, environment(this_player()));
    if (who){
write("You open your fan and give "+this_player()->query_name()+" a cool\n"+
      "breeze. How nice of you!\n");
	tell_object(who, this_player()->query_name()+" fans you... How nice!\n");
	bullseye=1;
	return 1;
    }
    else{
	write("who do you wish to fan?\n");
	return 1;
    }
    return 1;
}
