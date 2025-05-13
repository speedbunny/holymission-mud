#define MUDGOD "deepthought"
#define MUDNAME "Nightfall"

fail(str) {
	ghost();
	if (!str) return 0;
	write("You try to " + str + " but fail.\n");
	say(cap_name + " tries to " + str + " but fails.\n");
	return 1;
}

admire(str) {
object who;
	ghost();
	if (!str) {
		write("Who, or what do you admire?\n");
		return 1;
	}
	who=present(lower_case(str), environment(me));
	if (!who) {
		write(str + " is not here!\n");
		return 1;
	}
	if (!living(who)) {
		write("You admire " + who->short() + ".\n");
		say(cap_name + " admires " + who->short() + ".\n");
		return 1;
	}
	if (who==this_player()) {
		write("You admire yourself. Ah, how nice we are!\n");
		say(cap_name + " admires " + who->query_objective() + 
			"self. Disgusting!\n");
		return 1;
	}
	write("You admire " + capitalize(str) + ".\n");
	say(cap_name + " admires " + capitalize(str) + ".\n", who);
	tell_object(who, cap_name + " admires you.\n");
	return 1;
}

pat(str) {	/* idea: white queens famous all purpose soul addendum */
string adv, per; object who; int i;
	if (ghost()) return 0;
	if (!str) return 0;
	i = pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
	    write("You pat " + per + " on the head.\n");
	    say(cap_name + " pats " + per + " on the head.\n", who);
	    tell_object(who, cap_name + " pats you on the head.\n");
	    return 1;
	}
	if (i==3) {
	    write("You " + adv + " pat " + per + " on the head.\n");
	    say(cap_name + " " + adv + " pats " + per + " on the head.\n", who);
	    tell_object(who, cap_name + " " + adv + " pats you on the head.\n");
	    return 1;
	}
	return 0;
}


tongue(str) {
string adv, per; object who; int i;
	if (ghost()) return 0;
	if (!str) {
	    write("You stick your tongue out.\n");
	    say(cap_name + " sticks " + his + " tongue out.\n");
	    return 1;
	}
	i = pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
	    write("You " + adv + " stick your tongue out.\n");
	    say(cap_name + " " + adv + " sticks " + his + " tongue out.\n");
	    return 1;
	}
	if (i==2) {
	    write("You stick your tongue out to " + per + ".\n");
	    say(cap_name + " sticks " + his + " tongue out to " + per + ".\n", who);
	    tell_object(who, cap_name + " sticks " + his +
		 " tongue out to you.\n");
	    return 1;
	}
	if (i==3) {
	    write("You " + adv + " stick your tongue out to " + per + ".\n");
	    say(cap_name + " " + adv + " sticks " + his 
		+ " tongue out to " + per + ".\n", who);
	    tell_object(who, cap_name + " " + adv + " sticks " + his
		+ " tongue out to you.\n");
	    return 1;
	}
	return 0;
}

		
stare(str) {
string adv, per; object who; int i;
	if (ghost()) return 0;
	if (!str) {
		write("You stare into space.\n");
		say(cap_name + " stares into space.\n");
		return 1;
	}
	i = pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
		write("You " + adv + " stare into space.\n");
		say(cap_name + " " + adv + " stares into space.\n");
		return 1;
	}
	if (i==2) {
		write("You stare dreamily at " + per + ".\n");
		say(cap_name + " stares dreamily at " + per + ".\n", who);
		tell_object(who, cap_name + " stares dreamily at you.\n");
		return 1;
	}
	if (i==3) {
		write("You stare " + adv + " at " + per + ".\n");
		say(cap_name + " stares " + adv + " at " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " stares at you.\n"); 
		return 1;
	}	
}
nose(str) {
string adv, per; object who; int i;
	if (ghost()) return 0;
	if (!str) return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
		write("You rub your nose tenderly on " + per + "'s.\n");
		say(cap_name + " rubs " + his + " nose tenderly on " 
		+ per + "'s.\n", who);
		tell_object(who, cap_name + " rubs " + his 
		+ " nose tenderly on yours.\n");
		return 1;
	}
	if (i==3) {
		write("You rub your nose " + adv + " on " + per + "'s.\n");
		say(cap_name + " rubs " + his + " nose " + adv + " on " + per +
			"'s.\n", who);
		tell_object(who, cap_name + " rubs " + his + " nose " + adv +
			" on yours.\n");
		return 1;
	}
}

excuse(str) {
string adv, per; object who; int i;
	if (ghost()) return 0;
	if (!str) return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
		write("You shamefully excuse yourself to " + per + ".\n");
		say(cap_name + " shamefully excuses " 
		+ him + "self to "  + per + ".\n", who);
		tell_object(who, cap_name + " shamefully excuses " + him 
		+ "self to you.\n");
		return 1;
	}
	if (i==3) {
		write("You " + adv + " excuse yourself to " + per + ".\n");
		say(cap_name + " " + adv + " excuses " 
		+ him + "self to "  + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " excuses " + him 
		+ "self to you.\n");
		return 1;
	}
	return 0;
}

bang(str) {
string adv, per; object who; int i;
	if (ghost()) return 0;
	if (!str) {
		write("You angrily bang your head against the next wall.\n");
	    say(cap_name + " angrily bangs " + his 
	    + " head against the next wall.\n");
	    return 1;
	}
	i=pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
	    write("You " + adv + " bang your head against the next wall.\n");
	    say(cap_name + " " + adv + " bangs " + his 
	    + " head against the next wall.\n");
	    return 1;
	}
	return 0;
}

