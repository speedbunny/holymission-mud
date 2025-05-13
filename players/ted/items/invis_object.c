int start_time;

query_auto_load() {
 return "players/ted/items/invis_object: "+start_time;
}

start(ob) {
 move_object(this_object(),ob);
 start_time = time();
 tell_object(ob, "Your body takes on a strange transparancy.....\n");
 call_other(ob, "set_player_invis", 100);
}

id(str) {
 return str == "invis_object";
}

long() {
 write("You are invisible!\n");
 return 1;
}

short() {
 return;
}

drop() { return 1; }

init() {
 if(time() > start_time+3000) {
 add_action("do_score"); add_verb("score");
 }
}

init_arg(str) {
 sscanf(str, "%d", start_time);
}

do_score() {
 write("You fade back into view......\n");
 call_other(this_player(),"set_player_invis", 0);
 call_other(this_player(),"update", 5);
 destruct(this_object());
 return 1;
}
