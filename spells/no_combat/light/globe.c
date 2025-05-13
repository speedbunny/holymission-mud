/* a generic undropable thing */
#include "/obj/thing.c"

int light_level;

drop() {
  write("As you drop your ball of light it disappears.\n");
  destruct(this_object());
  return 1;
} 

set_llevel(arg) {
  light_level=arg;
}

light(arg) {
  if(arg) return set_light(light_level);
  else return set_light(-light_level);
}

set_time(tim) {
  call_out("end_light",tim);
}

end_light() {
  write("Your globe of light disappears.\n");
  say(environment()->query_name()+"'s globe of light disappears.\n");
  if(light()<=0) tell_room(environment(environment()),"It turns dark.\n");
  destruct(this_object());
  return 1;
}