roll(str) {
string adv;
	if (ghost()) return 0;
	if (!str) {
	    write("You roll your eyes to the ceiling.\n");
	    say(cap_name + " rolls " + his + " eyes to the ceiling.\n");
	    return 1;
	}
	adv=get_adv(str);
	if (!adv) return 0;
	write("You " + adv + " roll your eyes to the ceiling.\n");
	say(cap_name + " " + adv + " rolls " + his + " eyes to the ceiling.\n");
	return 1;
}


wink(str) {
string adv, per; object who; int i;
	if (ghost()) return 0;
	if (!str) {
		write("You wink suggestively.\n");
		say(cap_name + " winks suggestively.\n");
		return 1;
	}
	i = pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
		write("You wink " + adv + ".\n");
		say(cap_name + " winks " + adv + ".\n");
		return 1;
	}
	if (i==2) {
		write("You wink suggestively at " + per + ".\n");
		say(cap_name + " winks suggestively at " + per + ".\n", who);
		tell_object(who, cap_name + " winks suggestively at you.\n");
		return 1;
	}
	if (i==3) {
		write("You wink " + adv + " at " + per + ".\n");
		say(cap_name + " winks " + adv + " at " + per + ".\n", who);
		tell_object(who, cap_name + " winks " + adv + " at you.\n"); 
		return 1;
	}
}

apologize(str) {
string adv, per; object who; int i;
	ghost();
	if(!str) {
		write("You apologize yourself to the audience.\n");
		say(cap_name + " apologizes " + 
			pron(me) + "self to the audience.\n");
		return 1;
	}
	i=pers_verb(str);
    if (i<1) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
        if (i==1) {
        write("You " + adv + " apologize yourself to the audience.\n");
    	say(cap_name + " " + adv + " apologizes " + 
			pron(me) + "self to the audience.\n");
        return 1;
    }
    if (i==2) {
        write("You apologize yourself to " + per +".\n");
        say(cap_name + " apologizes " + pron(me) + "self to " +
			per + ".\n", who);
        tell_object(who, cap_name + " apologizes " + pron(me) +
                "self to you.\n");
        return 1;
        }
    if (i==3) {
        write("You " + adv + " apologize yourself to " + per+".\n");
        say(cap_name + " " + adv +" apologizes " + pron(me) + "self to " +
			per + ".\n", who);
        tell_object(who, cap_name + " " + adv +  " apologizes " + pron(me) +
                "self to you.\n");
        return 1;
    }
}
applaud(str) {
    if (ghost())
        return 0;
	if (!str) {
    	write("You applaud wholeheartedly.\n");
   		say(cap_name + " gives a round of applause.\n");
    	return 1;
	}
	return (verb_adv_at_per(str, " to "));
}



bow(str) {
object who, list;
string adv, per;
int i;
	ghost();
    if (!str) {
        write("You bow to your audience.\n");
        say(cap_name + " bows gracefully.\n");
        return 1;
    }
	if (str=="all") {
		list = users();
		for (i=0; i<sizeof(list);i++) {
			who = list[i];
			str=who->query_name();
			who = present(lower_case(str), environment(this_player()));
			if (who && living(who) && who!=this_player()) {
				write("You bow to " + who->query_name() +
				".\n");
				say(cap_name + " bows to " + who->query_name() +
				".\n", who);
				tell_object(who, cap_name + " bows to you.\n");
			}
		}
		return 1;
    }
	return(verb_adv_at_per(str, " to "));
}

comfort(str) {
int i;
string adv, per;
object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
	i=pers_verb(str); 
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
		write("You comfort " + per + ".\n");
		say(cap_name + " comforts " + per + ".\n", who);
		tell_object(who, cap_name + " comforts you.\n");
		return 1;
	}
	if (i==3) {
		write("You " + adv + " comfort " + per + ".\n");
		say(cap_name + " " + adv + " comforts " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " comforts you.\n");
		return 1;
	}
    return 1;
}


complain(str) {
string adv, per; object who; int i;
	if (str=="about box") 
		return 0;
	/* Just for padrones safe deposit box. */
	ghost();
	if(!str) {
		write("You complain bitterly about god, the world and" + 
			" life in general.\n"); 
		say(cap_name + " complains bitterly about god, the world and " +
			"life in general.\n");
		return 1;
	}
	i = pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
		write("You complain " + adv + " about god, the world and" +
            " life in general.\n");
        say(cap_name + " complains " + adv + " about god, the world and" +
           " life in general.\n");
		return 1;
	}
	if (i==2) {
	 write("You complain bitterly about " + per + ".\n");
	 say(cap_name + " complains bitterly about " + per + ".\n", who);
	 tell_object(who, cap_name + " complains bitterly about you!\n");
	 return 1;
	}
	if (i==3) {
		write("You complain " + adv + " about " + per + ".\n");
		say(cap_name + " complains " + adv + " about " 
		+ per + ".\n", who);
		tell_object(who, cap_name + " complains " + adv + " about you!\n");
		return 1;
	}
}

cuddle(str) {
int i; string adv, per; object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
    	write("You cuddle " + per + ".\n");
    	say(cap_name + " cuddles " + per + ".\n", who);
    	tell_object(who, cap_name + " cuddles you.\n");
    	return 1;
	}
	if (i==3) {
		write("You " + adv + " cuddle " + per + ".\n");
		say(cap_name + " " + adv + " cuddles " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " cuddles you.\n");
		return 1;
	}
}

