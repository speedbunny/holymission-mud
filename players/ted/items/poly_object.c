string oldtitle, newtitle, oldguild, newguild;
int dest_time, level;

start(ob, new, test) {
 move_object(this_object(), ob);
 newtitle = new;
 oldtitle = call_other(ob, "query_title");
 level = call_other(ob, "query_level");
 tell_object(ob, "You find you must drop everything!\n");
 call_other(ob, "drop_all");
 if(test==1 || test==4 || test==9 || test==13 || test==14) {
	call_other(ob, "set_wc", 25);
 tell_object(ob, "You feel your natural attack is very deadly!\n");
  } else if(test==1 || test==15 || test==18 || test==17 || test==20) {
	call_other(ob, "set_wc", 20);
 tell_object(ob, "You feel your natural attack is deadly!\n");
  } else {
	call_other(ob, "set_wc", 15);
 tell_object(ob, "You feel your natural attack is quite good!\n");
  }
 call_other(ob, "set_title", newtitle);
 dest_time = random(1000) + 800;
 call_out("destroy", dest_time);
}

id(str) {
 return str == "poly_object";
}

drop() { return 1; }

init() {
 add_action("do_quit"); add_verb("quit");
 add_action("do_wield"); add_verb("wield");
}

do_quit() {
 write("Ok, changing you back......Now you can quite.\n");
 call_out("destroy", 0);
 call_other(this_player(), "quit");
 return 1;
}

do_wield(str) {
 write("You feel that your natural attack is better than that puny "+str+"\n");
 return 1;
}

destroy() {
 object ob;
 ob = environment(this_object());
 call_other(ob, "set_title", oldtitle);
 tell_object(ob, "You turn back into "+oldtitle+"!\n");
 tell_object(ob, "You find you must drop everything!\n");
 call_other(ob, "drop_all");
 call_other(ob, "set_wc", 3);
 destruct(this_object());
 return 1;
}
