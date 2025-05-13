#define SN capitalize(this_player()->query_name())
#define TP this_player()
#define HERE environment(TP)
#define DN capitalize(dest->query_name())
#define HAM this_object()

object dest;

id(str) {return str=="hamster";}

get(str) {return 1;}

drop(str) {
 if(query_verb()=="drop"||query_verb()=="quit") 
    {write("As you let go of the hamster, it sighs a breath of relief and scurries away.\n");
     destruct(HAM);
     return 1;}
 else {return;}}

reset(arg) {}

short() {return "A small, furry hamster";}

long() {
 write("Its a cute, small, furry animal.  It squeaks as you crush it in your\n"+
       "hand, and its little eyes seem ready to burst out of its head.  Since\n"+
       "you've got nothing better to do than play with a small rodent, you might\n"+
       "as well have a little fun with it.\n"+
       "You might try: throw hamster to <player>\n"+
       "               squeeze hamster\n");
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
 if(!str) {notify_fail("Throw what?\n"); return;}
 else if(id(str)) {notify_fail("Throw hamster to whom?\n"); return;}
 else if(sscanf(str,"%s to %s",what, who)!=2) {
    notify_fail("I don't understand\n"); return;}
 else if(!id(what)) {notify_fail("Throw what?\n"); return;}
 else if(!dest=find_player(who)) {
   notify_fail("Throw it to whom?\n"); return ;}
 else if(dest==TP) {
  write("You throw the hamster up and down.\n");
  broadcast(filter_array(users(),"room_filter",HAM),
   SN+" tosses a small hamster around.\n");
  return 1;}
 else if(present(dest,HERE)) {
    write("You skillfully toss the hamster across the room to "+DN+".\n");
    tell_object(dest,SN+" tosses you a small hamster.\n");
    broadcast(filter_array(users(),"room_filter",HAM),
     SN+" tosses a small hamster across the room to "+DN+".\n");
    transfer(HAM,dest);
    dest=0;
    return 1;}
 else {
   tell_object(TP,"Squeal! You hurl the hamster across the sky to "+DN+"!\n");
   broadcast(filter_array(users(),"throw_filter",HAM),
             "Squeal!  "+SN+" hurls a hamster across the sky to "+DN+"!\n");
   tell_object(dest,SN+" throws a small hamster to you.\n");
   transfer(HAM,dest);
   dest=0;
   return 1;}
}

squeeze(str) {
 if(!str) {notify_fail("Squeeze what?\n"); return;}
else if(!id(str)) {notify_fail("Throw what?Squeeze what?\n"); return;}
 else {
   tell_object(TP,
     "The hamster writhes in pain as you squeeze it in your hand.  How amusing!\n");
   broadcast(filter_array(users(),"room_filter",HAM),
     "You hear a faint squeak as "+SN+" tortures a small rodent.\n");
   return 1;}
 }