/*
curse(str) {
object who;

	ghost();
	if (!str) {
		write("You curse violently.\n");
		say(cap_name + " violently curses and makes some rude guestures.\n");
		return 1;
	}
	who = present(lower_case(str), environment(this_player()));
	if (!who || !living(who) || who==this_player()) {
		write("You violently curse " + str + ".\n");
		say(cap_name + " violently curses " + str + ".\n");
		return 1;
	}
	write("You make some rude guestures and curse " + capitalize(str) 
		+ " violently.\n");
	say(cap_name + " makes some rude guestures and curses " + capitalize(str) 
		+ " violently.\n", who);
	tell_object(who, cap_name 
		+ " makes some rude guestures and curses you violently.\n");
	return 1;
}  */
curtsey(str) {
object who, list;
string adv, per;
int i;
    ghost();
    if (!str) {
	write("You curtsey gracefully.\n");
	say(cap_name + " curtseys gracefully.\n");
	return 1;
    }
    return(verb_adv_at_per(str, " to "));
    return 1;
}
dance(str) {
int i; string adv, per; object who;
    if (ghost())
        return 0;
    if (!str) {
        write("Feels silly, doesn't it?\n");
		write("You do the disco duck.\n");
        say(cap_name + " does the disco duck.\n");
        return 1;
    }
	i=pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
		write("You " + adv + " do the disco duck.\n");
		say(cap_name + " " + adv + " does the disco duck.\n");
		return 1;
	}
	if (i==2) {
		write("You sweep " + per + " across the dance floor.\n");
		say(cap_name + " sweeps " + per + " across the dance floor.\n",who);
		tell_object(who, cap_name + " sweeps you across the dance floor.\n");
		return 1;
	}
	if (i==3) {
		write("You " + adv + " sweep " + per + " across the dance floor.\n");
		say(cap_name + " " + adv + " sweeps " + per + " across the " +
			"dance floor.\n", who);
		tell_object(who, cap_name + " " + adv + " sweeps you across the " + 
			"dance floor.\n");
		return 1;
	}
	return 0;
}


finger(str) {
int i; string adv, per; object who;
	ghost();
	if (ghost()) return 0;
	if (!str) {
	    write("You show your bad middle finger to the persons present.\n");
	    say(cap_name + " shows " + his +
			" bad middle finger to the persons present.\n");
	    return 1;
	}
	i=pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
	    write("You " + adv + " show your bad middle finger to " 
	    + "the persons present.\n");
	    say(cap_name + " " + adv + " shows " + his + " bad middle finger"+
	    " to the persons present.\n");
	    return 1;
	}
	if (i==2) {
	    write("You show your bad middle finger to " + per + ".\n");
	    say(cap_name + " shows " + his + " bad middle finger"+
		" to " + per + ".\n", who);
	    tell_object(who, cap_name + " shows you " + his +
		" bad middle finger!\n");
	    return 1;
	}
	if (i==3) {
	    write("You " + adv + " show your bad middle finger to " 
		+ per + ".\n");
	    say(cap_name + " " + adv + " shows " + his + " bad middle finger"+
		" to " + per + ".\n", who);
	    tell_object(who, cap_name + " " + adv + " shows you " + his +
		" bad middle finger!\n");
	    return 1;
	}
}

/* fear(str) {
object who;
	ghost();
	if (!str) {
		write("You shiver with fear.\n");
		say(cap_name + " shivers with fear.\n");
		return 1;
	}
	who = present(lower_case(str), environment(this_player()));
	if (!who || !living(who)) {
		write(capitalize(str) + " is not here!\n");
		return 1;
	}
	write("You look frightfully at " + 
		capitalize(who->query_name()) + " and shiver with fear.\n");
	say(cap_name + " looks frightfully at " + capitalize(str) +
		" and shivers with fear.\n", who);
	tell_object(who, cap_name 
		+ " looks frightfully at you and shivers with fear.\n");
	return 1;
}   */
fondle(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (!str)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
		write("You fondle " + per + ".\n");
		say(cap_name + " fondles " + per + ".\n", who);
		tell_object(who, cap_name + " fondles you.\n");
		return 1;
	}
	if (i==3) {
		write("You " + adv + " fondle " + per + ".\n");
		say(cap_name + " " + adv + " fondles " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " fondles you.\n");
		return 1;
	}
}
french(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (!str)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
    	write("You give " + per + " a REAL kiss..it lasts a long time...\n");
   	 	say(cap_name + " gives " + per +
         " a deep and passionate kiss..it seems to take forever...\n", who);
    	tell_object(who, cap_name +
        " gives you a deep and passionate kiss..it seems to take forever...\n");
    	return 1;
	}
	if (i==3) {
		write("You " + adv + " give " + per + " a REAL kiss...it seems to " +
		"take forever...\n");
		say(cap_name + " " + adv + " gives " + per +
		 " a deep and passionate kiss...it seems to take forever...\n", who);
		tell_object(who, cap_name + " " + adv + 
		" gives you a deep and passionate kiss...it seems to take forever...\n");
		return 1;
	}
}
glare(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (!str)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
    	write("You glare stonily at " + per + ".\n");
    	say(cap_name + " stonily glares at " + per + ".\n", who);
   		tell_object(who, cap_name + " stonily glares at you.\n");
    	return 1;
	}
	if (i==3) {
		write("You glare " + adv + " at " + per + ".\n");
		say(cap_name + " " + adv + " glares at " +  per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " glares at you.\n");
		return 1;
	}
}

