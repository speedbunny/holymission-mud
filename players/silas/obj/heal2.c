/* Coded by Malakai.... :) */
inherit "obj/treasure";
id(str){
	return str== "potion";
}
init(){
	add_action("drink","drink");
	add_action("drop_potion","drop");
}
query_weight(){
	return 1;
}
query_value(){
	return 2000;
}
get(){return 1;}
short(){ return "A potion of medium healing";}
long(){
	write("This is a flask containing a potion of medium healing. It may be possible\n");
	write("to drink it.\n");
	return 1;
}
drink(str){
	if(!str)return;
        if(str=="potion"){
	write("You drink the potion, and you feel refreshed.\n");
	say(this_player()->query_name()+" drinks the potion of medium healing.\n");
	this_player()->heal_self(random(100));
	destruct(this_object());
	return 1;
	}
	return 1;
}
drop_potion(str){
	if(!str)return;
        if(str=="potion"){
	write("You drop the potion, and it breaks on the ground!\n");
	say(this_player()->query_name()+" drops the potion on the ground, and it breaks.\n");
	destruct(this_object());
	return 1;
	}
}
