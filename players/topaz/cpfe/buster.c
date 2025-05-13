/*coded for ishikawa by haplo*/
/* coded by tatsuo for kitiana*/
inherit "obj/armour";

#include "/players/gambit/defs2.h"
#define TP this_player()
#define TPN TP->query_name()
#define TPPN TP-query_possesive()


reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("Buster the Bird");
    set_alias("buster");

    set_type("bird");

}
init() {
    ::init();
	add_action("_say","say");
    add_action("show", "display");
     add_action("_pet","pet");
    add_action("show", "show");
}

show(str) {
    if(!id(str)) return;
	write("You proudly show off Buster to your friends.\n");
	say(TPN+" shows you Buster the Bird, her very bestest friend.\n");
    return 1;
}

change(str) {
    if(str !="title") return;
    title_set();
    write("You have fixed your title.\n");
    return 1;
}

title_set() {
    object x;
    x=environment(this_object());
    if(!x) return;
    x->set_title("loves Buster very much");
    x->set_pretitle("none");
    return 1;
}

query_weight() { return 0; }

query_auto_load() { return "players/haplo/ishikawa/obj/star:";}


long() {
    write(BS("It is a bright golden star with a brilliant aura circling it. "+
	"To show off your title, type 'change title', to be proud of yourself "+
        "and display your star to everyone, type 'show star'."));
}

remove() { 
    write(" You decide to save it to show your grandchildren instead.\n"); 
    return 1;
}

dest() { destruct(this_object()); }

drop() { 
    if (query_verb()== "sell"){
	write ("You decide not to sell it and save it for your grandchildren.\n");
	return 1;
    }
    if(query_verb() == "give"){
	write("You change your mind and decide to say it for you grandchildren.\n");
	return 1;
    }

    write("It is to pretty to drop.\n");
    return 1;
}
_say(str){
  say("Kitiana says: "+str+".\n");
  say("Buster repeats: cawl, "+str+", cawl.\n");
  write("You say: "+str+".\n");
  write("Buster repeats: cawl, "+str+", cawl.\n");
  return 1;
}
_pet(str){
  if(str=="buster"){
   write("Buster coos softly as you pet him.\n");
   say("Buster the bird coos softly as Kitiana pets him.\n");
    return 1;
}
else return 0;
}