grope(str) {
int i; object who; string adv, per;
    if (ghost())
        return 0;
    if (!str)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
    	write("<Well what sort of noise do you expect here?>.\n");
		write("You grope " + per + ".\n");
    	say(cap_name + " gropes " + str + ".\n", who);
    	tell_object(who, cap_name + " gropes you.\n");
    	return 1;
	}
	if (i==3) {
		write("You " + adv + " grope " + per + ".\n");
		say(cap_name + " " + adv + " gropes " + per + ".\n",who);
		tell_object(who, cap_name + " " + adv + " gropes you.\n");
		return 1;
	}
}

hug(str) {
object who; int i; string adv, per;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	who=glob_who; adv=glob_adv; per=glob_per;
	if (i==2) {
    	write("You hug " + per + ".\n");
    	say(cap_name + " hugs " + per + ".\n", who);
    	tell_object(who, cap_name + " hugs you.\n");
    	return 1;
	}
	if (i==3) {
		write("You " + adv + " hug " + per + ".\n");
		say(cap_name + " " + adv + " hugs " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " hugs you.\n");
		return 1;
	}
}
kick(str) {
object who;  int i; string adv, per;
    if (ghost())
        return 0;
    if (!str) {
	write("You kick a long-forgotten, invisible, dead turtle.\n");
	say(cap_name + " kicks a long-forgotten, invisible, dead turtle.\n");
	return 1;
    }
	i=pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
		write("You " + adv + " kick a long-forgotten, invisible, dead turtle.\n");
		say(cap_name + " " + adv + " kicks a long-forgotten, invisible, dead turtle.\n");
		return 1;
	}
	if (i==2) {
    	write("You kick " + per + ".\n");
		say(cap_name + " kicks " + per + ".\n", who);
    	tell_object(who, cap_name + " kicks you.   OUCH!!\n");
		return 1;
	}
	if (i==3) {
		write("You " + adv + " kick " + per + ".\n");
		say(cap_name + " " + adv + " kicks " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " kicks you. OUCH!!\n");
		return 1;
	}
}

kiss(str) {
object who; int i; string adv, per;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (who==this_player()) return 0;
    if (call_other(who, "query_frog")) {
        call_other(this_player(), "frog_curse", 1);
        call_other(who, "frog_curse", 0);
        return 1;
    }
	if (i==2) {
    		write("You kiss " + per + ".\n");
    		say(cap_name + " kisses " + per + ".\n", who);
    		tell_object(who, cap_name + " kisses you.\n");
		return 1;
	}
	if (i==3) {
		write("You " + adv + " kiss " + per + ".\n");
		say(cap_name + " " + adv + " kisses " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " kisses you.\n");
		return 1;
	}
}
knee(str) {
object who; string adv, per; int i;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
    	if (who->query_male()) {
       	 say(cap_name + " suddenly raises " + his +
            " knee, sending " + per+ " to the floor, writhing in pain!\n",
            who);
       	 write("You hit " + per+ " with your knee.\n");
       	 tell_object(who, cap_name + " hits you with " +
                    his + " knee below your belt!\n" +
                    "You double over and fall to the ground, writhing in " +
                    "excrutiating pain,\nfeeling like you may throw up " +
                    "everything you have eaten!\n");
    	}
    	else {
        say(cap_name + " tries to knee "+per +", without much effect.\n", who);
        write("You try to knee " + per+ ". Not very effective though.\n");
        tell_object(who, cap_name +
		" tries to knee you, without much effect.\n");
    	}
    	return 1;
	}
	if (i==3) {
	   if (who->query_male()) {
		write("You " + adv + " hit " + per + " with your knee.\n");
		say(cap_name + " " + adv + " suddely raises " + his + 
			" knee, sending " + per + " to the florr, writhing in pain!\n",
		who);
		tell_object(who, cap_name + " " + adv + " hits you with " + his +
			" knee below your belt!\n" +
			"You double over and fall to the ground, writhing in  " + 
			"excrutiating pain,\nfeeling like you may throw up " + 
			"everything you have eaten!\n");
	   }
	   else {
		write("You " + adv + " tries to knee " + per + 
			", without much effect.\n");
		say(cap_name + " "  + adv + " tries to knee " + per + 
			", without much effect.\n", who);
		tell_object(who, cap_name + " " + adv + " tries to knee you," +
			"without much effect.\n");
	   }
	return 1;
	}
}
lick(str) {
string adv, per; object who; int i; 
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
	i=pers_verb(str);
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
    	say(cap_name + " licks " + per + ".\n", who);
    	write("You lick " + per + ".\n");
    	tell_object(who, cap_name + " licks you.\n");
    	return 1;
	}
	if (i==3) {
		write("You " + adv + " lick " + per + ".\n");
		say(cap_name + " " + adv + " licks " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " licks you.\n");
		return 1;
	}
}

