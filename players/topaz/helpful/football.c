#define who capitalize(call_other(this_player(), "query_real_name", 0))
#define it lower_case(str)
#define ob  find_player(it)
#define me (call_other(this_player(), "query_wizard", 0))
string name;
int weight, value;
 
id(str) { return str == "ball" || str == "magic ball"; }
 
get(){ return 1; }
 
query_value() { return 10; }
 
short(){ return "A magic ball"; }
 
long(){ write("An offical magic ball! throw <player> or kick <player>.\n");}
 
reset()  {
         weight = 0;
         value = 10;
}
 
init(){
     add_action("throw"); add_verb("throw");
     add_action("kick"); add_verb("kick");
     add_action("drop_object"); add_verb("drop");
}
 
drop_object(str) {
    if (str == "all") {
        drop_object("magic ball");
        return;
    }
    if (!str || !id(str)) return 0;
	if(environment() != this_player()) return 0;
    write("The magic ball explodes when it hits the ground!\n");
    say(call_other(this_player(), "query_name") +
    " drops a magic ball. It explodes into a million pieces.\n");
    destruct(this_object());
    return 1;
}
 
throw(str){
     if(!ob){
     write("No person is playing right now!\n");
     return 1;
     }
        if((ob->query_invis() || ob->query_wizard())
        && !(this_player()->query_wizard())) {
         /* capa: auf query_level > 19 bzw. query_level < 20 */
	write("Wizards don't like to be bugged with games.\n");
  return 1;
  }
     if(!present("magic ball",ob)) {
  if(me) {    /* capa: me auf query_wizard geaendert (z. 4)  */
  if(!(ob->query_wizard())) {
     write("You throw the magic ball to "+capitalize(str)+".\n");
     write("That is a player I hope you did not throw too hard.\n");
     move_object(this_object(), ob);
     tell_room(environment(ob), "You see a magic ball flying through the air.\n");
     tell_room(environment(ob), "\n" +
             "The magic ball is going towards "+capitalize(str)+".\n");
     tell_room(environment(ob), "The magic ball is really moving fast!\n");
     tell_room(environment(ob), "The magic ball was thrown by "+who+".\n");
     tell_room(environment(ob), "That is a wizard!\n");
     tell_room(environment(ob), "\n");
     tell_room(environment(ob), "The ball hits "+capitalize(str)+" hard!\n");
     tell_object(ob, "You feel like puking, the ball hit you so hard!\n");
     tell_room(environment(ob), "\n" +
               ""+capitalize(str)+" starts to cough uncontrollably!\n");
     call_other(ob, "force_us", "cough");
     call_other(ob, "force_us", "cough");
     call_other(ob, "force_us", "cough");
     call_other(ob, "force_us", "puke");
     return 1;
     }
}
     write("You throw the magic ball to "+capitalize(str)+".\n");
     move_object(this_object(), ob);
     tell_room(environment(ob), "You see a magic ball flying through the air.\n");
     tell_room(environment(ob), "The magic ball is swiftly thrown to " +
                ""+capitalize(str)+" by "+who+".\n");
     tell_room(environment(ob), ""+capitalize(str)+" jumps into the air" +
                         " and catches it.\n");
     tell_object(ob, "You catch a perfect spiral thrown to you.\n");
     return 1;
}
     write("That person has a magic ball already, only one per player.\n");
     return 1;
}
 
kick(str){
     if(!str) return 0;
     if(!ob) {
     write("No such person is playing now.\n");
     return 1;
     }
if(str == "magic ball"){
     write("You clumbsily kick the magic ball.\n");
     call_other(this_player(),"remote_say","A magic ball slowly to you.\n");
     move_object(this_object(), environment(this_player()));
     return 1;
     }
        if((ob->query_invis() || ob->query_wizard())
        && !(this_player()->query_wizard())) {
       /* capa: query_level     */
	write("Wizards don't like to be bugged with games.\n");
  return 1;
  }
     if(!present("magic ball",ob)) {
     write("You kick the magic ball to "+capitalize(str)+".\n");
     move_object(this_object(), ob);
     tell_room(environment(ob), "A magic ball kicked by "+who+" flies over your"+
                         " head on its way to "+capitalize(str)+".\n");
     tell_room(environment(ob),""+capitalize(str)+" leaps into the air and" +
                              " catches the magic ball with one hand!\n");
     tell_object(ob, "A magic ball kicked by "+who+" lands in your arms.\n");
     return 1;
}
     write("That person has a magic ball already, only one per player.\n");
     return 1;
}
