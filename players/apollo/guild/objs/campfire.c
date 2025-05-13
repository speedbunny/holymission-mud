//Coded by Pretzel
//Touched up by Apollo

#define TP this_player()
#define ENV environment
#define GUILD TP->query_guild()

id(string str){ return str == "campfire"; }

query_value(){ return 0; }

query_weight(){ return 1000000;}

short(){ return "A campfire";}
long(){
    write("This is the campfire of the horde.  It has a soft golden glow to it\n"+
      "that makes you feel uneasy.  Members of the horde come here in preparation\n"+
      "for the hunt.  Just before the horde goes out to hunt they envision their\n"+
      "prey of choice.\n");
    return 1;
}
init(){
    add_action("do_find","envision");
}

do_find(string str){
    object who;
    object where;
    if(GUILD != 11){
	write("You are not part of the horde!\n");
	return 1;
    }
    if(TP->query_immortal()==1){
	write("Your a wizard. Why do you need this to find someone?\n");
	return 1;
    }
    if(!str){
	write("Envision who?\n");
	return 1;
    }
    who=find_player(str);
    if(!who){
	write("That person is not here.\n");
	return 1;
    }
    if(who->query_immortal()==1){
	write("You can't envision the gods you idiot!\n");
	write("You feel the wrath of the gods bear down upon you!\n");
	write("You feel hurt in some way!\n");
	TP->reduce_hit_point(10);
	return 1;
    }
	if(TP->query_sp() < 20){
        write("You don't have enough energy to envision anyone.\n");
	return 1;
}
    where=ENV(who);
	tell_object(TP,where->long()+"\n");
        tell_object(who,"You feel like you're being watched.\n");
	TP->restore_spell_points(-20);
    return 1;
}