love(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    i=pers_verb(str);
    if (i<2) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==2) {
    	say(cap_name + " whispers softly to " + per + ".\n", who);
   		write("You tell your true feelings to " + per + ".\n");
    	tell_object(who, cap_name + " whispers to you sweet words of love.\n");
    	return 1;
    }
    if (i==3) {
        write("You " + adv + " tell your true feelings to " + per + ".\n");
        tell_object(who, cap_name + " " + adv +
		  " whispers to you sweet words of love.\n");
        say(cap_name + " " + adv + " whispers softly to " + per + ".\n", who);
        return 1;
    }
}
nibble(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    i=pers_verb(str);
    if (i<2) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==2) {
    	say(cap_name + " nibbles on " + per + "s ear.\n", who);
    	write("You nibble " + per + "s ear.\n");
    	tell_object(who, cap_name + " nibbles on your ear.\n");
    	return 1;
	}
    if (i==3) {
        write("You " + adv + " nibble " + per + "s ear.\n");
        say(cap_name + " " + adv + " nibbles on " + per + "s ear.\n", who);
        tell_object(who,cap_name + " " + adv + " nibbles on your ear.\n");
		return 1;
	}
}
poke(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    i=pers_verb(str);
    if (i<2) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==2) {
    	say(cap_name + " pokes " + per + " in the ribs.\n", who);
    	write("You poke " + per + " in the ribs.\n");
    	tell_object(who, cap_name + " pokes you in the ribs.\n");
    	return 1;
	}
    if (i==3) {
        write("You " + adv + " poke " + per + " in the ribs.\n");
        say(cap_name + " " + adv + " pokes " + per + " in the ribs.\n", who);
        tell_object(who, cap_name + " " + adv + " pokes you in the ribs.\n");
        return 1;
    }
}
puke(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if(!str) {
        write("You puke on your shoes.\n");
        say(cap_name + " doubles over and pukes.\n");
        return 1;
    }
    i=pers_verb(str);
    if (i<1) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
        write("You " + adv + " puke on your shoes.\n");
        say(cap_name + " " + adv + " doubles over and pukes.\n");
		return 1;
	}
    if (i==2) {
    	write("You puke on " + per +".\n");
    	say(cap_name + " pukes on " + per + ".\n", who);
    	tell_object(who, cap_name + " pukes all over you!\n");
    	return 1;
	}
    if (i==3) {
        write("You " + adv + " puke on " + per+".\n");
        say(cap_name + " " + adv + " pukes on " + per + ".\n", who);
        tell_object(who, cap_name + " " + adv + " pukes all over you!\n");
        return 1;
    }
}
ruffle(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    i=pers_verb(str);
    if (i<2) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==2) {
    	write("You ruffle " + per + "s hair playfully.\n");
    	say(cap_name + " ruffles " + per + "s hair playfully.\n", who);
    	tell_object(who, cap_name + " ruffles your hair playfully.\n");
    	return 1;
    }
    if (i==3) {
        write("You " + adv + " ruffle " + per + "s hair playfully.\n");
        say(cap_name + " " + adv + " ruffles " + per 
			+ "s hair playfully.\n", who);
        tell_object(who, cap_name + " " + adv 
			+ " ruffles your hair playfully.\n");
        return 1;
    }
}

shiver(str) {
string adv;
    if (ghost())
        return 0;
	if (!str) {
    	write("Brrrrrr!!!\n");
    	say(cap_name + " shivers from the cold.\n");
    	return 1;
	}
	if (str) { 
		adv=get_adv(str);
		if (!adv) return 0;
		write("Brrrrrr!!!\n"); write("You " + adv+ " shiver from the cold.\n");
		say(cap_name + " " + adv + " shivers from the cold.\n");
		return 1;
	}
}
slap(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    i=pers_verb(str);
    if (i<2) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==2) {
    	write("You slap " + per + ".\n");
    	say(cap_name + " slaps " + per + ".\n", who);
    	tell_object(who, cap_name + " slaps you!\n");
    	return 1;
	}
    if (i==3) {
        write("You " + adv + " slap " + per + ".\n");
        say(cap_name + " " + adv + " slaps " + per + ".\n", who);
		tell_object(who,cap_name + " " + adv + " slaps you!\n");
        return 1;
    }
}
snap(str) {
string adv;
    if (ghost())
        return 0;
    if (!str) {
	write("You snap your fingers.\n");
	say(cap_name + " snaps " + his +
            " fingers.\n");
	return 1;
    }
    adv=get_adv(str);
    if (!adv) { no_ab(); return 1; }
    write("You " + adv + " snap your fingers.\n");
    say(cap_name + " " + adv + " snaps " + his + " fingers.\n");
    return 1;
}

