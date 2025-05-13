/* hide_shad */

inherit "/obj/std_shadow";

int no_unhide_msg;

object hide_object() {
    return this_object();
}
 
int hide_shad() {
   return 1;
}
 
void end_shadow(object ob) {
    if(!no_unhide_msg)
        tell_object(me,"You feel exposed.\n");
    say(me->query_name()+" arrives.\n", me);
    me->set_vis();
    return ::end_shadow(ob);
}
 
int attacked_by(object ob) {
    if(me->attacked_by(ob))
        end_shadow(this_object());
}
 
void change_attacker(object ob) {
    end_shadow(this_object());
    return me->change_attacker(ob);         
}
 
varargs mixed attack(object weap, int hands) {
    end_shadow(this_object());
    return me->attack(weap, hands);
}
 
string look_info(int flag) {
    if(!look_inf) 
        look_inf = " [hidden]";
 
    return ::look_info(flag);
}

void set_no_unhide_msg(int i) {
    no_unhide_msg = i;
}
