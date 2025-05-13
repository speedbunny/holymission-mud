inherit "obj/monster";
reset(arg){
    ::reset(arg);
    if (! arg) {
	set_name ("Sifu Brandon");
	set_alt_name("brandon");
	set_long("This is Sifu Brandon, Master of Preying Mantis Kung-Fu. His "+
	  "fighting skills are legendary. He has never know defeat in "+
	  "combat. It is said he can block or counter just about any "+
	"attack. He is here visiting the Hwarang-Do school, and his "+
	"friend, Horiuchi Owari. It would not be wise to attack him! \n");
	" \n";
	set_al(100);
	set_ac(40);
	set_hp(2000);
	set_level(50);
	set_wc(50);
	set_number_of_arms(4); /* I want extra attacks */
    }
}
init(){
    ::init();
    add_action("block", "feet");
    add_action("block", "death");
    add_action("block", "assassinate");
    add_action("block", "backstab");
    add_action("block", "smash");
    add_action("block", "choke");
    add_action("block", "but");
    add_action("block", "punch");
    add_action("block", "kick");
    add_action("block", "bodyslam");
    add_action("block", "knee");
    add_action("block", "bash");
    add_action("block", "backstab");
}
block (arg) {
    if(query_verb()== "feet") {
	if(arg== "Brandon");
	write("He uses a mantis Block to parry your kick!\n");
	this_player()->hit_player(50);
	return 1;
    }
    if(query_verb()== "smash"){
	if(arg== "Brandon");
	write("As you attempt a smash, Brandon uses a leg check to block it.\n");
	this_player()->hit_player(40);
	return 1;
    }
    if(query_verb()== "choke"){
	if(arg=="brandon");
	write("Brandon slaps your hands down, and hits you with and Iron Palm!\n");
	this_player()->hit_player(100);
	return 1;
    }
    if(query_verb()== "but"){
	if(arg=="brandon");
	write("You try to headbutt Brandon, OUCH! He has Iron Head!\n");
	this_player()->hit_player(150);
	return 1;
    }
    if(query_verb()== "punch"){
	if(arg=="brandon");
	write("Your punch is caught in a Mantis Grab. Brandon Laughs at you!\n");
	this_player()->hit_player(20);
	return 1;
    }
    if(query_verb()=="kick"){
	if(arg=="brandon");
	write("Your kick is caught and thrown to the side!\n");
	return 1;
    }
    if(query_verb()=="bash"){
	if(arg=="brandon");
	write("Brandon dodges your bash! You'll have to try harder than that!\n");
	say(this_player()->query_name()+" trys to bash Brandon, but he dodges!\n");
	return 1;
    }
    if(query_verb()== "assassinate" && query_verb()=="backstab"){
	if(arg=="brandon"){
	    write("Brandon waits for the last second then turns and trips you!\n");
	    this_object()->attack_obj(this_player());
	    if(this_player()->query_invis());
	    this_player()->set_vis();
	    return 1;
	}
    }
    if(query_verb()=="death"){
	if(arg=="brandon");
	write("Brandon parries your death strike and hits you with one!\n");
	this_player()->hit_player(400);
	return 1;
    }
    if(query_verb()=="bodyslam"){
	write("Brandon rolls with the fall, and springs back to his feet.\n");
	return 1;
    }
}
