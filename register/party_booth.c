int in_progress;

id(str) { return str == "list"; }

short() { return "Party Booth"; }

long(str) {
   if (id(str)) return read(str);
   write("This is the Party Booth.\n");
/*   write("An adventuring party can come here, and when everyone is in,\n");
   write("someone types the command <register>.  The party will then\n");
   write("share experience for any monsters they kill. Higher level\n");
   write("party members, will recieve a larger portion than lower level\n");
   write("party members, on the premise that they will contribute more.\n");
   write("Once experience has been gained, any party member can type the\n");
   write("command <divvy> to divide the experience among the party members.\n");
   write("To leave the party, just drop your party symbol. (Note: only\n");
   write("experience will be divided, not alignment changes.\n");
   write("There is a list tacked to the wall of current parties.\n");
*/
   write("Everything has changed here, it seems that there is a new system\n");
   write("to build parties now. (try 'help group' for info!)\n");
   write("\n");
   write("    The only exit is down.\n");
   return 1;
}

init() {
/*   add_action("register"); add_verb("register");
   add_action("read"); add_verb("read");
   add_action("get_followme"); add_verb("followme");
*/
   add_action("west"); add_verb("down");
}

read(str) {
   object store, ob;
   if (!id(str)) {
      /* 13 oct 92, couldnt read other things, Galadriel */
      return 0;
     }
   store = find_object("register/party_store");
   if (store) ob = first_inventory(store);
   while (ob && !ob->id("party"))
      ob = next_inventory(ob);
   if (!store || !ob) {
      write("There are no parties at the moment.\n");
      return 1;
     }
   while(ob) {
      if (ob->id("party")) ob->long();
      ob = next_inventory(ob);
     }
   return 1;
}

west() {
   this_player()->move_player("down#room/pub2");
   return 1;
}

register() {
   string name;
   if (this_player()->query_immortal()) {
      write("Wizards cannot register parties, only throw them!\n");
      return 1;
   }
   if (in_progress) {
      write("Someone is already trying to register this party.\n");
      return 1;
     }
   name = this_player()->query_name();
   say(name + " tries to register the party.\n");
   if (!check_all_here()) {
      tell_room(this_object(),
         "Registration failed. Someone already belongs to a party.\n");
      return 1;
     }
   if (count_players() == 1) {
      write("Not enough players to form a party. Must have at least 2.\n");
      return 1;
     }
   write("What do you want to call this party? (adventurers) ");
   in_progress = 1;
   input_to("register_party");
   return 1;
}

count_players() {
   object ob;
   int k;
   ob = first_inventory(this_object());
   k = 0;
   while (ob) {
      if (living(ob) && ob->query_level() < 30) k += 1;
      ob = next_inventory(ob);
     }
   return k;
}

register_party(str) {
   object ob, symbol, party;
   ob = first_inventory(this_object());
   while (ob && !living(ob)) ob = next_inventory(ob);
   party = clone_object("register/party");
   if (str && str != "") party->set_title(str);
   move_object(party, "register/party_store");
   while (ob) {
      if (living(ob) && !ob->query_immortal()) {
         party->set_player(ob);
         symbol = clone_object("register/party_symbol");
         symbol->set_party(party);
         move_object(symbol, ob);
        }
      ob = next_inventory(ob);
     }
   tell_room(this_object(), "The party has been registered.\n");
   in_progress = 0;
   return 1;
}

check_all_here() {
   object ob;
   ob = first_inventory(this_object());
   while (ob) {
      if (present("party", ob)) return 0;
      ob = next_inventory(ob);
     }
   return 1;
}

reset(arg) {
   if (!arg) set_light(1);
   return;
}


get_followme() {
   write("Followme's are out of service for the moment.\n");
   return 1;
   move_object(clone_object("open/followme"),this_player());
   write("Ok.\n");
   return 1;
}




