
#define TP this_player()
#define TPN this_player()->query_name()
#define env environment
inherit "obj/monster";
object target, owner;
string name, own_name;
int level, hp, wc, ac, guarding;

reset(arg){
    ::reset(arg);
    if(arg) return;
    own_name=TPN;
    set_name("knight");
    set_alias("bodyguard");
    set_race("human");
    set_long("This is a test knight.\n");
    set_level(1);
    set_hp(5000);
    set_ep(1);
    set_wc(70);
    set_ac(50);
    msgin="arrives";
    msgout="leaves";
    enable_commands();
}
patch_owner(o) {
    own_name=o;
}
init(){
    ::init();
    add_action("name", "name");
    add_action("messagein", "setin");
    add_action("messageout", "setout");
    add_action("step", "step");
    add_action("die", "die");
    add_action("destroy", "destroy");
    add_action("relax", "relax");
}
catch_tell(str){
    string a,b;
    object target;
    if(guarding) return 1;
    sscanf(str, "%s %s.",a,b);
    if(b=="arrives"){
	target=find_living(lower_case(a));
	if(target && owner){
	    tell_object(owner, "\n"+name+" tells you: "+
	      target->query_name()+" just arrived.\n");
	    return 1;
	}
    }
    return 1;
}
get_owner(obj){
    if(obj->query_real_name() !=own_name){
	write("You're not "+owner->query_name()+".\n");
	write("Where is my liege?\n");
	if(!find_player(own_name)) call_out("die", 5);
	if(find_player(own_name)) tell_own(obj);
	return 0;
    }
}
check_ok(){
    if(!owner){
	get_owner(TP);
	return 1;
    }
    if(TP!=owner){
	tell_object(owner, TP->query_name()+" is trying to command me.\n");
	return 1;
    }
}
step(str){
    object target;
    if(!str || str!="back"){
	notify_fail("What?\n");
	return 1;
    }
    if(!check_ok()) return 0;
    write("Your knight steps back to your side.\n");
    say(TPN+" commands "+TP->query_possessive()+" knight to step back.\n");
    target=this_object()->query_attack();
    if(target){
	this_object()->stop_fight();
	target->stop_fight();
    }
    if(guarding) guarding=0;
    set_heart_beat(1);
    return 1;
}
messagein(str){
    if(!check_ok()) return 0;
    if(!str){
	write("Setin <msg> to set the msg seen when your knight arrives.\n");
	return 1;
    }
    msgin=str;
    write("OK - message is changed.\n");
    return 1;
}
messageout(str){
    if(!check_ok()) return 0;
    if(!str){
	write("Setout <msg> to set the msg seen when your knight leaves.\n");
	return 1;
    }
    msgout=str;
    write("OK - message is changed.\n");
    return 1;
}
name(str){
    if(!check_ok()) return 0;
    if(!str) return 0;
    set_alt_name(str);
    set_short(str+" "+TP->query_name()+"'s knight.");
    write("OK - name changed.\n");
    return 1;
}
die(){
    int check;
    check=0;
    if(alt_name){
	say(alt_name+" exclaims: I have been released from my duty.\n");
	say(alt_name+" holds aloft his sword and disappears.\n");
    }
    destruct(this_object());
}
heart_beat(){
    ::heart_beat();
    if(guarding) return;
    if(!find_player(own_name)){
	call_out("die", 3);
	return 1;
    }
    if(!owner(this_object())) owner=find_player(own_name);
    if(environment(this_object()) != env(owner)) {
	tell_room(env(this_object()), alt_name+" "+msgout+".\n");
	tell_room(env(owner), alt_name+" "+msgin+".\n");
	move_object(this_object(), env(owner));
    }
}
destroy(str){
    object target;
    if(!check_ok()) return 0;
    if(!str) return 0;
    target=present(str, env(this_object()));
    if(!target || !living(target) || !target->query_npc()){
	write("Your knight is bewildered.\n");
	return 1;
    }
    write("Your knight proceeds to methodically destroy "+target->query_name()+"\n");
    say(alt_name+", "+owner->query_name()+"'s knight starts to methodically\n"+
      "destroy "+target->query_name()+".\n");
    this_object()->attack_object(target);
    return 1;
}
relax(){
    if(!check_ok()) return 0;
    write("You command your knight to relax.\n");
    say(owner->query_name()+"'s knight stands at ease.\n");
    guarding=1;
    return 1;
}
tell_own(obj){
    owner=find_player(own_name);
    tell_object(owner, "\n"+name+" tells you: "+obj->query_name()+" "+
      "is bugging me.\n");
    return;
}
say_it(str){
    say(str, this_player());
}
query_real_name() {return alt_name;}
query_name() {return this_object()->short();}
