#include "/obj/lw.h"

int strength;


short() { return "A carrier pigeon in a cage"; }

long() { write(lw("It is a carrier pigeon from the fighters guild used to take messages to other players in the Holy Mission.\nYou can use this pigeon with the command 'ptell <player> <msg>'.\n")); }

id(string str) { return (str=="cage" || str=="pigeon" || str=="carrier pidgeon"); }

get() { return 1; }
drop() { if(query_verb()!="quit") 
                write("The bond between you and the pigeon is just too great to break it now.\n");
         return 1; }

reset(int arg) {
        if(arg) return;
        strength=45;
}

init() {
        add_action("ptell","ptell");
}

ptell(string str) {
        string *message,towrite;
        object sentto;

        if(!str) { 
         notify_fail("To your amazement the pigeon tells you: To use me you have to type 'ptell <playername> <msg>'.\n");
         return 0;
        }
        message = explode(str," ");
        message[0]=lower_case(message[0]);
        if(!sentto = find_living(message[0])) {
         write(lw("You throw the pigeon high into the air and it flies around in a circle above your head looking confused before landing on your shoulder and saying: There isn`t anyone with that name is logged on.\n"));
         return 1;
        } else {
         str=extract(str,strlen(message[0])+1);
         towrite="The pigeon flies off in search of "+capitalize(message[0])+" and returns a moment later.\n";
         towrite+="The pigeon tells you: ";
   if(sentto->query_earmuff_level()> this_player()->query_level())
            towrite+="I dont think they want to be disturbed at the moment but you could probably try again later?\n";
         else if(sentto->query_linkdeath()) 
            towrite+="I have not learnt how to talk to the linkdead yet.\n";
         else if(!(int)query_ip_number(sentto)) 
            towrite+="I will not talk to characters that are not players.\n";
         else if(sentto==this_player())
            towrite+="Why do you want to send a message to yourself?\n";
         else if(query_editing(sentto))
            towrite+="That wizard was editing something when I arrived so why not try again in a few minutes.\n";
         else { 
                tell_object(sentto,"A carrier pigeon arrives from "+this_player()->query_name()+" with a message attached to its leg which reads: "+str+"\nThe pigeon flies off again.\n");
                if(query_input_pending(sentto))
                   towrite+="That player was writing a message at the moment but I sent the message anyway.\n";
                else if(query_idle(sentto)>300)
		   towrite+="When I got there it looked as though they were inactive but I sent the message anyway. Maybe they will get back to you later.\n";
                else 
                   towrite+="I sent the message.\n";
                }
         }
        if(strength<5 && strength)
                towrite+="As the pigeon returns you notice that it looks weak and ready to drop.\n";
        else if(!strength) {
                write(lw(towrite+"You notice the pigeon in the distance suddenly fall from the sky and at the same time the cage that you kept him in disappears from your inventory.\n"));
                destruct(this_object());
                return 1;
        } else towrite+="The pigeon quickly returns to its cage.\n";
        write(lw(towrite));
        return 1;
}
