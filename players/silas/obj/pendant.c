
/* Deutscher Chat-channel          nach eine Idee von Auslander aka Sentinel */
/* Idee uebernommen und kodiert von Herp                         */
/* Code translated into English and modified by Silas                         */

int is_broadcasting;

id(str) { return str=="pendant"; }

short() { return "An iron cross pendant (worn)"; }

long() { 
 write("You can use this pendant to communicate via a special frequency.\n"
     + "\n"
     + "Turn channel on..............33 on\n"
     + "Turn channel off.............33 off\n"
     + "Who else is online...........33\n"
     + "Broadcast....................33 <message>\n");
 return 1;
}

init() { 
   add_action("broadcast","33");
}

get() { return 1; }
drop(){ return 1; }

query_broadcast() { return is_broadcasting; }

query_auto_load() { return "players/silas/obj/pendant:"+is_broadcasting; }
 
broadcast(str) {
object u,r; 
string pre_msg; 
int i;

  if (str) {
     if (query_verb()=="33") pre_msg="[*33*] "; /* wozu soll das wieder gut sein ? */
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
    write("The pendant has been deactivated, sending/receiving isn't possible.\n");
    return 1;
     } 
     u=users();
     for (i=0; i<sizeof(u); i++)
     if ((r=present("pendant",u[i])) && r->query_broadcast())
        tell_object(u[i],pre_msg+capitalize(this_player()->query_name())
              + " says: "+str+"\n");
     return 1;
  } 

  /* Anzeige wer aller nen Ring hat und ob er aktiv ist. */
 
  u=users();
  for (i=0;i<sizeof(u);i++)
      if (r=present("pendant",u[i])) {
     if (r->query_broadcast()) write("RECEIVING:  ");
                  else write("RADIO SILENCE: ");
     write(u[i]->query_name()+"\n");
      }
  return 1; 
}
