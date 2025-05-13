/* spy.c 910425 Herp */

#define LEVEL this_player()->query_level()
#define CHECK_OWNER if (owner && owner!=this_player()) { write("This spy isn't working for you !\n"); return 1; }

object spy_dest;		/* Where to spy			  */
object owner;			/* Whom does the spy belong to ?  */
string owner_name;		/* Whom does the spy belong to ?  */
string my_name;			/* What's the spy's name ? 	  */
string my_cap_name;		/* capitalized version		  */
string old_cap_name;		/* guess what			  */
int spy_reporting;		/* Be quiet now ? Or keep talking */
int spy_to_player;		/* Report to a player or a room   */

/* this isn't beautifull: using global variables, but how is     */
/* LPC doing the following: proc(type *param); ???               */

object p1;
int p2;

id(str) { if (str=="spy" && LEVEL > 19) return 1; }

short() { 
  if (LEVEL > 19)
    if (owner)  
       if (my_name) return my_cap_name + " (" + owner_name + "'s spy)";
       else return owner_name + "'s spy"; 
    else return "Secret spy";
}

long() { if (LEVEL > 19)
  if (owner && owner!=this_player()) { write(short()+".\n"); return; } 
  write("A Spy for wizards, invisible for normal players.\n");
  write("He reports everything he hears in his current room to you,\n");
  write("to another room or to where ever you want !\n");
  write("Available commands are:\n");
  write("spy on                enables reporting.\n");
  write("spy off               disables reporting.\n");
  write("spy to <dest>         sets reporting to a specific room.\n");
  write("spy to env <dest>     sets reporting to the environment of <dest>.\n");
  write("spy to me             sets reporting to you.\n");
  write("spy to here           sets reporting to your current room.\n");
  write("spy from <dest>       moves the spy to the specified location.\n");
  write("spy from env <dest>   moves the spy to the environment of <dest>.\n");
  write("spy from here         would be the same as dropping the spy.\n");
  write("debug                 shows current setting.\n");
  write("corrupt spy           the spy will serve to your commands.\n");
  write("codename <pseudonym>  the nickname for your top-secret spy.\n");
  write("tell spy 'come'       the spy will return to you, finishing his job.\n"); 
  write("tell spy '<command>'  the spy will execute a command from above.\n");
  return;
}
reset(arg) {
  if (arg) return;
  enable_commands();
}
  
init() {
  add_action("spy","spy");
  add_action("debug","debug");
  add_action("corrupt","corrupt");
  add_action("codename","codename");
}

query_name() { return my_name; }

query_npc() { return 1; }

spy(str) {
  if (!str || LEVEL < 20) return;
  CHECK_OWNER
  if (!owner) { write("You must corrput him first !\n"); return 1; }

  if (do_spy(str)) write("Ok.\n");
  return 1;
}

corrupt(str) {
  if (!str || LEVEL < 20) return;
  CHECK_OWNER
 
  owner=this_player();
  owner_name=this_player()->query_name();
  write("You corrupted this witted spy ! He's working for you now.\n");
  write("He's waiting for the operation to start ...\n");
  write("He's waiting for his codename !\n");
  return 1;
}

codename(str) {
  if (!str || find_living(str) || LEVEL < 20) return;
  CHECK_OWNER
  if (!owner) { write("You must corrput him first !\n"); return 1; }

  old_cap_name = my_cap_name; 
  my_name = lower_case(str);
  my_cap_name = capitalize(my_name);
  set_living_name(my_name);
  if (old_cap_name) write(old_cap_name+" is now known as "+my_cap_name+"\n");
  return 1;
}

debug() {
  if (LEVEL > 19) {
  CHECK_OWNER
  write("TO = ");
    write(spy_dest);
    if (spy_dest) write(" " + spy_dest->short());
    write("\n");
  write("REPORTING = " + spy_reporting + "\n");
  write("TO_PLAYER = " + spy_to_player+ "\n");
  write("OWNER = ");
    if (owner) write(owner->short()); else write("0");
    write("\n");
  return 1;
  }
}

catch_tell(str) {
 string who,what,cmd;
 
 if (!owner) return;
 if (sscanf(str,"%s tells you: %s",who,what)!=2 && who!=owner_name) {
    if (!spy_reporting || !spy_dest) return; 
    if (spy_to_player) { tell_object(spy_dest,my_cap_name+": "+str); return; }
    if (spy_dest!=environment()) tell_room(spy_dest,my_cap_name+": "+str);
    return;
  }
  else { /* the Master :-) called us */
   if (sscanf(what,"%scome%s",cmd)) {
      move_object(this_object(),environment(owner));
      tell_object(owner,my_cap_name+" is back.\n");
      return;
   }
   if (sscanf(what,"codename %s\n",cmd)==1) { codename(cmd); return; }
   if (sscanf(what,"spy %s\n",cmd)==1) { do_spy(cmd); return; }
   if (do_spy(what)) return; 
   tell_object(owner,"The spy didn't understand your last command...\n");
   return;
  }
}

do_spy(str) {
  int env;
  if (str=="on") {
     spy_reporting = 1;
     say(this_player()->query_name() + " turns on " + short() +".\n",this_player());
     spy_reporting = 1; 
     return 1; 
}
  if (str=="off") { 
     spy_reporting = 0;
     say(this_player()->query_name() + " turns off " + short() +".\n",this_player()); 
     return 1; 
}
  if (sscanf(str,"to env %s",str)) { set_spy_dest(str,"env"); return 1; }
  if (sscanf(str,"to %s",str)) { set_spy_dest(str,""); return 1; }
  if (sscanf(str,"from env %s",str)) { move_spy(str,"env"); return 1; }
  if (sscanf(str,"from %s",str)) { move_spy(str,""); return 1; }
  
}
 
set_spy_dest(str,str2) {
 if (find_anything(str,str2)) { spy_dest=p1; spy_to_player=p2; return; }
}

move_spy(str,str2) {
 if (find_anything(str,str2)) { 
     say(short() + " left to " + p1->short() + ".\n");
     move_object(this_object(),p1);
     return; 
 }
}

find_anything(str,str2) {
  if (str=="here") {
    p2 = 0; 
    p1 = environment(this_player());
  }
  else if (str=="me") {
    p2 = 1;
    p1 = this_player();
  } 
  else {
    p2 = 0; p1 = find_object(str);
    if (!p1) { p2 = 1; p1=find_living(str); }
    if (!p1) { write("No such object/living thing.\n"); return; }
  }

  if (str2=="env") {
    p2 = 0; p1 = environment(p1);
    if (!p1) { write("No such object/living thing.\n"); return; }
  }
  return 1;
}
