query_auto_load() {
  return "players/animal/elec/gag:";
}
 
drop() { return 1; }
 
get() { return 1; }
 
id(str) {
  return str == "this_person_is_gagged";
}
 
query_info() {
  return "this_person_is_gagged";
}
 
init() {
  add_action("forcer", "", 1);
}
 
forcer(str) {
  string verb;
  verb = query_verb();
  if(this_player()->query_level() > 19) return 0;
  if(verb=="thank" ||
     verb=="sigh" || verb=="smile" ||
     verb=="groan" || verb=="scream" ||
     verb=="converse" || verb=="who" ||
     verb=="sniff" || verb=="cry" ||
     verb=="push" || verb=="pull" ||
     verb=="spit" || verb=="grin" || verb=="sulk" ||
     verb=="grovel") return 0;
  if(verb=="unstrap") {
    write("This gag is far too tight.\n"); return 0; }
  write("You are gagged too well to do that!\n");
  return 1;
}
 
extra_look(str) {
  return str=="is gagged";
}
