object party;

id(str) { return str == "party" || str == "party symbol" || str == "symbol"; }

short() {
   if (!party) return 0;
   return "Symbol of " + call_other(party, "query_title");
}

long() {
   object ob, player;
   if (!party) return 1;
   write("This is a symbol representing the party of " +
      call_other(party, "query_title") + ".\n");
   write("Current members are:\n");
   ob = first_inventory(party);
   while(ob) {
      player = call_other(ob, "query_player");
      if (player)
         write("  " + call_other(player, "query_name") + "\n");
      else
         call_other(ob, "init");
      ob = next_inventory(ob);
     }
}

set_party(ob) { party = ob; }

init() {
   add_action("divvy"); add_verb("divvy");
}

divvy() {
   if (!party) return 0;
   return call_other(party, "divvy");
}

drop(n) {
   object player;
   if (!party || !first_inventory(party)) {
      call_out("destroy", 1);
      return 1;
     }
/* If n = 1, we are being called from transfer_all_to(), so we assume
   that he has died, so we don't want to divvy() */
   player = environment(this_object());
   tell_object(player, "You are no longer in the party.\n");
   if (!n) divvy();
   call_other(party, "drop_player", player);
   call_out("destroy", 1);
   return 1;
}

destroy() {
   destruct(this_object());
}

/* Herp: this is needed for some guilds, where it's able that a specific spell
	 attacks all pc's and npc's in a room. 
         The members of a party must not be attacked then. */
 
query_party() { return party; }

