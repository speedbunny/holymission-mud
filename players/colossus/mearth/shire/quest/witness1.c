inherit "obj/monster";
#define LIE 10
#define TPC this_player()->query_wis()
string murderer, murder_weap, murder_room;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_short("Hobbit traveller");
    set_name("hobbit traveller");
    set_alias("HOBBIT_WITNESS1");
    set_alt_name("traveller");
    set_race("hobbit");
    set_level(7);
    set_gender(1);
    set_al(0);
    set_long(
      "A meek but cunning looking hobbit that travels around the Shire by\n"+
      "foot. As you look at him, he eyes you with a calculating look and\n"+
      "then looks away.\n");
    add_money(25);
}

void set_murderer(string str){ murderer = str; }
set_murder_weap(string str){ murder_weap = str; }
void set_murder_room(string str){ murder_room = str;}

void state_job(object TP){
    tell_room(environment(this_player()),
      TP->query_name()+" asks: What is your job?\n");
    tell_room(environment(),
      "The hobbit says: I am a traveller.\n");
}

void state_name(object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: What is your name?\n");
    tell_room(environment(),
      "The hobbit says: My name is Thom.\n");
}

void state_murderer(string str, object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: What do you know about "+
      capitalize(str)+"?\n");
if(murderer==str && TPC>random(LIE)){
	tell_room(environment(),
	  "The hobbit says: "+capitalize(str)+" is an evil person.\n"+
	  "The hobbit says: It is very likely that he is the murderer!\n");
    }
    else {
	tell_room(environment(),
	  "The hobbit says: I know him well, "+capitalize(str)+
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
	  "The hobbit says: Yes I believe so.\n");
    }
    else {
	tell_room(environment(),
	  "The hobbit says: Not too likely.\n");
    }
    environment()->set_done(2);
}

void state_murder_room(string str, object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: Do you think the murder was "+
      " committed at the "+str+"?\n");
if(murder_room==str && TPC>random(LIE)){
	tell_room(environment(),
	  "The hobbit says: Most definitely! I was there!\n");
    }
    else {
	tell_room(environment(),
	  "The hobbit says: I don't think so.\n"+
	  "THe hobbit says: The scream was from another different direction.\n");
    }
    environment()->set_done(3);
}
