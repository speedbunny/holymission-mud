id(str) { return str=="sil" || str=="silencer"; }

short() { return "A silencer"; }
long() { write("You see a face with no eyes, no ears and no mouth.\n"); }
init() { add_action("sil","silence"); }
get()  { return 1; }

sil(str) {
string who,col;
object ob;

  if (!str) return;
  if (sscanf(str,"%s %s",who,col)!=2) col="1";
  if (!who || !(ob=find_player(who))) return; 
  tell_object(ob,
	      "You suddenly feel very peaceful, "+
	      "like having smoked 10g Ganja.\n" +
	      "You grow silent ...["+col+"m\n");
  write("You turn to silence "+ob->query_name()+" ...\n");
  say(this_player()->query_name()+" makes a magical gesture towards "+
	ob->query_name()+".\n");
  return 1;
}
