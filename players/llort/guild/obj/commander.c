object mon,me,ctl;
dump() { 
  write("-------\n");
  write(mon); write(" -- mon \n");
  write(me); write(" -- me \n");
  write(ctl); write(" -- ctl \n");
}

id(a) { return a=="commander"; }
query_name() { return "command-tool"; }

init_me(m,c) {
    mon=m;
    ctl=c;
    me=environment();
}

init() {
    add_action("comm","command");
}

comm(a) {
string mname,cmd,arg,hlp;
object vic;
    if(!ctl) { destruct(this_object()); return 0; }
    if(this_player()!=me) return;
    if(!(hlp=explode(a," ")) || sizeof(hlp)<2) return;
    mname=hlp[0]; cmd=hlp[1];
    if(sizeof(hlp)>2) arg=implode(hlp[2..sizeof(hlp)-1]," ");
    else arg="";
    if(!mon->id(mname)) return 0;
    if(!present(mname,environment(me))) {
        write(mname+" is not here.\n");
        return 1;
    }
    switch(cmd) {
        case "follow":
            write(mname+" starts following you.\n");
            ctl->set_follow(95);
            break;
        case "stay":
            write(mname+" stops following you.\n");
            ctl->set_follow(0);
            break;
        case "leave":
            ctl->free();
            break;
        case "kill":
            if(!arg || !(vic=present(arg,environment(mon))))
                write("Kill what ?\n");
            else {
                tell_room(environment(mon),mon->query_name()+
                   " turns to attack "+vic->query_name()+".\n");
                mon->attack_object(vic);
                if(random(100) < 50 && !this_player()->query_immortal())
                {
                   ctl->free();
                   write("Your link to the monster broke!\n");
                }
            }
            break; 
        default:
            command(cmd+" "+arg,mon);
    }
    return 1;
}
