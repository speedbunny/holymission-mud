inherit "obj/monster";
#define LIE 8
#define TPC this_player()->query_wis()
string murderer, murder_weap, murder_room;


void init(){
    ::init();
    add_action("show", "show");
}

int show(){
    if(this_player()->query_level()>=40){
	write(murderer+murder_weap+murder_room);
	return 1;
    }
}

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("old gaffer");
    set_alias("HOBBIT_WITNESS0");
    set_alt_name("gaffer");
    set_race("hobbit");
    set_level(7);
    set_gender(1);
    set_al(0);
    set_long(
      "This hobbit is so old his face looks like a wrinkled piece of parchment.\n"+
      "He also appears to be quite deaf and his eyesight is quite bad.\n"+
      "He is the hobbit that tells stories to other little hobbits.\n");
    add_money(25);
}

void set_murderer(string str){ murderer = str; }
void set_murder_weap(string str){ murder_weap = str; }
void set_murder_room(string str){ murder_room = str; }

void state_job(object TP){
    tell_room(environment(this_player()),
      TP->query_name()+" asks: What is your job?\n");
    tell_room(environment(),
      "The gaffer says: Eh? Job? I'm a retired farmer.\n"+
      "The gaffer says: Now I tell stories to the young ones.\n");
}

void state_name(object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: What is your name?\n");
    tell_room(environment(),
      "The gaffer says: What? Speak up!! Name you say? My name is Biffy.\n");
}

void state_murderer(string str, object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: What do you know about "+
      capitalize(str)+"?\n");
    if(murderer==str && TPC>random(LIE)){
	tell_room(environment(),
	  "The gaffer says: "+capitalize(str)+" is a bad little chap.\n"+
	  "The gaffer says: He may very well have done it!\n");
    }
    else {
	tell_room(environment(),
	  "The gaffer says: Speak louder! Ahh, I know him well, "+capitalize(str)+
	  " is not a murderer!\n");
	environment()->set_done(1);
    }
}

void state_murder_weap(string str, object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: Could the "+str+
      " be the murdering weapon?\n");
    if(murder_weap==str && TPC>random(LIE)){
	tell_room(environment(),
	  "The gaffer says: Could be I think. I didn't get a good look though.\n");
    }
    else {
	tell_room(environment(),
	  "The gaffer says: I do not remember it being the weapon used.\n");
    }
    environment()->set_done(2);
}
void state_murder_room(string str, object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: Do you think the murder was "+
      " committed at the "+str+"?\n");
    if(murder_room && TPC>random(LIE)){
	tell_room(environment(),
	  "The gaffer says: Hmm, I think it was, I couldn't get a good look though.\n");
    }
    else {
	tell_room(environment(),
	  "The gaffer says: Not likely.\n"+
	  "The gaffer says: If it did it escaped my aging eyes.\n");
    }
    environment()->set_done(3);
}
