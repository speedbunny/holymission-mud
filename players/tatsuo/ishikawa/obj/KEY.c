/* key by calidor 14.3 coded for whisky (just helping ;-)) */

/* ... added reset(), Herp */
 
id(str) { return str=="key"||str=="huge stone key"||str=="tatskey";}

reset(arg) {
object env;
string str;
  if (arg) {		/* nicht beim erzeugen durchfuehren ! */
    env=environment(this_object());
    if (!env || !(str=env->query_name()) || !find_player(str)
	     || env->query_linkdeath())
       destruct(this_object()); /* if no player, or the player is linkdeath */
  }
}
 
short() { return "a huge stone key";}
 
long() { write("A huge stone key carved from black marble. It is heavy.\n");}
 
query_value() {return 1;}
query_quest_item() {return 1;}
get() {return 1; }


give() {
  write("The key crumbles to dust!\n");
  destruct(this_object());
  return 1;
}

put() { 
  write("You break the key, trying to fit it into that.\n");
  destruct(this_object());
  return 1;
}
