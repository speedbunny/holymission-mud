int charges;

id(str) { return (str == "ball" || str == "crystal" || str == "crystal ball"); }

long(str) {
	write("You see a dark blue crystal ball, maybe it has some\n");
	write("special powers. The ball feels in your hand like you\n");
	write("should gaze, or peer into it.\n");
	return 1;
}

short() { return "A blue crystal ball"; }

init() {
  add_action("view", "gaze");
  add_action("view", "peer");
}

drop() { return 0; }

get() { return 1; }

query_name() { return "Crystal ball"; }

query_value() { return 100 * charges; }

query_weight() { return 0; }

query_info() {
	write("This is a crystal ball, used to locate people.\n");
	write("type 'peer <person>' or type 'gaze <person>'.\n");
	return 1;
}

view(arg) {
 object who, where, ob, looker;
 int i;
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
 move_object(looker, where);
 looker->mylook(0);
 destruct(looker);
 if(!charges) {
    write("The ball goes dull and crumbles to little crystalline pieces.\n");
    destruct(this_object());
    return 1;
 }
 charges--;
 return 1;
}

reset(arg) { if(!arg) charges=20; }
