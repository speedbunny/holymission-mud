/* Edited by Colossus 022294 */
#pragma strict_types

inherit "obj/armour";

void reset(int arg){
    ::reset(arg);
    if(!arg) {
	set_name("cloak");
	set_ac(100);
	set_weight(1);
	set_value(10000);
	set_short("Vampire cloak");
	set_long("A long dark cloak that seems to be on every vampire you've\n"+
	  "met or read about. It seems that they have a reputation\n"+
	  "to protect.\n");
    }
}

int drop(string str){
    if(!id(str))
	return 0;
    else
	write("You cannot drop the cloak.\n");
    return 1;
}

status get(){
    return (int)this_player()->query_wizard();
}
status query_mage_wear(){ return 1; }
