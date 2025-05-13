/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

#define	PATH	"players/herp/dragon"

#define	TP	this_player()
#define TO	this_object()
#define TPN	this_player()->query_name()
#define	env	environment

#define SAY(x)	tell_room(env(),x)

status broken;

id(str) { return (str=="egg" && !broken) || (str=="eggshell" && broken); }
short() { return (broken?"Some eggshells":"An egg"); }
long() { write("It is a green egg with brown spots.\n"); }
get() { return 1; }
init() { add_action("eat","eat"); }
eat() {
  write("You brake the egg and eat it.\n" +
	"It tastes disgusting !\n" +
	"You puke on your shoes.\n");
  say(TPN+" swallows a raw egg and pukes on his shoes.\n");
  TP->reduce_hp(random(20)+1);
  destruct(TO);
  return 1;
}

reset(arg) {
string s;
int i;

  if (!arg) {
     if (sscanf(file_name(this_object()),"%s#%d",s,i)==2)
	call_out("breed_dragon",1800); /* half an hour */
     broken=0;
  }
}

breed_dragon() {
object *u,pl,drago;
int i;

  pl=env(TO);
  if (living(pl)) {
      tell_object(env(TO),"You drop the egg.\n");
      move_object(TO,env(pl));
      say(TPN+" drops an egg.\n",pl);
  } else {
    SAY("Suddenly a little egg slightly begins to move.\n");
  }
  SAY("The egg breaks.\n\nA tiny little dragon crawls out of the eggshells "+
      "and runs away.\n");
  broken=1;
  move_object(drago=clone_object(PATH+"/dragon"),env(TO));
  drago->run_away();
  if (env(drago)==env(TO)) {
     SAY("The little dragon is mad with fear ! It attacks !\n");
     u=all_inventory(env(TO));
     for (i=0;i<sizeof(u);i++) {
	 if (living(u[i]) && !u[i]->query_npc() && !u[i]->query_invis()
			  && !u[i]->query_linkdeath() ) {
	    drago->attack_object(u[i]);
	    return;
	 }
     }
     SAY("The little dragon looks confused.\nIt sits down on its tail and weeps.\n");
  }
}
