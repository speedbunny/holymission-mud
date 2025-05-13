#include "/players/waldo/defs.h"

inherit "obj/treasure";
string target;

reset(arg)
{
::reset(arg);
	if(arg)
		return;
	set_name("bear");
	set_alt_name("bear");
	set_alias("bear");
	set_short("A big teddy bear");
	set_long(    "  ___  \n"+
	    "{~._.~}\n"+
	    " ( Y ) \n"+
	    "()~*~()\n"+
	    "(_)-(_)\n\n"+
	    "A teddy bear, with button eyes.\n"+
	    "Use <bhelp> to get help with the bear.\n");
}

drop()
{
	TELLRM(environment(this_player()),
	    "The teddy bear screams in agony as it rolls around on the ground.\n"+
	    "A panthean of Gods appear in a cloud of smoke and a flash of light.\n"+
	    "They boom: 'Come here fella'. The bear jumps into their custody\n"+
	    "and is swiftly whisked away from further harm.\n"+
	    "The Gods depart in a solemn fashion.\n");
	destruct(TO);
	return 1;
}

init()
{
::init();
	AA("bear_help","bhelp");
        AA("bear_hug","bhug");
	AA("bear_send","bsend");
	AA("bear_mood","bood");
}

bear_help()
{
	write ("The Ultimate teddy bear help\n"+
	    "----------------------------\n\n"+
	    "bhelp          - This little helper page\n"+
	    "bsend <player> - Send the bear to <player>\n"+
	    "bhug           - Hug the teddy bear\n"+
	    "bood <mode>    - Changes the teddy's mood\n"+
	    "go home        - Sends the bear away\n"+
	    "\n");
	return 1;
}

bear_hug()
{
  write("You hug the bear!\n");
  write("The bear sends you a mental picture....\n"+
        "   ___                          ___   \n"+
        " {~._.~}   I'm a teddy bear   {~._.~} \n"+
        "  ( Y )     You just gotta     ( Y )  \n"+
        " ()~*~()        love me       ()~*~() \n"+
        " (_)-(_)                      (_)-(_) \n"
        );
  return 1;
  }

bear_send(str)
{
	object nextperson;
	if(!str)
	{
		write("Your bear looks confused!\n");
		return 1;
	}
	if (!find_player(str))
	{
		write("Teddy tells you: No such player.\n");
		return 1;
	}
	nextperson=find_living(str);
	write("You send the bear to "+nextperson->QNAME+".\n");
	TELL(nextperson,TPQN+" sends a teddy bear to you.\n");
	MOVE(TO,nextperson);
	return 1;
}

bear_mood(str)
{
	if (!str)
	{
		write("Please enter a mood:-\n");
		write("dead , sleeping , tired \n");
		write("normal or drunk\n");
		return 1;
	}

	switch(str)
	{
          case "dead" :
                write("Bear's mood changed to : dead\n");
		set_long ( "  ___   \n"+
		    "{~+_+~}   Your teddy bear is\n"+
		    " ( Y )    looking like he\n"+
		    "()~*~()   is no longer in the\n"+
		    "(_)-(_)   land of the living!\n\n"+
		    "A teddy bear, with button eyes.\n"+
		    "Use <bhelp> to get help with the bear.\n");
		break;

	  case "sleeping" :
                write("Bear's mood changed to : sleeping\n");
		set_long(  "  ___   \n"+
		    "{~___~}   Your teddy bear is\n"+
		    " ( Y )    looking like he is\n"+
		    "()~*~()   having a nice sleep.\n"+
		    "(_)-(_)   Maybe you shouldn't wake him.\n\n"+
		    "A teddy bear, with button eyes.\n"+
		    "Use <bhelp> to get help with the bear.\n");
		break;

	  case "tired" :
                write("Bear's mood changed to : tired\n");
		set_long(  "  ___   \n"+
		    "{~p_q~}   Your teddy bear is\n"+
		    " ( Y )    looking quite tired and\n"+
		    "()~*~()   is about to fall into a\n"+
		    "(_)-(_)   deep and dreamless sleep.\n\n"+
		    "A teddy bear, with button eyes.\n"+
		    "Use <bhelp> to get help with the bear.\n");
		break;

	  case "drunk" :
                write("Bear's mood changed to : drunk\n");
		set_long(  "  ___   \n"+
		    "{~x_x~}   Your teddy bear is\n"+
		    " ( Y )    as pissed as a newt.\n"+
		    "()~*~()   You better pray that\n"+
		    "(_)-(_)   he doesnt lose his stomach.\n\n"+
		    "A teddy bear, with button eyes.\n"+
		    "Use <bhelp> to get help with the bear.\n");
		break;
	
	  default :
                write("Bear's mood changed to : normal\n");
		set_long(  "  ___  \n"+
		    "{~._.~}\n"+
		    " ( Y ) \n"+
		    "()~*~()\n"+
		    "(_)-(_)\n\n"+
		    "A teddy bear, with button eyes.\n"+
		    "Use <bhelp> to get help with the bear.\n");
		break;
	} // end switch
	return 1;
}
// end of newbear.c
