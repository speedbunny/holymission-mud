
query_value() { return 500; }
query_weight() { return 1; }

get() { return 1; }

id(str) { return str == "scroll" || str == "gold leaf scroll" ||
                 str == "enchant"; }
short() { return "a beautiful, gold leaf scroll"; }

long() { 
   write("This is a beautiful, gold leaf scroll.  Across the top \n");
   write("you see 'Enchant'.\n");
   return 1;
}

init() {
   add_action("enchant"); add_verb("enchant");
   add_action("read"); add_verb("read");
}

read(arg) {
   if (!id(arg))
      return 0;
   long();
   return 1;
}

enchant(arg) {
   object obj, memb;
   int ac, wc, weight;
   int chance;
   int val;


   if (!arg) return 0;

   obj = present(arg, this_player());
   if (!obj) {
      if (present(arg, environment(this_player()))) {
         write("You must be carrying the "+arg+" to enchant it.\n");
         return 1;
      }
      write("You aren't carrying a " + arg + ".\n");
      return 1;
   }
   
   if (call_other(this_player(), "query_spell_points") < 20) {
      write("You can't quite comprehend the words on the scroll.\n");
      return 1;
   }
   ac = call_other(obj, "armor_class");
   wc = call_other(obj, "weapon_class");
   weight = call_other(obj, "query_weight");
   write("You read the scroll.  The "+arg+" begins glowing a deep blue.\n");
   say(call_other(this_player(), "query_name")+
                  " reads the gold leaf scroll.\n");
   if (ac > 0) {
      chance = 3*ac*(ac+1);
      
      if (chance > 95) chance = 95;
      if (chance > random(100)) {
         if (random(100) < 10) {
            write("The "+arg+" glows brighter, turning a blinding white.\n");
            write("The "+arg+" explodes!\n");
            say(call_other(this_player(), "query_name")+
               "'s "+arg+" explodes!\n");
            call_other(this_player(), "stop_wearing", 
               call_other(obj, "query_name"));
            destruct(obj);
            call_other(this_player(), "hit_player", 40);
         }
         else {
            val = call_other(obj, "query_value");
            val -= 400;
            if (val < 0) val = 0;
            write("The "+arg+" glow begins to fade, turning black.\n");
            say(call_other(this_player(), "query_name")+
               "'s "+arg+" glows a deep black.\n");
            call_other(obj, "set_ac", ac-1);
            call_other(obj, "set_value", val);
         } 
      } 
      else {
         val = call_other(obj, "query_value");
         val += 400;
         write("The "+arg+" glows brighter, turning a brilliant blue.\n");
         write("When the light fades, the "+arg+" remains.\n");
         say(call_other(this_player(), "query_name")
             +"'s "+arg+" takes on a better appearance.\n");
         call_other(obj, "set_ac", ac+1);
         call_other(obj, "set_value", val);
      }
      call_other(this_player(), "recalc_ac");
   } 
   else if (wc > 0) { 
      chance = (wc*(wc+1)*9)/40;
      if (chance > 95) chance = 95;
      if (chance > random(100)) {
         write("The "+arg+" glows brighter, turning a blinding white.\n");
         write("The "+arg+" explodes!\n");
         say(call_other(this_player(), "query_name")+
            "'s "+arg+" explodes!\n");
         destruct(obj);
         call_other(this_player(), "hit_player", 40);
      }
      else {
         val = call_other(obj, "query_value");
         write("The "+arg+" glows brighter, turning a brilliant blue.\n");
         write("When the light fades, the "+arg+" remains.\n");
         say(call_other(this_player(), "query_name")
             +"'s "+arg+" takes on a better appearance.\n");
         call_other(obj, "set_class", wc+4);
         call_other(obj, "set_value", val+800);
      }
      call_other(this_player(), "recalc_wc"); 
   }
   else write("Nothing happens.\n");

   if (call_other(this_player(), "query_level") < 20)
      call_other(this_player(), "add_spell_points", -20);
   write("The scroll turns to dust.\n");
   destruct(this_object());
   call_other(this_player(), "recalc_carry");
   log_file("ENCHANT", call_other(this_player(), "query_name") + 
                       " enchanted "+arg+"\n");
   return 1;
} 
