object player;
int experience;

id(str) { return str == "sign"; }

short() {
   string name;
   if (!player) return 0;
   name = call_other(player, "query_name");
   return "Sign for " + name;
}

set_player(ob) {
   player = ob;
   experience = call_other(player, "query_exp");
}

query_exp() {
   if (!player) return 0;
   return call_other(player, "query_exp") - experience;
}

add_exp(n) {
   int i;
   if (!player) return 0;
   i = n + experience - call_other(player, "query_exp");
   call_other(player, "add_exp", i);
   experience = call_other(player, "query_exp");
   if (i) tell_object(player, "Experience has been divided.\n");
   return 1;
}

query_level() {
   if (!player) return 0;
   return call_other(player, "query_level");
}

query_player() { return player; }

init() {
   if(!player) call_out("destroy", 1);
}

destroy() {
   destruct(this_object());
}




