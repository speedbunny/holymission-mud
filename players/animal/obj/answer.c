#include "../../../obj/living.h"
 
int busy;
object own, own1;
 
short()
{
     return "Animal growls: Who you looking at?";
}
 
long() {
        write("This wizard is always alert, and you get blinded\n"+
              "by his power for a minute. When you regain your\n"+
              "eyesite, you notice that he is looking at you!\n");
}
 
id(str) {
  return (str == "animal" || str == "answer");
}
 
reset(arg) {
        if(!arg) {
        own1 = this_player();
        busy = 1;
        age = 1200000201;
        own = find_living("animal");
        }
	is_invis = 1;
  set_heart_beat(1);
  name = "animal";
  cap_name = capitalize(name);
  level = 400;
  max_hp = -10000;
  hit_point = -20000;
  spell_points = -20000;
  enable_commands();
  set_living_name("animal");
}
 
is_player() {
  if ((!own) || (!interactive(own)) ) {return 0; }
  else { return 1; }
}
 
catch_tell(str) {
string whom;
string whomm, what;
object whommm;
  if (sscanf(str,"%s tells you: important%s\n",whom,what) == 2 ||
  sscanf(str,"%s tells you: Important%s\n",whom,what) == 2 ||
  sscanf(str,"%s tells you: IMPORTANT%s\n",whom,what) == 2) {
  say("("+whom+") [Important] ->"+what+"\n");
  log_file("animal","("+whom+") [Important] ->"+what+"\n");
  return 1;
  }
  if(!str || (sscanf(str,"%s tells you:%s\n",whom,what) != 2)) return;
  whomm = lower_case(whom);
  whommm = find_living(whomm);
  if ((busy == 1) && (!ok(whomm)))  {
  if(!whommm) return;
  tell_object(whommm,
  "You hear a loud growl in your head: I'm sorry, but Animal has left me\n"+
  "instructions for him not to be disturbed.  If this is terribly\n"+
  "important, then re-tell the message, and make the first word 'important'\n"+
  "and the message will get through.  Otherwise, he will respond to you\n"+
  "when he gets some free time.\n");
  log_file("animal","("+whom+") -> "+what+"\n");
  return 1;
  }else{
  tell_object(own1,"("+whom+") "+str);
  log_file("animal","("+whom+")->"+what+"\n");
 }
}
 
 
query_name() { return cap_name; }
 
query_real_name() { return name; }
 
toggle_busy() {
              if (busy == 1) { busy = 0; }
                else { busy = 1; }
	if(busy == 1) return "You are now busy";
	return "You are NOT busy";
}
 
heart_beat()  {
        if(!present(own1)) {
/*
        say("You see a brilliant flash, when ya look again, Animal is gone!\n");
       say("You hear an ear-splitting roar! Animal has arrived!\n");
*/
	move_object(this_object(),environment(own1));
        }
        call_other(this_object(),"reset",1);
       age = age + 1;
}
 
query_info() {
        return "INFO???? I need no info either!!!!!";
}
 
query_quests() {
        return "QUESTS???? I need no stinkin quests!!!!!";
}
 
ok(str) {
    return (str == "pooka" || str == "martyr" || str == "uther" ||
          str == "bectile" || str == "bambii" || str == "ayriel" ||
          str == "animalw");
}
 
