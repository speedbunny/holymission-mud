inherit "obj/monster";
#define LIE 10
#define TPC this_player()->query_wis()
string murderer, murder_weap, murder_room;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_short("Hobbit traveller");
    set_name("little hobbit girl");
    set_alias("HOBBIT_WITNESS2");
    set_alt_name("girl");
    set_race("hobbit");
    set_level(5);
    set_gender(2);
    set_al(0);
    set_long(
      "This is a cute little hobbit girl with pretty features. Her clothes are\n"+
      "slightly soiled from running around though. As you look at her carefully\n"+
      "she looks back up and smiles charmingly at you.\n");
    add_money(25);
}

void set_murderer(string str){ murderer = str; }
void set_murder_ewap(string str){ murder_weap = str; }
void set_murder_room(string str){ murder_room = str; }

void state_job(object TP){
    tell_room(environment(this_player()),
      TP->query_name()+" asks: What is your job?\n");
    tell_room(environment(),
      "THe little girl says: I am a child. I like to play!\n");
}

void state_name(object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: What is your name?\n");
    tell_room(environment(),
      "The little girl says: My friends call me Gina.\n");
}

void state_murderer(string str, object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: What do you know about "+
      capitalize(str)+"?\n");
    if(murderer==str && TPC>random(LIE)){
	tell_room(environment(),
	  "The little girl says: "+capitalize(str)+" is a very fierce person.\n"+
	  "The little girl says: I think he may have done it... maybe.\n");
    }
    else {
	tell_room(environment(),
	  "The girl says: "+capitalize(str)+" is my friend!"+
	  " He is not a murderer, hmmmph!\n");
	environment()->set_done(1);
    }
}

void state_murder_weap(string str, object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: Could the "+str+
      " be the murdering weapon?\n");
    if(murder_weap==str && TPC>random(LIE)){
	tell_room(environment(),
	  "The little girl says: I think so, I am not familiar with weapons though.\n");
    }
    else {
	tell_room(environment(),
	  "The little girl says: I don't think so, but I'm just a little girl.\n");
    }
    environment()->set_done(2);
}
void state_murder_room(string str, object TP){
    tell_room(environment(TP),
      TP->query_name()+" asks: Do you think the murder was "+
      " committed at the "+str+"?\n");
    if(murder_room==str && TPC>random(LIE)){
	tell_room(environment(),
	  "The little girl says: Yes, I was hiding there when it happened.\n");
    }
    else {
	tell_room(environment(),
	  "The little girl says: Maybe not.\n"+
	  "The little girl says: I did not see anything happen there.\n");
    }
    environment()->set_done(3);
}
