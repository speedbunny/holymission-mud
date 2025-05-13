
/* Deutscher Chat-channel          nach eine Idee von Auslander aka Sentinel */
/* Idee uebernommen und kodiert von Herp		         	     */

#define FILENAME "players/herp/obj/ohrring"	/* change if neccessary */

int is_broadcasting;

id(str) { return str=="ring" || str=="ohrring"; }

short() { return "Ein goldener Ohrring"; }

long() { 
 write("Mit diesem Ohrring kannst dich ueber den deutsch Kanal unterhalten.\n"
     + "Verwendung: deutsch <nachrichten-text> oder\n"
     + "            de      <nachrichten-text> oder\n"
     + "            18      <nachrichten-text>.\n\n"
     + "Fuer Nichteingeweihte: 18 ist die Kanalnummer, auf denen die Fernfahrer"
     + "\ndeutsch daherquasseln :-)\n");
 return 1;
}

reset() { is_broadcasting=1; }
init() { 
   add_action("broadcast","deutsch");
   add_action("broadcast","de");
   add_action("broadcast","18");
}

get() { return 1; }
#if 0 /* Bonzo, 8/7/1992, 15:26 */
drop() { return 1; }
#endif
#if 1 /* Bonzo, 8/7/1992, as well. This is so that I can replace damaged ohrrings. */
drop()
{
 if(!this_player()->query_wizard()) return 1;
    /* normal players can't drop it. */
}
#endif

query_broadcast() { return is_broadcasting; }

/* query_auto_load() { return FILENAME+":"+is_broadcasting; } */
 
broadcast(str) {
object u,r; 
string pre_msg; 
int i;

  if (str) {
     if (query_verb()=="18") pre_msg="[*18*] "; /* wozu soll das wieder gut sein ? */
	else pre_msg="";
     if (str=="on" && !is_broadcasting) {
        is_broadcasting=1;
	write("Jau, der deutsche Quasselkanal ist aktiviert.\n");
	return 1;
     }
     if (str=="off" && is_broadcasting) {
	is_broadcasting=0;
	write("Deutscher Quasselkanal abgeschaltet.\n");
	return 1;
     }
     if (!is_broadcasting) {
	write("Ohrring ist abgeschalten, senden/empfangen nicht moeglich.\n");
	return 1;
     } 
     u=users();
     for (i=0; i<sizeof(u); i++)
	 if ((r=present("ring",u[i])) && r->query_broadcast())
	    tell_object(u[i],pre_msg+capitalize(this_player()->query_name())
		      + " sagt: "+str+"\n");
     return 1;
  } 

  /* Anzeige wer aller nen Ring hat und ob er aktiv ist. */
 
  u=users();
  for (i=0;i<sizeof(u);i++)
      if (r=present("ohrring",u[i])) {
	 if (r->query_broadcast()) write("EMPFAENGT:  ");
			      else write("FUNKSTILLE: ");
	 write(u[i]->query_name()+"\n");
      }
  return 1; 
}
