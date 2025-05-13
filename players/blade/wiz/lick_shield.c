/* NoHear Shadow for Blade's WizCloak */
/* Coded by Blade on Holy Mission     */
/* Version 10.18.94                   */

object master;

void start_shad(object obj) {
  master = obj;
  shadow(master, 1);
}

catch_tell(str) {
  string dummy1;
  object dude;

  if(master){
    if(sscanf(str, "The distant %s lustfully licks you.", dummy1)==1 ||
       sscanf(str, "%s licks you lustfully.",dummy1)==1 ){
      dude = find_player(lower_case(dummy1));
      if(dude)
	tell_object(dude, "You try to lick "+master->query_name()+" but "+
		    master->query_pronoun()+" dodges it!\n");
      tell_object(master, dude->query_name()+ 
		  " tried to lick you, but you dodged it!\n");
      return str;
    }
    write(str);
  }
  return str;
}

object query_lickshield(){
  return(this_object());
}









