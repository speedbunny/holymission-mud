#include "lw.h"

inherit "obj/weapon";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("sightblinder");
    set_alias("spear");
    set_alt_name("vagweap");
    set_short("Sightblinder the Mighty Spear");
    set_long(
      "Sightblinder is a beautiful weapon with a burnished steel shaft and\n"+
      "a razorsharp speartip. The spear's balance is incredible and it\n"+
      "vibrates, as though in expectation of vanquishing foes. A tiny\n"+
      "note is attached which reads: return sightblinder to store me with\n"+
      "Justice.\n");
    set_weight(3);
    set_class(16);
    set_value(5000);
}

int drop(){
    write("You do not want to drop Sightblinder.\n");
    return 1;
}

void init(){
    ::init();
    add_action("dest_me", "return");
}

status dest_me(string str){
    if(id(str)){
	write("You return Sightblinder to Justice for storage.\n");
	destruct(this_object());
	return 1;
    }
}

string* query_hit_msg(int dam, string name, string att, string def){
    if(dam<1) return ({
	  lw("thrusts mightily with Sightblinder but hit nothing except air."),
	  lw("thrusts mightily with Sightblinder but missess you."),
	  lw("thrusts mightily with Sightblinder at empty air."),
	});
    else if(dam<2) return ({
	  lw("thrust Sightblinder at "+name+", glancing "+
	    name+"."),
	  lw("thrusts Sightblinder at you, glancing you."),
	  lw("thrusts Sightblinder at "+name+", making a glancing hit on "+
	    name+"."),
	});
    else if(dam < 4 ) return ({
	  lw("swing the butt of Sightblinder into "+name+"'s midsection, "+
	    name+" doubles over gasping for air."),
	  lw("swings the butt of Sightblinder into your midsection. "+
	    "You double over gasping for air."),
	  lw("swings the butt of Sightblinder into "+name+"'s midsection, "+
	    name+" doubles over gasping for air."),
	});
    else if (dam < 9) return ({
	  lw("jab Sightblinder into "+name+" and twist it, "+name+" screams "+
	    "in agony."),
	  lw("jabs Sightblinder into you and twists it. You scream in agony."),
	  lw("jabs Sightblinder into "+name+" and twists it, "+name+
	    " screams in agony."),
	});
    else if(dam < 14) return ({
	  lw("stab "+name+" with Sightblinder and follow it up with a strong kick."),
	  lw("stabs you with Sightblinder and follows it up with a strong kick."),
	  lw("stabs "+name+" with Sightblinder and follows it up with a strong kick."),
	});
    else if(dam < 19) return ({
	  lw("stab deeply into "+name+"'s internal organs and make julienne of them."),
	  lw("stabs deeply into your internal organs and makes julienne of them."),
	  lw("stabs deeply into "+name+"'s internal organs and makes "+
	    "julienne of them."),
	});
    else if (dam < 29) return ({
	  lw("go into a frenzy and dice "+name+" into small cubes."),
	  lw("goes into a frenzy and dices you into small cubes."),
	  lw("goes into a frenzy and dices "+name+" into small cubes."),
	});
    else if (dam < 29) return ({
	  lw("run Sightblinder through "+name+" and disembowel "+
	    name+"."),
	  lw("runs Sightblinder through "+name+" and disembowels "+
	    "you."),
	  lw("runs Sightblinder through "+name+", disemboweling "+
	    name+"."),
	});
    else return ({
	  lw("watch as Sightblinder draws power from Time and Space before "+
	    "obliterating large chunks from "+name+"!"),
	  lw("watch as Sightblinder draws power from Time and Space before "+
	    "obliterating large chunks from your body!"),
	  lw("watch as Sightblinder draws power from Time and Space before "+
	    "obliterating large chunks from "+name+"!"),
	});
}
