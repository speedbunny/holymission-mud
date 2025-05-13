#include "/include/defs.h"

main(arg) {
  int level, hoodlevel;
  object cloak;
  cloak = present("guildsoul", TP);
  hoodlevel =(cloak->query_hoodlevel());

  if(!cloak){
    notify_fail("You need a cloak to block people out.\n");
    return 0;
  }
  

  if(!arg) {
    if(!hoodlevel) {
      write("Your hood is not blocking anyone.\n");
      return 1;
    }
    write("Your hood is currently blocking players level " +
	  hoodlevel + " and below.\n");
    return 1;
  }
  if(sscanf(arg, "%d", level)) {
    if(level == 0) {
      if(hoodlevel) {
	TP->listen_shout(0);
	cloak->set_hoodlevel(0);;
	write("You take off your hood.\n");
	say(TP->SNAME + " pulls back " + TP->POS + " hood.\n");
	return 1;
      }
      write("Your hood is already off.\n");
      return 1;
    }
    if(level <= TP->LEVEL && level >= 1) {
      TP->listen_shout(level);
      write("You set your hood strength to " + level + ".\n");
      if(!hoodlevel)
	say(TP->SNAME + " pulls " + TP->POS + " black hood over " +
	    TP->POS + " head, covering " + TP->POS + " face in shadow.\n");
      cloak->set_hoodlevel(level);
      return 1;
    }
    write("You cannot block out that level.\n");
    return 1;
  }
  write("Syntax: hood <level>\n");
  return 1;
}
