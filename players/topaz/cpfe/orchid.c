inherit "obj/treasure";
#include "/players/exos/defs.h"
string scent,note;

reset(arg) {
   if(arg) return;
   set_id("flower");
   set_name("orchid");
   set_alias("flower");
   set_short("A single blue orchid");
   set_long("It is a beautiful blue orchid!\n"+
            "And it is magical!  Just type 'fhelp'.\n");
   set_weight(1);
   set_value(10);
   scent="a lovely flower grown on the top of Ishikawa's largest mountain";
   note="from your secret admirer!";
}

init() {
   AA("flow_help","fhelp");
   AA("send_flow","fsend");
   AA("flow_desc","fdesc");
   AA("flow_from","ffrom");
   AA("smell_flow","smell");
   AA("flow_scent","fsmell");
   AA("read_note","read");
}

flow_desc(str) {
   if(!str) {
      write("Use 'fdesc <description>' to change the orchid.\n");
      return 1;
   }
   TO->set_short("A single "+str+" orchid");
   TO->set_long("It is a beautiful "+str+" orchid!\n"+
                "And it is magical!  Just type 'fhelp'.\n");
   write("The orchid magically changes into "+str+"!\n");
   return 1;
}

send_flow(str) {
   object who;

   if(!str) {
      write("Who do you want to send the orchid to?\n");
      return 1;
   }
   who=find_player(str);
   if(who) {
      TELL(who,"Someone just sent you an Ishikawan Orchid!\n");
      transfer(TO,who);
      write("You send the orchid to "+who->QNAME+".\n");
   }
   else write("No such player.\n");
   return 1;
}

smell_flow(str) {
   if(str!="orchid" && str!="flower") return 0;
   say(TPN+" smells an orchid.\n");
   write("The orchid smells like "+scent+".\n");
   return 1;
}


read_note(str) {
   if(str!="orchid" && str!="flower") return 0;
   say(TPN+" reads a note tied to an orchid.\n");
   write("The note reads: "+note+"\n");
   return 1;
}

flow_from(str) {
   if(!str) str="From your secret admirer.";
   note=str;
   write("You change the note on the orchid.\n");
   say(TPN+" writes a note and ties it to an orchid.\n");
   return 1;
}

flow_scent(str) {
   if(!str) str="a lovely orchid, freshly picked just for you";
   scent=str;
   write("The orchid magically adjusts its scent!\n");
   return 1;
}

flow_help() {
   write("Orchid help:\n"+
         "   fhelp   -   This message\n"+
         "   fdesc   -   Change the color of the orchid\n"+
         "   fsend   -   Send orchid to another player\n"+
         "   ffrom   -   Tie a note to the orchid\n"+
         "   fsmell  -   Change the scent of the orchid\n"+
         "   read    -   Read the note\n"+
         "   smell   -   Smell the orchid\n"+
         "\nAny comments can be mailed to Exos.\n");
   return 1;
}
