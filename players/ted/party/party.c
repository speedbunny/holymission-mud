string title;
int total_exp;

id(str) { return str == "party" || str == lower_case(title); }

short() {
   if (!first_inventory(this_object())) {
      call_out("destroy", 1);
      return 0;
     }
   return "party of " + title;
}

long() {
   object ob, player;
   if (!first_inventory(this_object())) {
      call_out("destroy", 1);
      return 0;
     }
   write("Party of " + title + ".\n");
   write("  Current members are:\n");
   ob = first_inventory(this_object());
   while(ob) {
      player = call_other(ob, "query_player");
      if (player)
         write("    " + call_other(player, "query_name") + "\n");
      else
         call_other(ob, "init");
      ob = next_inventory(ob);
     }
}

set_player(player) {
   object sign;
   sign = clone_object("players/ted/party/party_sign");
   call_other(sign, "set_player", player);
   move_object(sign, this_object());
   return 1;
}

set_title(str) { title = str; }

query_title() { return title; }

drop_player(player) {
   object sign, ob, found;
   string name;
   sign = first_inventory(this_object());
   found = 0;
   name = call_other(player, "query_name");
   while (sign) {
      ob = call_other(sign, "query_player");
      if (ob == player) found = sign;
      else if (!ob) call_other(sign, "init");
      else tell_object(ob, name + " is no longer in the party.\n");
      sign = next_inventory(sign);
     }
   if (found) destruct(found);
   if (count_players() == 1) {
      sign = first_inventory(this_object());
      ob = call_other(sign, "query_player");
      tell_object(ob, "You are the only player left in the party, party "
         + "dissolved.\n");
      destruct(sign);
      found = present("party", ob);
      if (found) destruct(found);
      call_out("destroy", 1);
     }
   return 1;
}

count_players() {
   object sign;
   int k;
   sign = first_inventory(this_object());
   k = 0;
   while (sign) {
      k += 1;
      sign = next_inventory(sign);
     }
   return k;
}

destroy() {
   destruct(this_object());
}

divvy() {
   object sign;
   int n, exp, lev;
   n = count_levels();
   exp = count_exp();
   sign = first_inventory(this_object());
   while (sign) {
      lev = call_other(sign, "query_level");
      if(n!=0)
        call_other(sign, "add_exp", (exp * lev)/n);
        total_exp=total_exp + exp;
      sign = next_inventory(sign);
     }
   return 1;
}

count_levels() {
   object sign;
   int k;
   sign = first_inventory(this_object());
   while (sign) {
      k += call_other(sign, "query_level");
      sign = next_inventory(sign);
     }
   return k;
}

count_exp() {
   object sign;
   int k;
   sign = first_inventory(this_object());
   while (sign) {
      k += call_other(sign, "query_exp");
      sign = next_inventory(sign);
     }
   return k;
}

reset(arg) {
   if (!arg) title = "adventurers";
   return;
}




