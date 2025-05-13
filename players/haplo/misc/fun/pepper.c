inherit "obj/treasure";
#include "/players/exos/defs.h"
int uses;

reset (arg) {
  if(arg) return;
  set_id("pepper_spray");
  set_name("pepper");
  set_alias("mace");
  set_short("A small pouch of pepper");
  set_long("This pouch is full of pepper.  It is used on annoying\n"+
          "people who bother the lovely ladies of Holy Mission.  Just type\n"+
         "pepper<name>\n"+
          "Love, Exos.\n");
  set_weight(1);
  set_value(100);
  uses=5;
}

init() {
  ::init();
  AA("mace","pepper");
}

mace(str) {
  object who;

  if(!str) {
    write("Pepper whom?\n");
    return 1;
  }
  who=present(str,ENV(TP));
  if(!who || !living(who)) {
    write("Your pepper would have no effect!\n");
    return 1;
  }
  else if(who->QNPC) {
    write("That creature is not accosting you!\n");
    return 1;
  }
  else if(who->QRNAM=="exos") {
    write("Please do not pepper Exos!\n");
    return 1;
  }
  else {
    write("You dump pepper in "+who->QNAME+"'s eye!\n");
    say(TPN+" dumps pepper in "+who->QNAME+"'s eye!\n");
    TELL(who,TPN+" throws pepper in your eye!\n"+
      "You run blindly!\n"+
       "You decide not to accost "+TPN+" again!\n");
    who->RUN;
    write(CAP(who->QNAME)+" runs away screaming!\n");
    say(CAP(who->QNAME)+" runs away screaming!\n");
    uses--;
    if(uses==0) DEST(TO);
    else set_value(uses*20);
    return 1;
  }
}
