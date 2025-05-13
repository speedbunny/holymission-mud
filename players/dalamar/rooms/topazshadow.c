#define FP find_player("topaz")

set_shadow() {
	shadow(FP,1);
}

query_presentation() {
	string name;
    if(query_idle(find_player("topaz"))>120) return "Unfortunately for you, Topaz is idle.";

        switch(random(40)) {
		case 0:
      return "Try our new Topaz flavored ice cream!";
		case 1:
      return "Boy!  Topaz can sure change these titles fast!";
		case 2:
      return "The corpse of Topaz is in your soup!";
		case 3:
      return "There's no cure for Topaz!";
		case 4:
			name=capitalize(this_player()->query_real_name());
      return "Topaz shouts: "+name+"!  Having fun yet?";
		case 5:
      return "TopazTopazTopazTopazTopazTopaz";
		case 6:
      return "Don't you wish Topaz would grow up?";
		case 7:
      return "Topaz the titleless";
		case 8:
      return "Topaz is right.  You're wrong.  Deal with it!";
		case 9:
      return "Whose name was here?  *scratch your head*";
		case 10:
      return "I'm glad Topaz isn't around!";
    case 11:
      return "Coming soon:  Topaz2 - The sequel!!";
    case 12:
      return "Topaz isn't wearing any underwear!";
    case 13:
      return "Let's see...Who should Topaz dest today?";
    case 14:
      name=capitalize(this_player()->query_real_name());
      return "Topaz says: I'm not gonna play anymore until "+name+" leaves!";
    case 15:
      return "Have no fear!  Topaz is here!";
    case 16:
      return "Great!  First: I flunk biology.  Now: I have to put up with Topaz!";
    case 17:
      return "ToPaZ";
    case 18:
      return "Topaz is following you!";
    case 19:
      name=capitalize(this_player()->query_real_name());
      return "When did "+name+" wiz?!?";
    case 20:
      name=capitalize(this_player()->query_real_name());
      return "Topaz\n" +
             "We interrupt your regularly scheduled who listing to\n" +
             "bring you this important news flash:\n" +
             "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" +
             name+" has just escaped from an Interpol Maximum Security prison!\n" +
             "Any information leading to the capture of this dangerous\n" +
             "criminal will be rewarded greatly.  Your help in this\n" +
             "matter will be much appreciated.  Thank you.\n" +
             "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" +
             "We now return you to your regularly scheduled who list.\n";
    case 21:
      return "T O P A Z !";
    case 22:
      return "Many thanks to Portil for letting me use this file!";
    case 23:
      return "Who the heck is this Topaz guy anyway?!?";
    case 24:
      return "Well, at least I still have Topaz to kick around.";
    case 25:
      return "If you'd like Topaz to send out a ballot, tell him!  :)";
    case 26:
      return "Hopefully someday Topaz will be [Wiz]!  :)";
    case 27:
      return "See that rock over there?  Well, Topaz is dumber than it is!";
    case 28:
      return "The crowd chants: TOPAZ!  YOU'RE OUR HERO!!";
    case 29:
      return "Topaz kisses, er, kicks butt!  *grin*";
    case 30:
      return "And now: The Wonderful, the Awesome, the Remarkable, um, what was his name?";
    case 31:
      name=capitalize(this_player()->query_real_name());
      return "Topaz tells you: Are you *THE* " + name + "?!?  The one everyone's\n" +
             "talking about?!?";
    case 32:
      return "Topaz is spreading nasty rumours about you!";
    case 33:
      return "There's only one Topaz!  (Thank goodness!)";
    case 34:
      return "Waiter!  There's a Topaz in my soup!!";
    case 35:
      return "That's *MR.* Topaz to you!";
    case 36:
      return "Forget it!  Topaz wouldn't let you do that!";
    case 37:
      return "Ha!  Caught you cheating!  (Make you nervous?)  :)";
    case 38:
      return "T\n" +
             " O\n" +
             "  P\n" +
             "   A\n" +
             "    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ!!!!!!!!!!";
    case 39:
      return "You're lucky Topaz can't type.  He just tried to dest you!!";
	}
}
