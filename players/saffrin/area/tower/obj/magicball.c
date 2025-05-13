inherit "/obj/treasure";

#define SN capitalize(this_player()->query_name())
#define TP this_player()
#define HERE environment(TP)
#define DN capitalize(dest->query_name())
#define BALL this_object()

object dest;

reset(arg) {

  if (arg) return;
  set_name("a magic crystal ball");
  set_alias("ball");
  set_short("A magic crystal ball");
  set_long("This is a magic crystal ball that is fun to play with.  It glows \n"+
           "green from its center.\n"+
           "You might try: throw ball to <player>\n");
  set_weight(1);
  set_value(100);
}
init() {
 add_action("throw","throw");
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

throw(str) {
 string who, what;
 if(!str) {notify_fail("Throw what?\n"); return;}
 else if(id(str)) {notify_fail("Throw ball to whom?\n"); return;}
 else if(sscanf(str,"%s to %s",what, who)!=2) {
    notify_fail("I don't understand\n"); return;}
 else if(!id(what)) {notify_fail("Throw what?\n"); return;}
 else if(!dest=find_player(who)) {
   notify_fail("Throw it to whom?\n"); return ;}
 else if(dest==TP) {
  write("You throw the ball up and down.\n");
  broadcast(filter_array(users(),"room_filter",BALL),
   SN+" tosses a magic ball around.\n");
  return 1;}
 else if(present(dest,HERE)) {
    write("You skillfully toss the magic ball across the room to "+DN+".\n");
    tell_object(dest,SN+" tosses you a magic ball.\n");
    broadcast(filter_array(users(),"room_filter",BALL),
     SN+" tosses a magic ball across the room to "+DN+".\n");
    transfer(BALL,dest);
    dest=0;
    return 1;}
 else {
   tell_object(TP,"You throw the magic ball across the sky to "+DN+"!\n");
   broadcast(filter_array(users(),"room_filter",BALL),
             "Duck!  "+SN+" throws a magic ball across the sky to "+DN+"!\n");
   tell_object(dest,SN+" throws a magic ball to you.\n");
   transfer(BALL,dest);
   dest=0;
   return 1;}
}