snuggle(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    i=pers_verb(str);
    if (i<2) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==2) {
    	write("You snuggle " + per + ".\n");
    	say(cap_name + " snuggles up to " + per + ".\n", who);
    	tell_object(who, cap_name + " snuggles up to you.\n");
    	return 1;
    }
    if (i==3) {
        write("You " + adv + " snuggle " + per + ".\n");
        say(cap_name + " " + adv + " snuggles up to " + per + ".\n", who);
        tell_object(who, cap_name + " " + adv + " snuggles up to you.\n");
        return 1;
    }
}
spit(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if(!str) {
        write("You spit on the ground.\n");
        say(cap_name + " spits on the ground.\n");
        return 1;
    }
    i=pers_verb(str);
    if (i<1) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==1) {
        write("You " + adv + " spit on the ground.\n");
        say(cap_name + " " + adv + " spits on the ground.\n");
		return 1;
	}
    if (i==2) {
    	write("You spit on " + per +".\n");
    	say(cap_name + " spits on " + per + ".\n", who);
    	tell_object(who, cap_name + " spits on you!\n");
    	return 1;
	}
    if (i==3) {
        write("You " + adv + " spit on " + per +".\n");
        say(cap_name + " " + adv + " spits on " + per + ".\n", who);
        tell_object(who, cap_name + " " + adv + " spits on you!\n");
        return 1;
    }
}
squeeze(str) {
string adv, per; object who; int i;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    i=pers_verb(str);
    if (i<2) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==2) {
    	write("You squeeze " + per + " fondly.\n");
    	say(cap_name + " squeezes " + per + " fondly.\n", who);
    	tell_object(who, cap_name + " squeezes you fondly.\n");
    	return 1;
	}
    if (i==3) {
        write("You " + adv + " squeeze " + per + ".\n");
        say(cap_name + " " + adv + " squeezes " + per + ".\n", who);
        tell_object(who, cap_name + " " + adv + " squeezes you.\n");
        return 1;
    }
}
sulk(str) {
string adv;
    if (ghost())
        return 0;
    if (!str) {
    write("You sulk in the corner.\n");
    say(cap_name + " sulks in the corner.\n");
    return 1;
    }
    adv=get_adv(str);
    if (!adv) {
	no_ab();
	return 1;
    }
    write("You " + adv + " sulk in the corner.\n");
    say(cap_name + " " + adv + " sulks in the corner.\n");
    return 1;
}
twiddle(str) {
string adv;
    if (ghost())
        return 0;
    if (!str) {
	write("You twiddle your thumbs.\n");
	say(cap_name + " twiddles " + his +
        " thumbs.\n");
	return 1;
    }
    adv=get_adv(str);
    if (!adv) {
	no_ab();
	return 1;
    }
    write("You " + adv + " twiddle your thumbs.\n");
    say(cap_name + " " + adv + " twiddles " + his + " thumbs.\n");
    return 1;
}
wiggle(str) {
string adv;
    if (ghost())
        return 0;
    if (!str) {
    write("You wiggle your bottom.\n");
    say(cap_name + " wiggles " + his +
        " bottom.\n");
    return 1;
    }
    adv=get_adv(str);
    if (!adv) {
	    no_ab();
	    return 1;
    }
    write("You " + adv + " wiggle your bottom.\n");
    say(cap_name + " " + adv + " wiggles " + his +
        " bottom.\n");
    return 1;
}



praise(str) {
object who;
	ghost();
	if (!str || lower_case(str)==MUDGOD) {
		who = find_living(MUDGOD);
		write("You praise the god of "+MUDNAME+", halleluja!\n");
		say(cap_name + " praises the god of "+MUDNAME+", halleluja!\n");
		if (who) tell_object(who, cap_name + " praises your name!\n");
		return 1;
	}
	who = present(lower_case(str), environment(this_player()));
	if (!who || !living(who) || (who==this_player())) {
		if (who==this_player() || (str=="me")) {
			write("You praise yourself.\n");
			say(cap_name + " praises " + this_player()->query_objective() +
			"self. Suddenly, the air smells foul.\n");
			return 1;
		}
		write("But " + capitalize(str) + " is not present!\n");
		return 1;
	}
	write("You praise " + capitalize(str) + ".\n");
	say(cap_name + " praises " + capitalize(str) + ".\n", who);
	tell_object(who, cap_name + " praises you! \n");
	return 1;
}

protest(str) { 
	ghost();
	if (!str) {
		write("You protest.\n");
		say(cap_name + " protests!\n");
		return 1;
	}
	write ("You protest " + str + ".\n");
	say(cap_name + " protests " + str + ".\n");
	return 1;
}

tog_frog(str) {
object who;
	ghost();
	if (!str) return 0;
	if (this_player()->query_level()<20)
		return 0;
	who = present(lower_case(str), environment(this_player()));
	if (!who || !living(who)) return 0;
	write("You make a magical guesture and throw a spell at " +
		capitalize(who->query_name()) + ".\n");
	tell_object(who, this_player()->query_name() +
		" makes a magical guesture and throws a spell at you!\n");
	say(this_player()->query_name() + " makes a magical guesture and "+
		"throws a spell at " + capitalize(who->query_name()) + "\n");
	if (who->query_frog()==1)
	{
		who->frog_curse(0);
		return 1;
	}
	else {
		who->frog_curse(1);
		return 1;
	}
}
	
scratch(str) {
	if (ghost()) {
		return 0;
	}
	if (frog()) {
		if (str=="head") {
			write("You try to reach your " + str +
				", but your thin, little, green arms are simply too short!\n");
			say(cap_name + " tries to scratch " + his
				+ " " + str + ", but fails.\n");
			say(capitalize(his) 
				+ " thin, little, green arms are simply too short!!\n");
			return 1;
		}
	}
	if (!str) {
		write("You scratch yourself, thinking.\n");
		say(cap_name + " scratches " + pron(me) + 
			"self, thinking.\n");
		return 1;
	}
	if (str=="head") {
		write("You scratch your " + str + ", thinking.\n");
		say(cap_name + " scratches " + his 
			+ " " + str + ", thinking.\n");
		return 1;
	}
    write("You scratch your " + str + ".\n");
    say(cap_name + " scratches " + his + " " + str + ".\n");
    return 1;
}

