int _givit(string arg){
   object target;
   if(this_player()->query_real_name() != "bobo") return 0;
   target = find_player(arg);
   move_object(clone_object("/players/bobo/clan/amulet"), target);
   write("Given.\n");
   return 1;
   }
