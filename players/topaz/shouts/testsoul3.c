inherit "obj/armour";

#include "/players/topaz/defs.h"

query_auto_load();
query_ninja_wear() { return 1;}
query_summoner_wear() { return 1; }
query_mage_wear() { return 1; }
query_monk_wear() { return 1; }


get() {
    return(1);
}
drop() {
    write("To get rid of the gender shouter type:\n" +
          "toss shouter\n");
    return(1);
}
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_type("shoutsoul");
    set_ac(0);
    set_weight(0);
    set_name("shouter");
    set_id("shouter");
    set_alias("gender shouter");
    set_short("A gender shouter");
    set_long("A gender shouter.\n" +
            "To shout to all of your gender, type:\n" +
             "genshout <message>\n");
}

init() {
    ::init();

    add_action("_gendershout","genshout");
    add_action("_toss","toss");
}

_gendershout( str ) {
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
        tell_object(u[i],TP->query_name() + " shouts something to all " + TP->query_gender_string() + "s.\n");
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
