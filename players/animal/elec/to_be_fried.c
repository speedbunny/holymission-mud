query_auto_load() {
  return "players/animal/elec/to_be_fried:";
}
 
get() { return 1; }
 
drop() { return 1; }
 
id(str) {
  return str == "to_be_fried";
}
 
query_info() {
  return "will_die";
}
 
init() {
  start_execution();
  add_action("filter", "", 1);
}
 
filter(str) {
  string verb;
  verb = query_verb();
  if(verb=="quit") {
    write("MUHAHAHAHAHA! You cannot leave now!\n");
    return 1;
  }
  if(this_player()->query_level() > 19) return 0;
  if(verb=="say") return 0;
  if(verb=="shout" ||
     verb=="look"  ||
     verb=="thank" ||
     verb=="sigh") return 0;
  if(verb=="who" || verb=="bomb") return 0;
  if(verb=="push" || verb=="pull" || verb=="read" || verb=="wiz") return 0;
  if(verb=="destruct") return 0;
  if(verb=="cry" || verb=="sniff" || verb=="sigh" || verb=="spit") return 0;
  write("You are not allowed to do that!\n");
  return 1;
}
 
start_execution() {
  object ned, my_host;
  my_host = environment(this_object());
  if(my_host) {
    if(living(my_host)) {
      if(my_host->query_ghost()==1) {
        destruct(this_object());
        return;
      }
    }
    else 
      return;
  }
  else 
    return;
  if(file_name(environment(my_host))!="players/animal/elec/chair_room") 
    move_object(my_host, "/players/animal/elec/chair_room");
}
extra_look() {
  return "strapped to the electric chair";
}
