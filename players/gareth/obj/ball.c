#include "/players/gareth/define.h"

int charges;

id(str) { return (str == "ball" || str == "crystal" || str == "crystal ball"); }

long(str) {
	write("This is a round crystal ball. It is slightly cloudy.\n");
	return 1;
}

short() { return "A Crystal Ball"; }

init() {
 add_action("view"); add_verb("peer");
 add_action("view"); add_verb("find");
}

drop() { return 0; }

get() { return 1; }

query_name() { return "Crystal Ball"; }
query_value() { return 325; }

query_weight() { return 2; }

query_info() {
	write("This is a crystal ball, used to locate people.\n");
	write("type 'peer <person>' or type 'find <person>'.\n");
	return 1;
}

view(arg) {
 object who, where, ob, looker;
 int i;
 if(TP->query_spell_points()<(30+TP->query_level()))
	return write("You are not strong enough to do that.\n");
 who=find_player(arg);
 if (!arg) {
    write("What are you looking for ?\n");
 return 1;
 }
 if (!who) {
    write("Couldn't find "+arg+"\n");
  return 1;
 }
 where=environment(who);
 write("You peer into the crystal ball, trying to find "+arg+"\n");
 write("You see:\n\n");
 if (who->query_immortal()) {
    write("You can't stand looking at the power surrounding "+arg+".\n");
    write("You lose your consciousness ...\n");
    return 1;
 } 
 looker=clone_object("sys/mylook");
 MO(looker, where);
 looker->mylook(0);
 destruct(looker);
 charges--;
 return 1;
 }

reset(arg) { if(!arg) charges=10; }
