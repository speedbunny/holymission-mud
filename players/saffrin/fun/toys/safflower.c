inherit "obj/treasure";
#include "/players/saffrin/defs.h"
string scent,note;

reset(arg) {
   if(arg) return;
   set_id("safflower");
   set_name("safflower");
   set_alias("flower");
   set_short("A yellow safflower");
   set_long("It is a beautiful yellow safflower!\n"+
            "And it is magical!  Just type 'shelp'.\n");
   set_weight(1);
   set_value(10);
   scent="the wonderful scent of Saffrin's own safflowers.\n";
   note="from someone special.";
}

init() {
   AA("flow_help","shelp");
   AA("send_flow","ssend");
   AA("flow_from","sfrom");
   AA("smell_flow","smell");
   AA("flow_scent","ssmell");
   AA("read_note","read");
}

send_flow(str) {
   object who;

   if(!str) {
      write("Who do you want to send the safflower to?\n");
      return 1;
   }
   who=find_player(str);
   if(who) {
      TELL(who,"Someone just sent you safflower!\n");
      transfer(TO,who);
      write("You send the safflower to "+who->QNAME+".\n");
   }
   else write("No such player.\n");
   return 1;
}

smell_flow(str) {
   if(str!="safflower" && str!="flower") return 0;
   say(CQN+" smells an safflower.\n");
   write("The safflower smells like "+scent+".\n");
   return 1;
}


read_note(str) {
   if(str!="safflower" && str!="flower") return 0;
   say(CQN+" reads a note tied to an safflower.\n");
   write("The note reads: "+note+"\n");
   return 1;
}

flow_from(str) {
   if(!str) str="From someone special.";
   note=str;
   write("You change the note on the safflower.\n");
   say(CQN+" writes a note and ties it to an safflower.\n");
   return 1;
}

flow_scent(str) {
   if(!str) str="a lovely safflower, freshly picked just for you";
   scent=str;
   write("The safflower magically adjusts its scent!\n");
   return 1;
}

flow_help() {
   write("Safflower help:\n"+
         "   shelp   -   This message\n"+
         "   ssend   -   Send safflower to another player\n"+
         "   sfrom   -   Tie a note to the safflower\n"+
         "   ssmell  -   Change the scent of the safflower\n"+
         "   read    -   Read the note\n"+
         "   smell   -   Smell the safflower\n"+
         "\nEnjoy!\n");
   return 1;
}
