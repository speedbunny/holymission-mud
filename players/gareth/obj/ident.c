#include "/players/gareth/define.h"
query_value() { return 375; }
query_weight() { return 1; }
get() { return 1; }
id(str) { return str == "scroll" || str == "identify" || 
                 str == "vellum scroll"; }
short() { return "a crumbling vellum scroll"; }

long() { 
   write("This is an old, crumbling scroll.  Across the top \n");
   write("you see 'Identify'.\n");
   return 1;
}

init() {
   add_action("identify"); add_verb("identify");
   add_action("read"); add_verb("read");
}

read(arg) {
   if (!id(arg))
      return 0;
   long();
   return 1;
}

identify(arg) {
   object obj, memb;
   int ac, wc, weight;
   string info;

   if (!arg) return 0;

   obj = present(arg, TP);
   if (!obj) {
      if (present(arg, environment(TP))) {
         write("You must be carrying the "+arg+" to identify it.\n");
         return 1;
      }
      write("You aren't carrying a " + arg + ".\n");
      return 1;
   }
   
   if (call_other(TP, "query_spell_points") < 10) {
      write("You can't quite comprehend the words on the scroll.\n");
      return 1;
   }
   ac = call_other(obj, "armor_class");
   wc = call_other(obj, "weapon_class");
   weight = call_other(obj, "query_weight");
   if (ac > 0) {
      write("This appears to be some type of armor.\n");
      if (ac > 5)
         write("This is some of the best armor you've ever seen.\n");
      else if (ac > 4) 
         write("This provides you superb protection.\n");
      else if (ac > 3)
         write("This provides you excellent protection.\n");
      else if (ac > 2)
         write("This provides you good protection.\n");
      else if (ac > 1)
         write("This provides you average protection.\n");
      else write("This provides little protection.\n"); 
   } 
   else if (wc > 0) { 
      write("This appears to be some type of weapon.\n");
      if (wc > 20)
         write("This is a superb weapon.\n");
      else if (wc > 15)
         write("This is an excellent weapon.\n");
      else if (wc > 10)
         write("This is a good weapon.\n");
      else if (wc > 5)
         write("This is an average weapon.\n");
      else 
         write("This is a below average weapon.\n"); 
   }
   else write("You can't tell what type of object this is.\n");

   if (weight>10)
      write("You probably can't carry much else while carrying this.\n");
   else if (weight>7)
      write("This object is pretty heavy.\n");
   else if (weight>5)
      write("This object is moderately heavy.\n");
   else if (weight>3)
      write("This object is pretty light.\n");
   else if (weight>1)
      write("This object is really light.\n");
   else if (weight == 1)
      write("This object weights almost nothing.\n");
   else 
      write("This object weights nothing.\n");

   info = obj->query_info();
   if (info)
      write(info);
   if (call_other(TP, "query_level") < 30)
      call_other(TP, "add_spell_points", -10);
   write("The scroll turns to dust.\n");
   destruct(TO);
   call_other(TO, "recalc_carry");
   log_file("IDENTIFY", call_other(TP, "query_name") + 
                      " identified "+arg+"\n");
   return 1;
}
