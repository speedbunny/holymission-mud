/* key by calidor 14.3 coded for whisky (just helping ;-)) */

/* ... added reset(), Herp */
 
id(str) { return str=="key"||str=="golden key"||str=="whiskeykey";}

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
 
short() { return "a golden key";}
 
long() { write("It is just a little golden key.\n");}
 
query_value() {return 1;}
query_quest_item() {return 1;}
get() {return 1; }

drop() {
  write("Your golden key crumbles to dust.\n");
  destruct(this_object());
  return 1;
}

give() {
  write("The key loses it's magical power and crumbles to dust.\n");
  destruct(this_object());
  return 1;
}

put() { 
  write("The key loses it's magical power and crumbles to dust.\n");
  destruct(this_object());
  return 1;
}
