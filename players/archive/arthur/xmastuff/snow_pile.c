/*Code by Arthur for Holy Mission 140.78.3.1 Date done 12.23.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
int left,hb,logme,newleft,wiz_allow;
reset (arg) {
if (arg) return;
   set_id("A pile of snow");
   set_short("A pile of snow");
   left=30;
   set_heart_beat(1);
   set_alias("snow");
   set_value(0);
   set_weight(100);
}
init() {
   add_action("pick", "get");
   add_action("pick", "take");
   if(TP()->query_immortal()) {
      add_action("left", "left");
      add_action("setsnowball", "setsnowball");
      add_action("wiz_allow", "allowwiz");
      add_action("log", "log");
    }
   ::init();
}
pick (str) {
    if(str !="snowball") return 0;
    if(left==0) {
     write("You go to get a snow-ball, but there is no good snow left for snowballs.\n");
     return 1;}
     left=left-1;
     if(logme == 1) {
        log_file("arthur.snow",file_name(environment(this_object()))+" "+TP()->query_real_name()+" gets a snow-ball.\n");
      }
    if(wiz_allow == 1) {transfer(clone_object("/players/arthur/xmastuff/wsnowball"), TP()); }
    else {transfer(clone_object("/players/arthur/xmastuff/snowball"),TP()); }
     write("You pick up a nice hard snow-ball.\n");
     say(TP()->query_name()+" picks up a snowball.\n");
      return 1;}
get() {return 0;}
left() {
   write("there are "+left+" snowballs left.\nIt was updated "+hb+" seconds ago.\n");
   if(logme == 1){write("It is currently logging.\n");}
   else {write("It is not logging right now.\n");}
   return 1;
    }
heart_beat() { hb=hb+1;
   if(hb==900) {
     tell_room(environment(this_object()), "It starts to snow, causing the snow-pile to be refreshed.\n");
     left=30;
     hb = 0;
     }
    }
no_clean_up() {
    return 1;
}
setsnowball(num) {
   if(!num) return 1;
   if(sscanf(num,"%d",newleft) != 1) {
   write("That number is invalid\n");
   return 1;}
   left=newleft;
   write("You change the number of snowballs to "+left+".\n");
   return 1;}
long() {
      write("Maybe you can get a few snow-balls from this pile.\n");
      if(TP()->query_immortal()) {
      write("Wiz extras:\n          setsnowball - sets number of snowballs.\n          left - shows how long till reset, how many snowballs are left, and\n          if it is currently logging.\n          log - no switches from log on to log off or log off to log on.\n");
     }
    }
log() {
   if(logme==1) {
     logme = 0;
     write("you shut the logging off.\n");
     return 1;}
   else {
     logme = 1;
     write("you turn the logging on.\n");
     return 1;}
    }
wiz_allow() {
   if(wiz_allow !=1) {wiz_allow = 1; write("Wiz throwing now avalable\n"); return 1;}
   else{ wiz_allow = 0; write("Wiz throwing is not possible\n"); return 1; }
}
