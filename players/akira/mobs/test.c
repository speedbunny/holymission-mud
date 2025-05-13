inherit "obj/monster";
reset(arg){
    ::reset(arg);
    if (! arg) {
   /* Yes this mob is a bitch, but I plan on having him guard so very */
   /* powerful stuff. Have fun. -Akira                                */
        set_name ("Temple Guardian");
        set_alt_name("guardian");
set_long("This is a temple guardian. He is made from some strange type\n"+
         "of stone. however even though he is made from stone, he seems\n"+
         "to move with the grace and speed of water. legend hold that if\n"+
         "a guardian does not want you to enter a given place, you\n"+
         "will never enter that place.\n");
	set_al(100);
	set_ac(40);
        set_level(60);
        set_wc(20);
	set_number_of_arms(4); /* I want extra attacks */
    }
}
init(){
    ::init();
    add_action("block", "feet");
    add_action("block", "slide");
    add_action("block", "cast");
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
        if(arg== "guardian");
        write("He blocks your kick with very little effoet!\n");
	this_player()->hit_player(50);
	return 1;
    }
    if(query_verb()== "slide"){
        write("The Guardian will not let you do that!\n");
        return 1;
    }
    if(query_verb()== "smash"){
        if(arg== "guardian");
        write("As you attempt to smash, He uses a leg check to block it!\n");
	this_player()->hit_player(40);
	return 1;
    }
    if(query_verb()== "cast"){
  this_player()->restore_spell_points(-(this_player()->query_spell_points()/2));
write("The guardian counters your spell, and drains your power!\n");
    return 1;
 }
    if(query_verb()== "choke"){
        if(arg== "guardian");
        write("He slaps your hands down and counter strikes!\n");
	this_player()->hit_player(100);
	return 1;
    }
    if(query_verb()== "but"){
        if(arg== "guardian");
        write("You try to headbutt him, OUCH he is made of stone!\n");
	this_player()->hit_player(150);
	return 1;
    }
    if(query_verb()== "punch"){
        if(arg== "guardian");
        write("Your punch is caught, and Guardian counter strikes!\n");
	this_player()->hit_player(20);
	return 1;
    }
    if(query_verb()=="kick"){
        if(arg== "guardian");
	write("Your kick is caught and thrown to the side!\n");
	return 1;
    }
    if(query_verb()=="bash"){
        if(arg== "guardian");
        write("The Guardian side steps your bash!\n");
	return 1;
    }
    if(query_verb()== "assassinate" && query_verb()=="backstab"){
        if(arg== "guardian"){
        write("The guardian seems to trip you just before you strike!\n");
	    this_object()->attack_obj(this_player());
	    if(this_player()->query_invis());
	    this_player()->set_vis();
	    return 1;
	}
    }
    if(query_verb()=="death"){
        if(arg== "guardian");
        write("He parries your death strike and hits you with one!\n");
	this_player()->hit_player(400);
	return 1;
    }
    if(query_verb()=="bodyslam"){
        write("The guardian rolls with it and springs back to his feet!\n");
	return 1;
    }
}
