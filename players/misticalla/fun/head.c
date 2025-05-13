#define SN capitalize(this_player()->query_name())
#define TP this_player()
#define HERE environment(TP)
#define DN capitalize(dest->query_name())
#define HAM this_object()

object dest;

id(str) {return str=="head";}

get(str) {return 1;}

drop(str) {
    if(query_verb()=="drop"||query_verb()=="quit") 
    {write("As you drop the head it splats on the ground.\n");
	destruct(HAM);
	return 1;}
    else {return;}}

reset(arg) {}

short() {return "A bloody, rotten head";}
alias() {return "head";}

long() {
    write("It's a cute, fuzzy half-eaten head. It runs of blood when you\n" + 
      "crush it in your hand, and its little eyes seem ready to burst out of\n" + 
      "its head. Since you've got nothing better to do than play with heads.\n" + 
      "Might as well have a little fun with it then.\n");
    write("You might try: throw head to <player>\n"
      +"               <squeeze head>\n");
    return 1;}

init() {
    add_action("throw","throw");
    add_action("squeeze","squeeze");
}

broadcast(u, msg) {
    int i;
    for(i=0;i<sizeof(u);i++) {
	tell_object(u[i],msg);
    }
    return 1;}

room_filter(ob) {
    if(ob==TP) {return 0;}
    else if(ob==dest) {return 0;}
    else if(present(ob,HERE)) {return 1;}
    else {return 0;}}


throw_filter(ob) {
    if(ob==TP) {return 0;}
    else if(ob==dest) {return 0;}
    else if(ob->query_earmuff_level()>TP->query_level()) {return 0;}
    else {return 1;}}

throw(str) {
    string who, what;
    if(!str) {notify_fail("Throw what ?\n"); return;}
    else if(id(str)) {notify_fail("Throw head to whom ?\n"); return;}
    else if(sscanf(str,"%s to %s",what, who)!=2) {
	notify_fail("I don't understand\n"); return;}
    else if(!id(what)) {notify_fail("Throw what ?\n"); return;}
    else if(!dest=find_player(who)) {
	notify_fail("Throw it to whom ?\n"); return ;}
    else if(dest==TP) {
	write ("You throw the head up and down.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  SN+" tosses a bloody head around.\n");
	return 1;}
    else if(present(dest,HERE)) {
	write("You skillfully whip the bloody head across the room to "+DN+".\n");
	tell_object(dest,SN+" whips you a bloody head.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  SN+" whips a bloody head across the room to "+DN+".\n");
	transfer(HAM,dest);
	dest=0;
	return 1;}
    else {
	tell_object(TP, "Splat! You whip a bloody head across the sky to "+DN+"!\n");
	broadcast(filter_array(users(),"throw_filter",HAM),
	  "Splat! "+SN+" whips a bloody head across the sky to "+DN+"!\n");
	tell_object(dest,SN+" whips a bloody head to you.\n");
	transfer(HAM,dest);
	dest=0;
	return 1;}
}

squeeze(str) {
    if(!str) {notify_fail("Squeeze what ?\n"); return;}
    else if(!id(str)) {notify_fail("Throw what ? Squeeze what ?\n"); return;}
    else {
	tell_object(TP,
	  "The bloody head runs blood all over your hands. How amusing.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  "You hear an insane laugh as "+SN+" tortures the bloody head.\n");
	return 1;}
}


