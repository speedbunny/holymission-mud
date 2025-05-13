inherit "/obj/treasure";
 
#include "/obj/obj_defs.h"
#include "/obj/lw.h"
 
int charges;
 
int foo() {
  return 1;
}
 
int gaze_eye(string str) {
  object   *inven, who, targetloc;
  string   s;
  int      i, sz;
 
  if(!str) {
    write("You gaze in the air....\n");
    say(TP->NAME+" gazes in the air.\n");
    return 1;
  }
  if(sscanf(str,"at %s",s) == 1)
    str=s;
  if(!who = find_living(str)) {
    printf("A voice inside your head tells you %s is not alive right now.\n",
           CAP(str));
    say(TP->NAME + " peers perplexedly into a catseye.\n");
    return 1;
  }
  if(who->IMM) {
    printf("Do not even THINK about looking at a wiz.\n");
    printf("This is for finding players, not wizards.\n");
    return 1;
  }
  write("You gaze into the catseye and see " + CAP(str) + ".\n\n");
  say(TP->NAME + " peers into a catseye.\n");
  targetloc = ENV(who);
  targetloc->long();
  write("\n");
  TELL(who, "You feel like someone is watching you.\n");
  write("Looking through the eye, you see that " + str + " is carrying:\n");
  inven = all_inventory(who);
  if(inven)
    for(sz=sizeof(inven), i=0; i<sz; i++)
      if(s = inven[i]->short())
        write(s + "\n");
 
  if(charges == 0) {
    writelw("The catseye begins to glow with a holy light. "+
            "The light grows brighter and brighter. "+
            "When you can see again, the eye is gone.\n");
    say(TP->NAME + " begins to glow brightly!\n");
    say("The blinding aura fades to a dull glow and vanishes.\n");
    destruct(TO);
  }
  else
    charges--;
  return 1;
}
 
int _drop_object(string str) {
  if(str == "all") {
    _drop_object("catseye");
    return 0;
  }
  if(!str || str!="catseye" || str!="eye")
    return 0;
  if(ENV() != TP)
    return 0;
  write("The catseye shatters into a million pieces.\n");
  say(TP->NAME + " drops a catseye. It shatters into a million pieces.\n");
  destruct(TO);
  return 1;
}
 
void reset(int arg) {
  charges=random(5)+1;
  if(arg) return;
 
  set_short("A catseye");
  set_long("This looks like a cats eye embedded in a black stone. " +
           "The cats eye seems to have a look to it that is somehow " +
           "giving you the impression it is following you. " +
           "The eye is glowing with a soft inner light. " +
           "You seem to be gazing at a door through space.\n");
  set_value(2500);
  set_weight(2);
  set_alias("eye");
  set_alt_name("catseye");
}
 
void init() {
  add_action("gaze_eye","gaze");
  add_action("_drop_object","drop");
}
