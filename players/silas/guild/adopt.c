/* Last Edit 24.3.92 by Wolfi */

object master;

id(str) { return str == "adopt_slave";} 

long() {
   write("Your master is "+ master->query_name() + "\n");
   write("Type :stop adoption: to get free from your leader.\n");
   return 1;
}

init() {
  add_action("long","master");
  add_action("stop_adoption","stop");
  enable_commands();
}

stop_adoption(str) {
   if (!str || str !="adoption") return 0;
   
   tell_object(environment(),"You get free from your leader.\n");
   tell_object(master,"You're slave is gone.\n");

   destruct(this_object());
   call_other(master,"erase_adopted");  
   master=0; 
   return 1; 
}
catch_tell(str) {
  if (!master) return;

  if (environment(environment()) != environment(master)) { 
     write("You are not allowed to leave your master.\n");
     move_object(environment(),environment(master));
     tell_object(master,environment()->query_name() +" arrives.\n");
     tell_object(master,environment()->query_name()+" tried to escape but failed.\n");
  }
}

query_master(str) {
    return master = str;
}

query_weight() { return 0;} 

query_value() { return 0; }



 
