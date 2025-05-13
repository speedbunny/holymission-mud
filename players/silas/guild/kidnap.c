/* Last Edit 24.3.92 by Wolfi */

object master;

id(str) { return str == "kidnap_slave";} 

init() {
  if (!living(environment())) {
    destruct_me();
    return;
  }

  call_out("destruct_me",200);
  enable_commands();
}
catch_tell(str) {
  if (!master) return;
  if (!living(environment())) {
    destruct_me();
    return; 
  }
 
  if (environment(environment()) != environment(master)) { 
     write("You can't escape from your kidnapper.\n");
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

destruct_me() { destruct(this_object()); }
