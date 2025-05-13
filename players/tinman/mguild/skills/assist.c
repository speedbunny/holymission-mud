

/* =============================================================== 
   Userdoc: assist          /players/whisky/guild/skills/assist.c
   ---------------------------------------------------------------
   Art: helping a friend fighting a monster via assist <name>
   Damage || Heal: none
   Cost: none
   Special: no real advantage, just a quicker typing sometimes /
            no real monkskill anymore, was taken into the lib. 
   =============================================================== */

int assist(string arg)
{
   object friend, victim;
   closure call;

   call = #'call_other;

    if (!stringp(arg) || arg == apply(call,this_player(),"query_real_name"))
    {
        write("Assist whom ?\n");
        return 1;
    }

    friend = present(arg,environment(this_player()));

    if (!objectp(friend))       
        write("You can't assist someone who isn't here !\n");
    else if (!living(friend))
        write("But "+arg+" is no living !\n");
    else if (objectp(victim = apply(call,this_player(),"query_attack")) &&
             environment(this_player())==environment(victim))
    {
        write("NO WAY ! You are fighting for your life !\n");
    }
    else if (!objectp(victim = apply(call,friend,"query_attack")) 
             || !living(victim))
        write("But "+capitalize(arg)+" isn't fighting anyone !\n");
    else 
    {
        write("You jump in the fight to assist "+capitalize(arg)+" !\n");
        tell_object(friend,apply(call,this_player(),"query_name")+
                    " assists you !\n");
        say(apply(call,this_player(),"query_name")+
            " assists "+capitalize(arg)+"\n",
            friend,this_player());
        tell_object(friend,apply(call,this_player(),"query_name")+
                    " assists you !\n");
        apply(call,this_player(),"attack_object",victim);
     }
   return 1;
}
