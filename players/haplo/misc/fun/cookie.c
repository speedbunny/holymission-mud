#define SN capitalize(this_player()->query_name())
#define TP this_player()
#define HERE environment(TP)
#define DN capitalize(dest->query_name())
#define HAM this_object()

object dest;

id(str) {return str=="cookie";}

get(str) {return 1;}

drop(str) {
 if(query_verb()=="drop"||query_verb()=="quit") 
    {write("As you drop the cookie you notice that you made the cookie crumble.\n");
     destruct(HAM);
     return 1;}
 else {return;}}

reset(arg) {}

short() {return "A cookie";}

long() {
write("Its a circular cookie. There are chocolate chips throughout the cookie.\n"+
       "Maybe you should try: throw cookie to <player>\n"+
       "               eat cookie\n");
 return 1;}

init() {
 add_action("throw","throw");
add_action("eat","eat");
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
else if(id(str)) {notify_fail("Throw cookie to whom?\n"); return;}
 else if(sscanf(str,"%s to %s",what, who)!=2) {
    notify_fail("I don't understand\n"); return;}
 else if(!id(what)) {notify_fail("Throw what?\n"); return;}
 else if(!dest=find_player(who)) {
   notify_fail("Throw it to whom?\n"); return ;}
 else if(dest==TP) {
 write("You toss the cookie in the air.\n");
  broadcast(filter_array(users(),"room_filter",HAM),
  SN+" flips the chocolate chip cookie in the air.\n");
  return 1;}
 else if(present(dest,HERE)) {
   write("You toss the cookie with much care across the room to "+DN+".\n");
   tell_object(dest,SN+" tosses you a tasty cookie.\n");
    broadcast(filter_array(users(),"room_filter",HAM),
    SN+" tosses a tasty cookie across the room to "+DN+".\n");
    transfer(HAM,dest);
    dest=0;
    return 1;}
 else {
  tell_object(TP,"WOW! You see a chocolate chip cookie thrown across the sky to "+DN+"!\n");
   broadcast(filter_array(users(),"throw_filter",HAM),
            "WOW! "+SN+" threw a cookie across the sky to "+DN+"!\n");
  tell_object(dest,SN+" threw a tasty cookie to you.\n");
   transfer(HAM,dest);
   dest=0;
   return 1;}
}

eat(str) {
if(!str) {notify_fail("Eat what?\n"); return;}
else if(!id(str)) {notify_fail("Throw what?Eat what?\n"); return;}
 else {
   tell_object(TP,
   "YUM!! That chocolate chip cookie tasted DELIGHTFUL!!\n");
   broadcast(filter_array(users(),"room_filter",HAM),
   "You hear a munching noice as "+SN+" eats the tasty cookie.\n");
   return 1;}
 }


