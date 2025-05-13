inherit "obj/treasure";

#include "/players/topaz/defs.h"

query_auto_load() {
    return "players/topaz/shouts/players:";
}

get() {
    return(1);
}
drop() {
    write("To get rid of the player shouter type:\n" +
          "toss shouter\n");
    return(1);
}
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_weight(0);
    set_name("shouter");
    set_id("shouter");
    set_alias("player shouter");
    set_short("A player shouter");
    set_long("A player shouter.\n" +
            "To shout a message with each player's name in it, type:\n" +
             "playershout <message> PLAYERS <message>\n");
}

init() {
    ::init();

    add_action("_playershout","playshout");
    add_action("_toss","toss");
}

/* start again here */
_playershout( str ) {
object *u;
int i;

if(!str) {
    write("Shout what to all " + TP->query_gender_string()+ "s?\n");
    return (1);
}
if(!(TP->query_wizard()) && TP->query_sp() < 20) {
    write("You don't have enough spellpoints.\n");
}
else {
    write("You shout to all " + TP->query_gender_string() + "s:\n    " + str + "\n" );

    log_file("PLAYSHOUTS", TP->query_real_name()+": "+TP->query_name() + " shouts to all " + TP->query_gender_string() + "s:\n    " + str + "\n\n");
    u = users();

    for(i=0;i<sizeof(u);i++) {
      if(u[i]->query_gender_string() == TP->query_gender_string() && u[i] != TP) {
        tell_object(u[i], TP->query_name() +
          " shouts to all " + TP->query_gender_string() + "s:\n    " + str + "\n");
      }
      else if(TP !=u[i]) {
        tell_object(u[i],TP->query_name() + " shouts something in that unintelligible way that all " + TP->query_gender_string() + "s can shout.\n");
      }
    }
    if(!TP->query_wizard()) {
      TP->restore_spell_points(-20);
    }
    }
    return(1);
}

_toss(str) {
if(!str) {
    write("Make sure you type \"toss shouter\"\n");
    return(1);
}
if(str!="shouter") {
    write("Make sure you type \"toss shouter\"\n");
    return(1);
}
if(str=="shouter") {
    destruct(this_object());
    write("You toss your gender shouter up in the air and it floats away.\n");
    return(1);
}
}
