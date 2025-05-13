/*Code by Arthur for Holy Mission - 140.78.3.1 Date Done 11.4.94 */
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"

object plyr;

reset (arg) {
if (arg) return;

   set_short(0);
   set_alias("asoul");
   set_long("Arthur's very own extended soul.");
   set_value(0);
   set_weight(0);
}
init() {
     add_action("abaer", "abaer");
     add_action("amoo", "amoo");
     add_action("abark", "abark");
     add_action("apet", "apet");
     add_action("wiggle", "wiggle");
     add_action("help", "help");
     ::init();

}
abaer(str) {
    if(!str) {
        write("who do you want to give a baer hug 2?\n");
        return 1;}
  plyr=present(lower_case(str), environment(TP()));
    if(!plyr) {
        write("That player is not here.\n");
        return 1;}
    write("You squeeze "+capitalize(str)+"\n"+plyr->query_name()+" screams in pain.\n");
    say(TP()->query_name()+" gives "+plyr->query_name()+".a giant baer hug.\n"+plyr->query_name()+" screams in pain.\n", plyr);
    tell_object(plyr,TP()->query_name()+" gives you a giant baer hug.\nYou feel pain shooting up your spine.\n");
    return 1;
  }

apet(str) {
     if(!str) {
        write("who do you want to moo at?\n");
        return 1;}
   plyr=present(lower_case(str), environment(TP()));
    if(!plyr) {
       write("That player is not here.\n");
       return 1;}
    write("You pet "+capitalize(str)+".\n"+plyr->query_name()+" purrs happily.\n");
   say(TP()->query_name()+" pets "+plyr->query_name()+".\n"+plyr->query_name()+" purrs happily.\n", plyr);
   tell_object(plyr,TP()->query_name()+" pets you.\nYou purr happily.\n");
 return 1;
}

amoo() {
     write("You moo loudly.\n");
      say(TP()->query_name()+" Moo's very loudly.\n");
     return 1;
}
wiggle() {
    write("You wiggle your behind.\n");
   say(TP()->query_name()+" wiggles.\n");
   return 1;
}

abark() {
     write("You bark wildly.\n");
     say(TP()->query_name()+" barks wildly.\nYou jump from his loud barking sound.\n");
      return 1;
}
help(str) {
     if(!str) return 0;
     if(str == "asoul") {
          write("The commands currently avaliable in it.\n"+
          "abark\namoo\napet <plyr>\n");
          return 1;
          }
        return 0;
       }
drop() {return 1;}

query_auto_load() { return "/players/arthur/asoul.c:"; }

