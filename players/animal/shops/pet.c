/* 041994 Colossus: Edited out query_real_name as it was useless */

inherit "obj/monster";

object target, owner;
string name,namep;
int level, hp, wc, ac, guarding;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    namep = this_player()->query_real_name();
    set_name("a pet");
    set_alias("pet");
    set_race("animalpet");
    call_out("set_sh",3);
    set_long("This is a special pet, you can make it do\n"+
      "special things like: name <name>, sic <thing>,\n"+
      "chew corpse, torment <object>, release pet,\n"+
      "guard, heel, setin and setout.\n");
    set_level(1);
    set_hp(1);
    set_ep(10);
    set_wc(1);
    set_ac(1);
    msgin = "arrives";
    msgout = "leaves";
    enable_commands();
}

set_sh() {
    set_short("An unnamed pet <Belongs to "+namep+">");
}

patch_owner(o) { namep = o; }

init() {
    ::init();
    add_action("heel","heel");
    add_action("steal","steal");
    add_action("torment","torment");
    add_action("release","release");
    add_action("stay","stay");
    add_action("sic","sic");
    add_action("eat","chew");
    add_action("name","name");
    add_action("messagein","setin");
    add_action("messageout","setout");
}


catch_tell(str) {
    string s1,s2;
    object target;
    if (!guarding) return 1;
    sscanf(str,"%s %s.",s1,s2);
    if (s2 == "arrives") {
	target = find_living(lower_case(s1));
	if (target && owner) {
	    tell_object(owner, "\nYour pet tells you: "+
	      target->query_name()+" just arrived!\n> ");
	    return 1;
	}
    }
    return 1;
}

check_ok() {
    if (!owner) { get_owner(this_player()); }
    if (this_player() != owner) {
	tell_object(owner, "\n"+this_player()->query_name()+" is trying "+
	  "to command your pet.\n> ");
	return 0;
    }
    return 1;
}

die() {
    int check;
    check =0;
    if(alt_name) {
	say(alt_name+" screams: I have no one that loves me!!\n");
	say(alt_name+" is so shaken up, it dies.\n");
	check = 1;
    }
    if(name && !check) {
	say(name+" screams: I have no one that loves me!!\n");
	say(name+" is so shaken up, it dies.\n");
    }
    destruct(this_object());
}

eat(str) { 
    object target;
    if (!check_ok()) return 0;
    if (!str || str != "corpse") return 0;
    target = present("corpse",environment(this_object()));
    if (!target) {
	write("Your pet says: 'I see no corpse here!'\n");
	return 1;
    }
    write("Your pet jumps on the corpse, and rips it apart!\n");
    say(owner->query_name()+"'s pet jumps on a corpse, and rips it apart!\n");
    destruct(target);
    this_object()->heal_self(10);
    return 1;
}

get_owner(obj) {
    if(obj->query_real_name() != namep) {
	write("You are not my owner!!\n");
	write("Where is my owner???\n");  }
    if(!find_player(namep)) call_out("die",3);
    if(find_player(namep)) tell_own(obj);
    return 0;
}

heart_beat() {
    ::heart_beat();
    if (guarding) return;
    if(!find_player(namep)) { call_out("die",4); return; }
    if(!owner)  owner = find_player(namep);
    if (environment(this_object()) != environment(owner)) {
	tell_room(environment(this_object()), alt_name+
	  " "+msgout+".\n");
	tell_room(environment(owner), alt_name+
	  " "+msgin+".\n");
	move_object(this_object(),environment(owner));
    }
}

steal(s) {
    string what,whom;
    object victem;
    if(!check_ok()) return 0;
    if(sscanf(s,"%s from %s",what,whom)!=2){
	write("Steal what from whom?\n");
	return 1;
    }
    victem = present(whom,environment(this_player()));
    whom = capitalize(whom);
    if(!victem){
	write(whom+" is not present.\n");
	return 1;
    }
    if(victem==this_object()){
	write("Stealing from pet is pointless.\n");
	return 1;
    }
    return 0;
}

heel() {
    object target;
    if (!check_ok()) return 0;
    write("Your pet hurries over to your side.\n");
    say(owner->query_name()+"'s pet rushes to "+owner->query_possessive()+" side.\n");
    target = this_object()->query_attack();
    if (target) {
	this_object()->stop_fight();
	target->stop_fight();
    }
    if (guarding) guarding = 0;
    set_heart_beat(1);
    return 1;
}

messagein(str) { 
    if (!check_ok()) return 0;
    if (!str){ 
	write("setin <msg> to set the msg seen when your pet arrives.\n");
	return 1; }
    msgin = str;
    write("Ok - the message in is changed!\n");
    return 1;
}

messageout(str) { 
    if (!check_ok()) return 0;
    if (!str){ 
	write("setout <msg> to set the msg seen when your pet leaves.\n");
	return 1; }
    msgout = str;
    write("Ok - the message out is changed!\n");
    return 1;
}

name(str) { 
    if (!check_ok()) return 0;
    if (!str) return 0;
    set_alt_name(str);
    set_short(str+" <Belongs to "+owner->query_name()+">");
    write("Ok - name changed!\n");
    return 1;
}

release(str) { 
    if (!check_ok()) return 0;
    if (str != "pet") return 0;
    write("You release your pet.\n");
    say(owner->query_name()+" releases the pet.\n");
    call_out("die",2);
    return 1;
}

sic(str) { 
    object target;
    if (!check_ok()) return 0;
    if (!str) return 0;
    target = present(str, environment(this_object()));
    if (!target || !living(target) || !target->query_npc()) {
	write("Your pet say: 'Huh?'\n");
	return 1;
    }
    write("Your pet sics "+target->query_name()+".\n");
    say(owner->query_name()+"'s pet sics "+
      target->query_name()+".\n");
    this_object()->attack_object(target);      
    return 1; 
}

stay() {
    if (!check_ok()) return 0;
    write("You command your pet to stay.\n");
    say(owner->query_name()+"'s pet sits down, and relaxs.\n");
    guarding = 1;
    return 1;
}

tell_own(obj) {
    owner = find_player(namep);
    tell_object(owner,"\n"+name+" tells you: "+obj->query_name()+" is "+
      "bugging me!!\n> ");
    return;
}

torment(str) { 
    object target;
    if (!check_ok()) return 0;
    if (!str) return 0;
    target = present(str, environment(this_object()));
    if (!target) {
	write("Your pet is cofused.\n");
	return 1;
    }
    write("Your pet moves in on "+target->query_name()+
      ", growling and baring teeth.\n");
    say(owner->query_name()+"'s pet growls at "+
      target->query_name()+".\n");
    return 1;
}



say_it(str) {
    say(str,this_player());
}
// query_real_name() { return alt_name; }
query_name() { return this_object()->short(); }
