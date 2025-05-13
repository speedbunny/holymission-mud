inherit "obj/weapon";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("murderweapon");
    set_alias("sword");
    set_short("Bloodstained sword");
    set_long(
      "A small sword stained with dried blood. Apparently the one\n"+
      "who last killed with this weapon didn't bother to wipe it off.\n");
    set_weight(0);
    set_value(100);
    set_class(4);
}

int drop(){
    if(query_verb()=="sell"){
	write("You do not want to sell a piece of evidence.\n");
	return 1;
    }
} 
