// 10-24-94: Recoded by Mangla to be more efficient not using go
//               to room and look

inherit "/obj/treasure";

int      charges;
 
int foo() {
    return 1;
}

int gaze_eye(string str) {

    object   *inven, who, targetloc;
    string   s;
    int      i;

    if (!str) {
	write("You gaze in the air....\n");
	say(this_player()->query_name()+" gazes in the air.\n");
	return 1;
    }
    if (sscanf(str,"at %s",s)==1) str=s;
    if (!who = find_living(str)) {
        printf("A voice inside your head tells you %s is not alive right now.\n",
               capitalize(str));
        say(this_player()->query_name() + " peers perplexedly into a catseye.\n");
        return 1;
    }
    if(who->query_wizard()) {
        printf("Do not even THINK about looking at a wiz.\n");
        printf("This is for finding players, not wizards.\n");
        return 1;
    }
    write("You gaze into the catseye and see " + capitalize(str) + ".\n\n");
    say(this_player()->query_name() + " peers into a catseye.\n");
    targetloc = environment(who);
    targetloc->long();
    write("\n");
    tell_object(who,"You feel like someone is watching you.\n");
    write("Looking through the eye, you see that " + str + " is carrying:\n");
    inven = all_inventory(who);
    if (inven)
        for (i = 0; i < sizeof(inven); i++)
            if(s = inven[i]->short())
                write(s + "\n");

    if (charges == 0) {
        write("\nThe catseye begins to glow with a holy light.\n");
        write("The light grows brighter and brighter.\n");
        write("When you can see again, the eye is gone.\n");
        say(this_player()->query_name() + " begins to glow brightly!\n");
        say("The blinding aura fades to a dull glow and vanishes.\n");
        destruct(this_object());
    }
    else charges--;
    return 1;
}
 
int _drop_object(string str) {

    if (str == "all") {
        _drop_object("catseye");
        return 0;
    }
    if (!str || str != "catseye" || str != "eye") return 0;
	if(environment() != this_player()) return 0;
        write("The catseye shatters into a million pieces.\n");
        say(this_player()->query_name() + " drops a catseye. It shatters into a million pieces.\n");
    destruct(this_object());
    return 1;
}
 
 
void reset(int arg) {
    if (arg) return;

    charges=random(5)+1;
    set_short("A catseye");
    set_long("This looks like a cats eye embedded in a black stone.\n" +
             "The cats eye seems to have a look to it that is somehow\n" +
             "giving you the impression it is following you.\n" +
             "The eye is glowing with a soft inner light.\n" +
             "You seem to be gazing at a door through space.\n");
    set_value(2500);
    set_weight(2);
    set_alias("eye");
    
}
 
  
void init() {
    add_action("gaze_eye","gaze");
    add_action("_drop_object","drop");
}

