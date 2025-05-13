int full;

short() {
   if (full)
      return "A small vial containing a thick liquid";
   else
      return "A small vial";
}

long() {
   if (full)
      write ("This is a small vial containing a thick liquid.\n");
   else
      write ("This is a small vial.\n");
}

reset(arg) {
   if (!arg)
     full = 1;
}

init() {
   add_action("drink"); add_verb("drink");
}

id(str) {
   return str == "liquid" || str == "vial";
}

drink(str) {
   if (!id(str))
      return;

   if (full) {
      write ("You open the vial and drink the thick liquid.\n");
      write ("It has a strange bitter taste, and as you drink it\n");
      write ("your body begins to rejuvenate.  You are completely\n");
      write ("healed.\n");
      say (call_other(this_player(), "query_name") + " drinks a potion.\n",
	   this_player());
      call_other(this_player(), "heal_self", 1000);
      full = 0;
   }
   else
      write ("The vial is empty.\n");
   return 1;
}
      
get() {
   return 1;
}

query_value() {
   if (full)
      return 2500;
   else
      return 25;
}

query_weight() {
   return 0;
}
