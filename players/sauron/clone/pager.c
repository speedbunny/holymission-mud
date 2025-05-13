inherit "/obj/treasure";

#define DO_BEEP	(sound || query_idle(environment())>120)
#define BEEP	"\a"
#define PAGER   "/players/sauron/clone/pager"

int sound;

int send_page(string str) {
  string msg;
  object ob,pager;

  if(!str || sscanf(str,"%s %s",str,msg)!=2) {
    notify_fail("Page whom?\n");
    return 0;
  }
  else
    ob=find_player(str);
  if(!ob) {
    notify_fail(capitalize(str)+" is not logged on at this time.\n");
    return 0;
  }
  else if(!interactive(ob)) {
    notify_fail(capitalize(str)+" is linkdead... no point paging them!\n");
    return 0;
  }
  else if(!(pager=present("pager",ob)) ||
          explode(file_name(pager),"#")[0]!=PAGER[1..<1]) {
    notify_fail(capitalize(str)+" isn't carrying a pager.\n");
    return 0;
  }
  else if(str==this_player()->query_real_name()) {
    notify_fail("You can't page yourself.\n");
    return 0;
  }
  else {
    printf("You send the message '%s' to %s'%s pager.\n",
           msg,capitalize(str),(str[<1..<1]=="s"?"":"s"));
    pager->receive_page(this_player()->query_real_name(1),msg);
    return 1;
  }
}

void receive_page(string str,string msg) {
  object env;

  if(!(env=environment()) || !interactive(env))
    return;
  else {
    tell_object(env,sprintf("%sYour pager vibrates.\n",
                            (DO_BEEP?BEEP:"")));
    set_long("This is a pager which will allow you to page someone if \
they are idle, and they also carry a pager. There is a small button \
which you can use to turn the beep of the pager on or off.\nIn a little \
window, you can read the msg \"From "+capitalize(str)+": "+msg+"\"\n");
  }
}

int toggle_button(string str) {
  if(!str || str!="button") {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }
  else {
    sound=!sound;
    printf("You turn your pager's beep %s.\n",
           (sound?"on":"off"));
    return 1;
  }
}

void init_arg(mixed arg) {
  sscanf(arg,"%d",sound);
}

string query_auto_load() {
  return PAGER+":"+sound;
}

int drop() {
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_id("pager");
    set_alias("beeper");
    set_weight(0);
    set_value(0);
    set_short("A pager");
    set_long("This is a pager which will allow you to page someone if \
they are idle, and they also carry a pager. There is a small button \
which you can use to turn the beep of the pager on or off.\n");
  }
}

void init() {
  ::init();
  add_action("send_page","beep");
  add_action("send_page","page");
  add_action("toggle_button","press");
  add_action("toggle_button","push");
}