shake(str) {
object who, list;
string adv, per;
int i;
    if (ghost()) return 0;
    if(!str) {
        write("You're shaking in your boots.\n");
        say(cap_name + " shakes and quivers like a bowlful of jelly.\n");
        return 1;
    }
    if (str=="all") {
		list = users();
		for (i=0; i<sizeof(list);i++) {
			who = list[i];
			str=who->query_name();
			who = present(lower_case(str), environment(this_player()));
			if (who && living(who) && who!=this_player()) {
				write("You shake hands with " + who->query_name() +
				".\n");
				say(cap_name + " shakes hands with " + who->query_name() +
				".\n", who);
				tell_object(who, cap_name + " shakes your hand.\n");
			}
		}
	return 1;
    }
	i=pers_verb(str, " ");
	who=glob_who; per=glob_per; adv=glob_adv;
	if (i<2) return 0;
	if (i==2) {
    	write("You shake hands with " + per +".\n");
    	say(cap_name + " shakes hands with " + per + ".\n", who);
		tell_object(who, cap_name + " shakes your hand.\n");
		return 1;
	}
	if (i==3) {
		write("You " + adv + " shake hands with " + per + ".\n");
		say(cap_name + " " + adv + " shakes hands with " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " shakes your hand.\n");
		return 1;
	}
}


sing(str) {
    if (ghost())
	return 0;
	if (!str) {
		write("Oh sole mio!\n");
		say(cap_name + " sings in Italian.\n");
		return 1;
	}
	write("You sing: '" + capitalize(str) + "'.\n");
	say(cap_name + " sings: '" + capitalize(str) + "'.\n");
	return 1;
}


ignore(str) {
object who;
	ghost();
	if (!str) {
		write("You try to ignore all the present livings.\n");
		write("Come on, give them a chance!\n");
		say(cap_name + " is obviously ignoring all present livings.\n");
		return 1;
	}
	who = present(lower_case(str), environment(this_player()));
	if(!who  || !living(who) || who==this_player())
		return 0;
	write("You ignore " + capitalize(str) + ".\n");
	tell_object(who, cap_name + " ignores you!\n");
	say(cap_name + " obviously ignores " + capitalize(who->query_name()) +
		".\n", who);
	return 1;
}


look(str) {
int i;
string at;
    if(!str) return 0;
    if(sscanf(str, "at %s", at)==1) return 0;
    return(verb_adv_at_per(str));
}

mercy(str) {
object who;
	if (ghost()) return 0;
	if (!str) {
		write("You knee down in the dirt, squirm and beg for mercy.\n");
		say(cap_name + " knees down in the dirt, squirms and begs for mercy.\n");
		return 1;
	}
	who = present(lower_case(str), environment(me));
	if (!who || !living(who) || who==me) return 0;
	write("You knee down in the dirt, squirm and beg " + who->query_name()+
		" for mercy.\n");
	say(cap_name + " knees down in the dirt, squirms and begs " + 
		who->query_name() + " for mercy.\n", who);
	tell_object(who, cap_name + " knees down in the dirt, squirms and" + 
		" begs you for mercy.\n");
	return 1;
}

no(str) {
string adv, per; object who; int i;
	if (ghost()) {
		write("You shake your sheet in disagreement.\n");
		say(cap_name+" shakes "+his+" sheet in disagreement.\n");
		return 1;
	}
	if (frog()) {
		write("You try to shake your head in disagreement, but fail because of your\n");
		write("non-existing neck.\n");
		say(cap_name + " tries to shake "+his+
		  " head, but fails because of " + his+
		  "\nnon-existing neck.\n");
		return 1;
	}
	if (!str) {
	    write("You shake your head.\n");
	    say(cap_name + " shakes " + his + " head.\n");
 	    return 1;
	}
	i=pers_verb(str);
	if (i<1) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==1) {
	    write("You " + adv + " shake your head.\n");
	    say(cap_name + " " + adv + " shakes " + his + " head.\n");
	    return 1;
	}
	if (i==2) {
	    write("You look at " + per + " and shake your head.\n");
	    say(cap_name + " looks at " + per + " and shakes " 
		+ his + " head.\n", who);
	    tell_object(who, cap_name + " looks at you and shakes "
		+ his + " head.\n");
	    return 1;
	}
	if (i==3) {
	    write ("You look at " + per 
		+ " and shake your head " + adv + ".\n");
	    say(cap_name + " looks at " + per + " and shakes " + his 
		+ " head " + adv + ".\n", who);
	    tell_object(who, cap_name + " looks at you and shakes "
		+ his + " head " + adv + ".\n");
	    return 1;
	}
	return 0;
}
pale(str) {
	if (ghost())
	{
		write("But you are already!\n");
		say(cap_name + " tries to palen even more, without much success!.\n");
		return 1;
	}
	write("Your face turns as pale as ashes.\n");
	say(cap_name+"'s face turns as pale as ashes.\n");
	return 1;
}

pshout(str) {
object list,player;
string name;
int i;
        if (!str) {
            write("What do you want to shout?\n");
                return 1;
        }
	ghost();
        if (present("shout_curse", environment(this_object()))) {
                write("Your throat is sore. You only left off a crackle of a voice.\n");
                say(cap_name + " crackles with pain.\n");
                return 1;
        }

	if (this_player()->query_level()<20) {
		if (this_player()->query_spell_points()< 29) {
			write ("Sorry, too low on power.\n");
			return 1;
		}
		this_player()->restore_spell_points(-30);
	}
	list= users();
	write("You shout to all players: " + str + "\n");
	for (i= 0; i<sizeof(list); i++) {
		player=list[i];
		if (player->query_level() < 20 && player!=this_player())
		{
			tell_object(player, this_player()->query_name() +
			" shouts to all players: " + str + " \n");
		}
	}
	write("Done.\n");
	return 1;
}

