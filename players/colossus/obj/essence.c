
#define TP this_player()
#define ENV environment

string PREVIOUS, NOW, STACK;
object previous, now, stack;
int CHARGES;

inherit "obj/treasure";
reset(essence){
    CHARGES = 20+random(10);
    if(!essence){
	set_id("essence");
	set_short("Raiden's essence");
	set_long("The essence of Raiden the Thunder God. It looks as if you can\n"+
	  "use it to teleport. If you 'concentrate' you can set the location\n"+
	  "and if you 'concentrate' again, you will automatically be \n"+
	  "teleported to the spot you first concentrated on.\n");
	set_value(CHARGES*50);
	set_light(1);
    }
}
init(){
    ::init();
    add_action("tel", "concentrate");
}
tel() {
    if(ENV(TP)->query_property("no_teleport")) {
	write("You slam into an invisible barrier.\n");
	return 1;
    }
    if(!CHARGES) {
	write("Raiden's essence disappears as the stored power is used up.\n");
	destruct(this_object());
	return 1;
    }
    if(!PREVIOUS){
	PREVIOUS=NOW=file_name(ENV(TP));
	previous=ENV(TP);
	now=ENV(TP);
	write("Raiden's essence begins to crackle with energy as you charge it.\n");
    }
    else {
	PREVIOUS=file_name(ENV(TP));
	previous=ENV(TP);
	say(TP->query_name()+" charges up Raiden's essence.\n");
	TP->move_player("teleporting away#"+NOW);
	STACK=NOW; stack=now;
	NOW=PREVIOUS; now=previous;
	PREVIOUS=STACK; previous=stack;
	CHARGES --;
	return (1);
    }
    return (1);
}
