/* NoHear Shadow for Blade's WizCloak */
/* Coded by Blade on Holy Mission     */
/* Shamelessly pirated from Tatsuo    */
/* Version 10.18.94                   */

object master;

void start_shad(object obj) {
  master = obj;
  shadow(master, 1);
}

catch_tell(str) {
  string dummy1;
  string dummy2;
  object dude;

  if(master) {
    if(sscanf(str, "%s tells you: %s", dummy1, dummy2) == 2) {
      dude = find_player(lower_case(dummy1));
      if(dude) tell_object(dude, master->query_name()+" is unable to hear.\n");
      return str;}
    else if(sscanf(str, "%s shouts: %s", dummy1, dummy2) == 2) return str;
    else if(sscanf(str, " :*) %s thinks %s",dummy1,dummy2) == 2) {
      dude = find_player(lower_case(dummy1));
      tell_object(dude, master->query_name()+" is unable to hear.\n");
      return str;}
    else if(sscanf(str, "You notice %s %s",dummy1,dummy2) == 2){
      dude = find_player(lower_case(dummy1));
      tell_object(dude, master->query_name()+" is unable to hear.\n");
      return str;}
    else if(sscanf(str,"%s %s",dummy1,dummy2) == 2){
      dude = find_player(lower_case(dummy1));
	if(dude&&(dude!=master)){
	  tell_object(dude, master->query_name()+" cant hear.\n");
	  return 1;
	}
    }
    write(str);
  }
  return str;
}