wave(str) {
string adv, per; object who; int i;
	ghost();
	if (!str) {
		write("You wave farewell.\n");
		say(cap_name + " waves farewell.\n");
		return 1;
	}
    i = pers_verb(str);
    if (i<1) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==1) {
        write("You " + adv + " wave farewell.\n");
        say(cap_name + " " + adv + " waves farewell.\n");
        return 1;
    }
    if (i==2) {
		write("You wave farewell at " + capitalize(per) + ".\n");
		say(cap_name + " waves farewell at " + capitalize(per)
			+ ".\n", who);
		tell_object(who, cap_name + " waves farewell at you.\n");
		return 1;
	}
    if (i==3) {
        write("You " + adv + " wave farewell at " + capitalize(per) + ".\n");
        say(cap_name + " " + adv + " waves farewell at " 
			+ capitalize(per) + ".\n", who);
        tell_object(who, cap_name + " " + adv + " waves farewell at you.\n");
		return 1;
	}
	return 0;
}
		
wshout(str) {
object list, player;
string name;
int i;
	if (!str) {
	    write("What do you want to shout?\n");
		return 1;
	}
	ghost();
	if (present("shout_curse", environment(this_object()))) {
		write("Your throat is sore. You only left off a crackle of a voice.\n");
		say(cap_name + " crackles with pain.\n");
		return 1;
	}
	if (wshout_enable) { 
		write("No...you misused it too often.\n");
		return 1;
	}
	list= users();
	write("You shout to all wizards: " + str + "\n");
	for (i=0; i<sizeof(list); i++) {
		player=list[i];
		if (player->query_level() >19 && player!=this_player())
		{
		tell_object(player, this_player()->query_name() + 
			" shouts to all wizards: " + str + "\n");
		}
	}
	write("Done.\n");
	return 1;
}
relax() {
	if (ghost()) {
		write("Oh no! You crumbled your sheet!\n");
		say(cap_name + " the ghost wants to sit down and relax.\n" +
			"It crumbles his sheet!\n");
		return 1;
	}
	write("You sit comfortably down and relax.\n");
	say(cap_name + " sits comfortably down and relaxes.\n");
	return 1;
}

puzzle() {
	if (ghost()) return 0;
	write("You look puzzled.\n");
	say(cap_name + " looks puzzled.\n");
	return 1;
}


shame() {
	if (ghost()) return 0;
	write("You helplessly stumble some words of excuse. You are really ashamed.\n");
	say(cap_name + " helplessly stumbles some words of excuse. " + 
		capitalize(me->query_pronoun()) + " looks seriously ashamed.\n");
	return 1;
}


sweat() {
	if (ghost()) return 0;
	write("You sweat like a palatinian brook cow.\n");
	say(cap_name + " sweats like a palatinian brook cow.\n");
	return 1;
}

thank(str) {
object who, list;
string adv, per;
int i;
	if (!str) return 0;
	ghost();
	if (str=="all") {
		list = users();
		for (i=0; i<sizeof(list);i++) {
			who = list[i];
			str=who->query_name();
			who = present(lower_case(str), environment(this_player()));
			if (who && living(who) && who!=this_player()) {
				write("You thank " + who->query_name() +
				".\n");
				say(cap_name + " thanks "+ who->query_name() +
				".\n", who);
				tell_object(who, cap_name + " thanks you.\n");
			}
		}
		return 1;
    }
	i = pers_verb(str, " "); 
	if (i<2) return 0;
	adv=glob_adv; per=glob_per; who=glob_who;
	if (i==2) {
		write("You thank " + per + ".\n");
		say(cap_name + " thanks " + per + ".\n", who); 
		tell_object(who, cap_name + " thanks you.\n"); 
		return 1;
	}
	if (i==3) {
		write("You " + adv + " thank " + per + ".\n");
		say(cap_name + " " + adv + " thanks " + per + ".\n", who);
		tell_object(who, cap_name + " " + adv + " thanks you.\n");
		return 1;
	}
}

tickle(str) {
    object who;
    if (ghost()) return 0;
    if (frog()) {
	}
    if (!str) {
		write("Who do you want to tickle?\n");
		return 1;
	}
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
	return 0;
    write("You tickle " + capitalize(str) + " under " + 
		who->query_possessive() + " cheeks.\n");
		write(capitalize(str) + " tries to avoid, but giggles.\n");
	say(cap_name + " tickles " + capitalize(str) + " under " + 
		who->query_possessive() + " cheeks.\n", who);
	say(capitalize(str) + " tries to avoid, but starts giggling.\n", who);
	tell_object(who, cap_name + " tickles you under your cheeks!\n");
	tell_object(who, "You try to avoid, but start giggling.\n");
	return 1;
}
throat(str) {
string adv; int i;
	if (ghost()) {
		write("But you don't have a throat!\n");
		return 1;
	}
	if (!str) {
	    write("You clear your throat noisily.\n");
	    say(cap_name + " clears " + his + 
		" throat noisily.\n");
	    return 1;
	}
	i = pers_verb(str);
	if (i<1) return 0;
	adv = glob_adv;
	if (i==1) {
	    write("You clear your throat " + adv + ".\n");
	    say(cap_name + " clears " + his + " throat " + adv + ".\n");
	    return 1;
	}
	return 0;
}


wipe() {
	if (ghost()) return 0;
	if (frog()) {
		write("You try, but with your short, green and dumb little arms, you cannot reach\n");
		write("Your head.\n");
		say(cap_name + " tries to wipe the sweat from " + his + 
			" head, but " + his + 
			"\nshort, green and dumb little arms are too short.\n");
		return 1;
	}
	write("You wipe the sweat from your eyes.\n");
	say(cap_name + " wipes the sweat from " + his +
		" eyes.\n");
	return 1;
}

