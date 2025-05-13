#pragma strict_types
#pragma save_types
inherit "obj/weapon";

#include "/players/mangla/defs.h"

#define GM "guild/master"
#define COLS ({ "black","red","orange","blue","violet","green","white" })

int is_sword, superhit;

/*
int count;
*/

void switching(int arg);
string query_color();
void handle_reset();
void notify(string str);

int class(string s)
{
    if(environment() == TP)
    {
	if(s != 0)
	{
	    int temp;
	    sscanf(s,"%d",temp);
	    if(!temp || temp < 1)
		write("Illegal class setting.\n");
	    else
	    {
		superhit = temp;
		say(TP->query_name() +" adjusts "+ TP->POS +" lightsaber.\n");
		write("Superhit now set to "+ superhit +".\n");
	    }
	}
	else
	{
	    write("Current superhit is: "+ superhit +".\n");
	    say(TP->query_name() +" checks "+ TP->POS +" lightsaber.\n");
	}
    }
    return 1;
}

void reset(int arg)
{
    if(!arg) {
	superhit = 1;
	set_alias("handle");
	set_name("lightsaber");
	set_long("The chosen weapon of the Jedi.\n");
	set_type(2);
	set_class(5);
	set_weight(1);
	set_read("This is the weapon of a Jedi!\nThe Force is with you!\n");
	handle_reset();
    }
}

int id(string str) 
{
    switch(str)
    {
    case "lightsaber":
    case "handle":
	if (is_sword)
	{
	    long_desc = "This is a saber with a blade of light.\n" +
	    "The blade glows in a " + query_color() + " light.\n" +
	    "There is something written on the handle.\n";
	} else {
	    long_desc = "This seems to be the handle of a saber.\n" +
	    "It has a button on it.\n" +
	    "There is something written on it.\n";
	}
	return 1;
    case "blade":
	if (is_sword)
	{
	    long_desc = "It glows in a " + query_color() + 
	    " light. It seems to be very dangerous.\n";
	    return 1;
	} else 
	    return 0;
    case "button":
	long_desc = "A simple button.\n";
	return 1;
    default:
	return 0;
    }
}


string short() {
    string m;
    if(is_sword) m = "A " + query_color() + "-bladed lightsaber";
    else         m = "A simple handle";
    if(wielded)  m = m + " (wielded)";

    return m;
}

void init() 
{
    ::init();
    add_action("press","press");
    add_action("press","push");
    add_action("class","class");
}

int press(string str) {

    if(str != "button") return 0;

    if(ENV(TO)!=TP || !wielded || TP->query_level()<21) {
	write("Nothing happens. How strange!\n");
	return 1;
    }
    if(!is_sword) {
	if(TP->query_level() <= 20)
	{
	    write("This lightsaber is specially made for wizards.\n"+
	      "All other players cannot activate it.\n");
	    return 1;
	}
	is_sword=1;

	write("As you press the button, a " + query_color() + " blade of light flashes" +
	  " out of the handle.\n" +
	  "You have to concentrate hard to keep the saber under control.\n");
	say("A deadly " + query_color() + " blade of light erupts from nowhere...\n"
	  +"You hear a low roar of pure energy sizzling the air.\n");

	switching(1);
    }
    else {
	write("As you press the button the blade of light disappears.\n");
	say("The blade of light disappears.\n");
	switching(0);
    }
    return 1;
}

void switching(int arg) {

    if(arg) {
	set_hit_func(TO);
	set_light(1);
    }
    else {
	handle_reset();
	set_light(-1);
    }
    return;
}

void un_wield() {

    if(is_sword) {
	notify("The blade of light disappears.\n");
	handle_reset();
    }
    ::un_wield();
    return;
}

void handle_reset() {

    is_sword=0;
    set_hit_func();
    return;
}

int weapon_hit(object attacker) {

    int dam, dam2, dam3;
    string atta;

    atta = (string)attacker->NAME;
    dam  = superhit;
    /*
	dam2 = dam/2;
	dam3 = dam/3;
    */
    dam2 = 1;
    dam3 = 2;

    switch (random(9)) {
    case 0: notify(TP->NAME+" swings " + TP->POS +
	  " lightsaber in a wide arc.\n");
	break;
    case 1: notify(TP->NAME + " thrusts with " +
	  TP->POS + " lightsaber.\n");
	break;
    case 2: notify(TP->NAME + "'s lightsaber throws off sparks as it "+
	  "slices and dices.\n");
	break;
    case 3: notify(atta+" screams as " + TP->NAME + " cuts "+
	  "through " + attacker->query_pronoun() + ".\n");
	break;
    case 4: notify(TP->NAME + "'s lightsaber hums as it pierces " +
	  TP->POS + " opponent.\n");
	break;
    case 5: notify(TP->NAME + " calmly dismembers " + atta + ".\n");
	break;
    case 6: notify(atta + " clutches at the horrible wounds dealt by " +
	  TP->NAME + ".\n");
	break;
    case 7: notify(TP->NAME + "'s " + query_color() + " blade of light " +
	  "slices through " + atta + "'s body.\n");
	break;
    case 8: notify(TP->NAME + "'s lightsaber weaves under " + atta + "'s " +
	  "guard and pierces " + attacker->POS + " body.\n");
    }
    if (objectp(attacker) && living(attacker)) {
	if(TP->LEVEL > 24) {
	    write("You take a quick backhand slash at your opponent.\n");
	    say("Following with a backhand slash.\n");
	    return dam + dam2 + dam3;
	}
	else if (TP->LEVEL > 11) {
	    write("You sign your work with a small 'J' for Jedi.\n");
	    return dam + dam2;
	}
	else
	    return dam;
    }
    return 0;
}

void notify(string str) {

    write(str);
    say(str);
    return;
}

int get() {
    remove_call_out("fade_away");
    return 1;
}

int drop() {
    ::drop();
    call_out("fade_away",30);
    return 0;
}

string query_color() {

    int no;
    no=0;

    switch(TP->query_al_string()) {
    case "saintly": no++;
    case "good": no++;
    case "nice": no++;
    case "neutral": no++;
    case "nasty": no++;
    case "evil": no++;
    case "demonic": ;
    default: ;
    }
    return COLS[no];
}

void fade_away() {
    if ((!living(ENV(TO))) || ((int)ENV(TO)->query_guild() != 4)) {
	TELLR(ENV(TO),"The handle becomes indistinct and fades away.\n");
	destruct(this_object());
    }
    return;
}


int query_is_sword() {

    return is_sword;
}
