/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* ARGH ! Manchmal gehts einem auf die Nerven wenn man nur ein Monster
 * auf einmal dreschen kann ....
 */

inherit "obj/weapon";

reset(arg) {
  if (arg) return;
  set_name("Argh, Herp's little knife");
  set_alias("argh");
  set_alt_name("knife");
  set_long("You see the picture of a figthing red bull.\n" +
	   "It seems to you he's snorting 'Argh' ...\n");
  set_class(3);
}

init() {
  ::init();
  add_action("argh","argh");
}

drop() { destruct(this_object()); return 1; }

argh() {
object *ob;
int i;
  if ( 1 /* this_player()->query_wizard() */ ) {
     if (!wielded) {
	write("You must wield "+short_desc+" first.\n");
	return 1;
     }
     ob=all_inventory(environment(this_player()));
     write("You stomp on the ground and snort like an attacking bull.\n");
     say(this_player()->query_name()+" stomps on the ground and "+
	   "snorts like an attacking bull.\n");
     for (i=0;i<sizeof(ob);i++)
	 if (living(ob[i]) && ob[i]->query_npc())
	    ob[i]->hit_player(100000);	/* should be enough */
     return 1;
  }
}
