#pragma strict-types

inherit "/obj/container";
object 	owner;		// player obj
string 	poss;		// possessive player name
int	timer;

#define TIME	200
#define GENERIC 300
#define C	capitalize

string _possessive(string str);
int set_owner(object ob);

void reset(int arg) {
  ::reset(arg);
  if (arg) 
    return;
  set_of_glass(1);
  set_max_weight(50);
  set_name("floating disk"); 
  set_alias("disk");
  set_can_get(0);
  enable_commands();
}

void init() {
  ::init();
  if (!owner) {
    set_owner(this_player());
    poss = C(owner->query_name()
	     +_possessive(owner->query_name()));
  }
  if (!poss) 
    poss = "Paris'";
  set_short(C(poss)+" floating disk.\n");
  set_long(C(poss)+" floating disk.\n");
  set_heart_beat(1);
  timer = random(TIME)+GENERIC;
  add_action("_sit", "sit");
}

void heart_beat() {
  object	ob;
  
  if (!owner) {
    say(poss+" disk wobbles uncertainly in the air.\n");
    return;
  }
  ob = environment(owner);
  if (ob != environment()) {
    say(poss+" disk floats away.\n");
    move_object(this_object(), ob);
    tell_room(ob,poss+" floating disk arrives.\n");
    return;
  }
  if (!--timer) {
    say(poss+" disk wobbles gently above the ground.\n");
    timer=random(TIME)+GENERIC;
  }
}

int set_owner(object ob) {
  owner = ob;
}

string _possessive(string str) {
  /* A simple enough function to return the correct possessive ending
   * to a name
   */
  int i;

  i = strlen(str)-1;	
  if (str[i..i] == "s") 
    return "'";
  return "'s";
}
