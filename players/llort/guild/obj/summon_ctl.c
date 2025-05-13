#define E environment

object link;
int is_aggr,was_aggr;
int encaged;
int act_follow;
string home;

dump() {
  write("------\n");
  write(is_aggr+" -- is_aggr\n");
  write(was_aggr+" -- was_aggr\n");
  write(encaged+" -- encaged\n");
  write(act_follow+" -- act_follow\n");
  write(home+" -- home\n");
}

id(a) { return a=="summon_ctl"; }

query_name() { return "summon_control"; }

init_me(ctl,aggr,oldaggr,loc) {
    if(link) return;
    link=ctl;
    is_aggr=aggr;
    was_aggr=oldaggr;
    encaged=1;
    home=loc;
    call_out("test_cage",1);
}

query_was_aggressive() { return was_aggr; }

test_cage() {
    if(!("players/llort/guild/tower/summon9")->test_oct()) encaged=0;  
    else call_out("test_cage",2);
    if(!encaged && is_aggr) set_follow(80);
}

set_follow(per) {
    act_follow=per;
    call_out("follow",0,act_follow);
}

follow(per) {
    if(!link || act_follow==0 || encaged) return;
    if(present(link->query_real_name(),E(E(this_object())))) {
        if(!per) per=act_follow;
    } else if(per) {
        if(random(100)>per) per=0;
        else {
            E(this_object())->move_player("following "+link->query_name(),
                                          E(link));
            tell_object(link,E()->query_name()+" arrives, following you.\n");
        }
    }
    call_out("follow",1,per);
}

free() {
    if(encaged || (E()->query_attack() &&
                   present(E()->query_attack(),E(E())))) {
        call_out("free",5);
        return 0;
    }
    E()->set_aggressive(was_aggr);
    E()->move_player("home#"+home);
    tell_object(link,E()->query_name()+" leaves home.\n");
    destruct(this_object());
    return 1;
}
