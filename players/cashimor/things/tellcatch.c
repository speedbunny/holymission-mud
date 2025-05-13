inherit "obj/thing";

string tofind,last;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("tellcatch");
    set_short(0);
    set_long("Yes, this checks what you are saying...\n");
    set_can_get(1);
    set_weight(0);
    set_value(0);
  }
}

init() {
  ::init();
  add_action("catch_it","say");
  add_action("catch_it","'",1);
}

set_string(str) {
  tofind=str;
}

query_string() {
  return tofind;
}

catch_it(str) {
string str1,str2;
object who;

  who=find_living(tofind);
  if(!who) {
    destruct(this_object());
    return 0;
  }
  str1=query_verb();
  if(!str) str="";
  if(str1[0]=="'"[0]) str=extract(str1,1)+" "+str;
  if(sscanf(lower_case(str),"%s"+tofind+"%s",str1,str2)==2) {
    str1="You magically feel that "+this_player()->query_name()+" says:\n"
     + str+"\n";
    if(str1==last) return 0;
    last=str1;
    tell_object(who,str1);
  }
}

drop(silently) {
  destruct(this_object());
  return 1;
}
