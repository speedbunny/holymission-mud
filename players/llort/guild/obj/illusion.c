inherit "obj/thing";

int dest_time;

start(tim) {
  dest_time=tim;
  call_out("dest",dest_time);
}

dest() {
  tell_room(environment(this_object()),short()+" vanishes.\n");
  destruct(this_object());
  return 1;
}

query_name() { return short(); }

query_destr() { return dest_time; }
 
get() { return 0; } 
