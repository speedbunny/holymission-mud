inherit "obj/monster.c";

#include "alder.h"

#define MOVEME 1
object collared;
object me;
string collarname;
string myname;
int i;
int who, whot;
 
 
int owner_gone, following, reaction_time;
object owner;
string owner_name, followee;

id(str) {
  if(::id(str)) return 1;
  return str == "familiar" || str == owner_name+"'s familiar";
}

set_owner(ob) {
  owner = ob;
  owner_name = owner->query_real_name();
  return 1;
}

catch_tell_hook() {
  if (present(owner_name, environment(this_object())))
    return 1;
  return 0;
}

reset(arg) {
  ::reset();
  if (arg) return ;
  is_npc = 0;
  reaction_time = 0;
  my_commands();
  call_out("set_gone", 1);
}

set_gone() {
  if (!environment(this_object())) {
    owner_gone = 0;
    return;
  }
  if (present(owner_name, environment(this_object())))
    owner_gone = 0;
  else
    owner_gone = 1;
  call_out("set_gone", 1);
}

my_commands() {
  add("kill", "kill");
  add("deliver", "deliver");
  add("stay", "stay");
  add("follow", "follow");
  add("stay","unfollow");
  add("do_a_command","do");
}

kill(arg) {
  object ob;

  ob = find_living(arg);
  if (!ob) {
    tell(owner,name+" tells you: I can not find "+arg+", master.\n");
    return 1;
  }
  if (!present(ob,environment(this_object()))) {
    tell(owner,name+" tells you: "+arg+" is not here.\n");
    return 1;
  }
  tell(owner, name+" whispers: Yes master.\n");
  this_object()->attack_object(ob);
  return 1;
}

deliver(arg) {
  string what, who;
  object gift, here;

  if (!arg) return 0;
  if (sscanf(arg, "%s to %s", what, who) != 2) return 0;
  gift = present(what, owner);
  if (!what) {
    tell(owner, name+" tell you: You are not carrying the "+what+", "+owner_name+".\n");
    return 1;
  }
  if (gift->drop()) {
    tell(owner, name+" tells you: I can not take that from you.\n");
    return 1;
  }

  who = find_living(who);
  if (!who) {
    tell(owner, name+" tell you: I can not find that person.\n");
    return 1;
  }
  here = environment(this_object());
  if (!present(owner_name))
    tell(environment(owner), short()+" wanders in and takes "+gift->short()+" from "+owner_name+" and wanders out.\n");
  else 
    say(short()+" takes the "+gift->short()+" from "+owner_name+" and wanders out.\n");
  move_object(gift, this_object());
  owner->recalc_carry();
  move_object(this_object(), environment(who));
  say(short()+" wanders in and gives "+gift->short()+" to "+who->query_real_name()+" and wanders.\n",who);
  tell(who, short()+" wanders in and gives "+gift->short()+" to you.\n");
  if (transfer(gift, who)) {
    say("Confused as to why "+who->query_name()+" won't take the gift, "+
short()+" drops it on the floor.\n", who);
    tell(who, short()+" appears confused when it can not give you the gift.  It drops it on the floor.\n"); 
    command("drop "+what, this_object());
  }
  say(short()+" wanders out.\n");
  move_object(this_object(), here);
  say(short()+" wanders in.\n");
  return 1;
}

do_a_command(arg) {
  command(arg);
  return 1;
}

stay() {
  if (present(owner_name, environment(this_object())))
    tell(owner, name+" whispers: Yes, master.\n");
  else
    tell(owner, name+" tells you: Yes, master.\n");
  followee = 0;
  following = 0;
  remove_call_out("follow_call_out");
  return 1;
}

follow(arg) {
  object ob;
  
  if(arg) arg = lower_case(arg);
  if (present(owner_name, environment(this_object())))
    tell(owner, name+" whispers: Yes, master.\n");
  else
    tell(owner, name+" tells you: Yes, master.\n");
  if (!arg || arg == "me") 
    followee = owner_name;
  else {
    if(present(arg,environment(this_object()))) 
      followee = arg;
    else {
      write(arg+" not present!\n");
      return 1;
    }
  }
  following = 1;
  call_out("follow_call_out", 1);
  return 1;
}

follow_call_out() {
  if (!present(followee, environment(this_object())))
    goto_person(followee);
  call_out("follow_call_out", 1);
}

goto_person(arg) {
  object ob;

  say(short()+" wanders after "+owner_name+"\n");
  ob = find_living(arg);  
  if (!ob) {
    destruct(this_object());
    return 1;
  }
  move_object(this_object(), environment(ob));
  say(short()+" wanders in after "+owner_name+"\n");
}
