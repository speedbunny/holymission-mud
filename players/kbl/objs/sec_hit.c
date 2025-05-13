define env     environment
#define TP      this_player()
#define TO      this_object()
#define SAY(x)  tell_room(env(tp),x)

inherit "obj/weapon";
object tp;
string second_hit;


reset(arg){
    ::reset(arg);
    if(arg) return;
    second_hit=0;
}
hit(attacker) {
    int tmp;

    tmp=::hit(attacker);
    set_heart_beat(1);
    return tmp;
:z
    return tmp;
}


heart_beat() {
    object enmy;


    if((enmy=tp->query_attack()) && env(tp)==env(enmy) && random(20)<tp->query_l
evel()){
        tp->attack();
tell_room(environment(this_player()),
          this_player()->query_name()+"'s sword moves with astonishing speed and
 "+
          "cuts into its opponent again.\n");
    }
    else set_heart_beat(0);
}

wield(str) {
    int r;

    if (r=::wield(str)) {
        tp=TP;
    }
    return r;
}

set_second_hit(s) { second_hit=s; }
