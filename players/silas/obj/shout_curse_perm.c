#define TP	this_player()
#define RNAME	query_real_name()

int do_say() {
  write("You don't feel able to do that in your present condition!\n");
  return 1;
}

void dest_me() {
  destruct(this_object());
  return;
}

int start(object ob,int _time,object wizard) {
  if(!wizard || !ob)
    return 0;
  else  {
    move_object(this_object(),ob);
    tell_object(ob,"You feel your throat swell up and your mouth slam shut.\n");
    tell_object(ob,"You just received a shoutcurse from "
                   +(string)wizard->RNAME+".\n"
                   +"Please mail an Archwiz if you think it was unfair.\n");
    log_file("SHOUT_CURSE",ob->RNAME+" from "+
             (string)wizard->RNAME+" at "+ctime()+".\n");
      
  }
  return 1;
}

// Sauron: Added for maunal starting by a wizard using marker cmds.
int start_by_wiz(int time) {
  return start(environment(this_object()),time,TP);
}

void init_arg(string str) {
  int time;

  time=to_int(str);
  if(time>0)
    start(TP,time,TP);
  else {
    write("shout_curse tells you: Help - no time from init_arg... going to \
destruct!\n");
    dest_me();
  }
}

void finish_curse() {
  tell_object(environment(this_object()),
              "Your feel your throat and mouth recover.\n");
  destruct(this_object());
}

string query_auto_load() {
  return "obj/shout_curse:"+find_call_out("finish_curse");
}

// Mangla: added these for compat with qmunicator code.
int id(string str) {
  return str=="shcurse";
}

string query_name() {
  return "shcurse";
}

int get() {
  return 1;
}

int drop() {
  return 1;
}

void init() {
  if(!creator(this_object()) && !environment() || !living(environment()))
    call_out("dest_me",1);
  else {
    if(!TP && !creator(this_object())
           && !living(environment(this_object())))
      call_out("dest_me",1);
  }
  add_action("do_say", "deutsch");
  add_action("do_say", "de");
  add_action("do_say", "18");
  add_action("do_say", "shout");
  add_action("do_say","mt");
  add_action("do_say","qsay");
  add_action("do_say","qtell");
  add_action("do_say","qshout");
  add_action("do_say", "tell");
  add_action("do_say", "rtell");
  add_action("do_say", "rshout");
}
