#define MOVEME 1
object collared;
object me;
string collarname;
string myname;
int i;
int who, whot;
 
short() {
      if (who == 1) {
      return "A ring of following: <"+collarname+">";
      } else
      return "A ring of following";
}
 
query_value() { return 500; }
query_weight() { return 1; }
 
long() {
    write("This ring allows you to follow someone.\n");
    write("Type in follow <player> to follow.\n"+
          "Type in unfollow to stop.\n");
    return 1;
}
 
id(str) {
    return str == "ring" || str == "ring of following";
}
 
follow(str) {
    object levc, levm;
    object themto;
    string check;
 
    if (!str) { 
          write("Follow whom?\n");
          return 1; 
     }
    collared = present(lower_case(str), environment(this_player()));
    collarname = capitalize(str);
    if (!collared) {
    write(collarname+ " is not here.\n");
    return 1;
    }
    if (!living(collared)) {
    write(collarname+" is not alive!\n");
    return 1;
    }
    if (collared == this_player()) {
    write("Is this really necessary?\n");
    return 1;
    }
    me = this_player();
    myname = call_other(me, "query_name");
    themto = present("ring of following",collared);
    levc = call_other(collared,"query_level",0);
    levm = call_other(me,"query_level",0);
#if 0
     if((levc > 29 && levm < 29)) { /* Herp / changed */
#endif
/*     if (...() && collared()->query_wizard()) Dago:nobrackets here! */
     if (!me->query_immortal() && collared->query_immortal()) {
     write("You cannot follow a wiz, sorry.\n");
     return 1;
     }
     if(themto) {
          check = call_other(themto,"query_collarname",0);
          whot = call_other(themto,"query_who",0);
          if((check == myname) && whot) {
          write(collarname+" is already following you!\n");
          return 1;
          }
    }
    write("You start following "+collarname+".\n");
    say(capitalize(myname)+" is now following "+collarname+".\n");
    set_heart_beat(1);
    who = 1;
    return 1;
}
 
release(str) {
    if (who != 1) {
    write("You are not following anyone!\n");
    return 1;
    } else
    if (who == 1) {
    write("You stop following "+collarname+".\n");
    say(myname+" stops following "+collarname+".\n");
    collared = 0;
    who = 0;
    set_heart_beat(0);
    return 1;
    }
}
 
init() {
    add_action("follow"); add_verb("follow");
    add_action("release"); add_verb("unfollow");
}
 
get() { return 1; }
 
heart_beat() {
   object there;
   i = 1;
     there = environment(me);
   if((there != environment(collared)) && (i == MOVEME)
/* Herp: the ring needs to be present in the player ! */
     && (me==environment(this_object()))
   ) {
        if (environment(collared)->query_property("no_teleport")) {
	   tell_object(me,"You have lost "+collarname+".\n");
	   collared=0;
	   who=0;
	   set_heart_beat(0);
	   return 1;
	}
   tell_room(environment(collared), myname+" arrives, following "+
     collarname+".\n");
   move_object(me, environment(collared));
   tell_room(there, myname+" leaves, following "+
     collarname+".\n");
   tell_object(me, "You leave, following "+collarname+".\n");
   }
}
 
query_collarname() { return collarname; }
 
query_who() { return who; }
 
