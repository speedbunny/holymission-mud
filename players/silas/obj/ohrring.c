
/* Deutscher Chat-channel          nach eine Idee von Auslander aka Sentinel */
/* Idee uebernommen und kodiert von Herp                         */
/* Code translated into English by Silas                         */

#define FILENAME "players/silas/obj/ohrring"    /* change if neccessary */

int is_broadcasting;

id(str) { return str=="ring" || str=="earring"; }

short() { return "A golden earring"; }

long() { 
 write("Mit diesem Ohrring kannst dich ueber den deutschen Kanal unterhalten.\n"
     + "Verwendung: deutsch <nachrichten-text> oder\n"
     + "            de      <nachrichten-text> oder\n"
     + "            18      <nachrichten-text>.\n\n"
     + "Fuer Nichteingeweihte: 18 ist die Kanalnummer, auf denen die Fernfahrer"
     + "\ndeutsch daherquasseln :-)\n");
 return 1;
 /*
 You can talk on the German chat channel with this earring.
 usage: deutsch <message>  or
        de      <message>  or
        18      <message>.
 
        18 off -> switch off the channel
        18 on  -> switch on the channel
        18     -> show users

 For those who don't know it: 18 is the broadcast channel where truckers
 broadcast in German on their long journeys all over the country :-)
 */
}

init() { 
   add_action("broadcast","radio");
   add_action("broadcast","ra");
   add_action("broadcast","18");
}

get() { return 1; }
drop(){ return 1; }

query_broadcast() { return is_broadcasting; }

query_auto_load() { return FILENAME+":"+is_broadcasting; }
 
broadcast(str) {
object u,r; 
string pre_msg; 
int i;

  if (str) {
     if (query_verb()=="18") pre_msg="[*18*] "; /* wozu soll das wieder gut sein ? */
    else pre_msg="";
     if (str=="on" && !is_broadcasting) {
        is_broadcasting=1;
    write("The radio channel has been opened.\n");
    return 1;
     }
     if (str=="off" && is_broadcasting) {
    is_broadcasting=0;
    write("The radio channel has been closed.\n");
    return 1;
     }
     if (!is_broadcasting) {
    write("The earring has been turned off, sending/receiving isn't possible.\n");
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
     if (r->query_broadcast()) write("RECEIVING:  ");
                  else write("RADIO SILENCE: ");
     write(u[i]->query_name()+"\n");
      }
  return 1; 
}
