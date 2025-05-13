/*
 * This code was copied from Tubmud. Thanks a lot, Macbeth !
 *
 */


/* A new room for more orderly wizconfs...  Origin: unknown. Pell 91-07-12 */

#define GOD	"herp"
#define CGOD	"Herp"
#define TP this_player()
#define TPQRN this_player()->query_real_name()

inherit "room/room";

string banner;

reset(arg)
{
  if (arg) return;
    
/*
 * Replace this banner with something more interesting. I was originally
 * thinking of adding the ability to set the banner through a wizard
 * action, but it's too much hassle with save_object()...
 */

  banner = "Welcome to the new souped-up wizconf!";

  set_light(1);
  short_desc = "Conference room";
  no_castle_flag = 1;
  items = ({"throne", "foo"});	/* Just for the id()'s sake */
#if 0
  dest_dir = ({"room/wizclub", "club",
#endif
  dest_dir = ({"room/adv_guild", "guild",
	       "room/adv_inner", "inner",
	       "players/calidor/others/board/wiz", "flame"});
}

long(arg)			/* Override standard long() */
{     
  if (arg == "throne") {
    write("The throne is made of black marble and is large and imposing.\n");
    if (TPQRN == GOD)
      write("As you can feel, it is remarkably comfortable.\n");
    else if (present(GOD))
      write(CGOD+" is slouched back on it, in his usual relaxed posture.\n");
    else
      write("It is made for "+CGOD+" super high lord turbo power overgod.\n");
  }
  else
    write(
"This is the Wizard Conference room. The walls are made of black obsidian\n"+
"and the ceiling provides a blue, soft light.\n"+
"The room is furnished with tables made of glass, arranged in a big circle.\n"+
"In the middle of the room a black marble throne is located for "+CGOD+",\n"+
"the god of the Holy Mission.\n    ===> help wizconf <===  describes available commands.\n"+
"A banner streches through the room. It reads:\n"+ banner + "\n"+
"    There are three very obvious exits: guild, inner and flame.\n");
}

init()
{
  /* Add default action first, so the room actions can override */
  add_action("parsecommand", "", 1);
  ::init();			/* Setup room actions */
}

parsecommand(args) {
  string verb;

  verb = query_verb();

  if (verb == "help" && args == "wizconf") {
    if (TPQRN == GOD)
      write(
"Hi, "+CGOD+"! B-) You can do anything here of course. Use 'get word'\n"+
"to get the Word. This is what normal wizards get as help message:\n\n");

    write(
"You will find lots of normal feelings, emotions, etc, disabled as long\n"+
"as you don't have the Word. Don't try to override this; it is very simple\n"+
"and you should view this as a strong hint that the person with the Word\n"+
"should be able to speak uninterrupted.  These are the special commands:\n\n"+
"word           Tells "+CGOD+" that you want to speak.\n"+
"get word       Tells "+CGOD+" that you want to speak.\n"+
"return         Returns the word to "+CGOD+".\n"+
"agree          Says '<your name> agrees.'\n"+
"agree <name>   Says '<your name> agrees with <name>.'\n"+
"                 Might be good if the connection is very slow...\n"+
"disagree       See 'agree'. Be careful with its usage!\n"+
"yes, no        Synonyms to 'agree' and 'disagree' respectively.\n");
    return 1;
  }				/* if 'help wizconf' */

  if (TPQRN == GOD) {	/* Parse special God-stuff now */
    string who;

    if (verb == "give" && args && sscanf(args, "word to %s", who) == 1) {
      if (present("the word of speech", TP)) {
	if (present(lower_case(who))) {
	  move_object(present("the word of speech", TP),
		      present(lower_case(who)));
	  write("Ok.\n");
	  say(capitalize(who) + " has the Word.\n");
	}
	else
	  write(capitalize(who) + " doesn't seem to be present.\n");
      }
      else
	write("But you don't have the word! Use 'get word' to get it.\n");
      return 1;
    }
	
    if (verb == "get" && args == "word") {
      int got; object i, word;

      got = 0;
      i = first_inventory(this_object());
      while (i) {
	if (i == TP) {		/* This is Herp! */
	  i = next_inventory(i);
	  continue;
	}
	/* No need to do a special check for players-only */
	word = present("the word of speech", i);
	if (word) {
	  if (got)		/* Hmmm... more words in circulation */
	    destruct(word);
	  else {
	    got = 1;
	    move_object(word, TP);
	    say(CGOD +" has the Word.\n");
	  }
	}
	i = next_inventory(i);
      }				/* while */

      if (!got)			/* Hm, noone had it... */
	move_object(clone_object("obj/wizconfword"), TP);
      /* I could have made some protection against cloning by others
	 than Herp, but Herp has the "get word" command which destructs
	 all Words found, save one */

      return 1;
    }
    return 0;			/* Herp can do anything */
  }

  if (TP->query_level () >= 100)	/* Elders and above cad do anything too */
     return 0;

  if (verb == "word" || (verb == "get" && args == "word")) {
    write("You ask for the favour to speak.\n");
    say(capitalize(TPQRN) + " would like to speak.\n");
    return 1;
  }

  if (verb == "return") {	/* 'return word' works too of course */
    object god;
    
    if (present("the word of speech", TP)) {
      god = present(GOD);
      if (god) {
	move_object(present("the word of speech", TP), god);
	write("You return the Word to "+CGOD+".\n");
	say(capitalize(TPQRN) + " returns the Word to "+CGOD+".\n");
      }
      else
	write("Strange, but "+CGOD+" isn't present. You keep the Word.\n");
    }
    else
      write("But you don't have it!\n");
    return 1;
  }

  if (verb == "agree" || verb == "yes") {
    /* Yes, I know. args can be a sentence. We'll see how folks use this */
    if (args && find_player(args)) {
      write("You agree with " + args + ".\n");
      say(capitalize(TPQRN) + " agrees with " + args + ".\n");
    }
    else {
      write("You agree.\n");
      say(capitalize(TPQRN) + " agrees.\n");
    }
    return 1;
  }

  if (verb == "disagree" || verb == "no") {
    /* Yes, I know. args can be a sentence. We'll see how folks use this */
    if (args && find_player(args)) {
      write("You disagree with " + args + ".\n");
      say(capitalize(TPQRN) + " disagrees with " + args + ".\n");
    }
    else {
      write("You disagree.\n");
      say(capitalize(TPQRN) + " disagrees.\n");
    }
    return 1;
  }

  if (present("the word of speech", TP)) { /* Check for special actions */

/*
 * If the wizard has the Word, s/he should be able to use normal
 * emotions to augment the speech.
 */
    return 0;
  }

/* Allow these actions */

  if (verb == "goto" || verb == "trans" || verb == "tell" || verb == "home" ||
      verb == "earmuffs" || verb == "vis" || verb == "people" ||
      verb == "wizlist" || verb == "localcmd" || verb == "more" ||
      verb == "who" || verb == "bug" || verb == "typo" || verb == "idea" ||
      verb == "help" || verb == "exa" || verb == "examine" || verb == "look" ||
      verb == "i" || verb == "inventory" || verb == "quit") return 0;

/* If we have come this far, the wizard tries a command we don't like */

  write(
    "That action is unavailable here. Use 'get word' if you want to speak\n"+
    "or 'help wizconf' for a list of special commands.\n");
  return 1;
}
