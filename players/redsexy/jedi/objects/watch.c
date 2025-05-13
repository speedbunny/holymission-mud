inherit "/obj/armour";

#include "lw.h"
#include "/players/matt/defs.h"

#define TICK "/obj/tick"

drop(arg) {
  if(!arg) {
    write("The sundial is very upset at your action and stomps off to find a new owner\n");
    say(TP->NAME + " sighs" + " as " + TP->POS + " sundial walks off in a huff declaring it doesn't like its owner!\n");
  }
  destruct(TO);
  return 1;
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sundial");
  set_alias("watch");
  set_short("A wrist-worn sundial");
  set_long("This red sundial makes you feel sexy when you wear it! Commands are:\n\n" +
           "- reboot\n" + 
           "  Shows you time left until reboot\n\n" 
           "- central, eastern, mountain, pacific (timezones) \n" +
           "- holland, slovaki, hungary, uk, oz   (countries) \n\n" +
           "  Shows you the time in that country or timezone\n\n"
           );
  set_type("sundial");
  set_ac(0);
  set_weight(1);
  set_value(100);
}


init() {
  ::init();
  if(!living(ENV(TO))) destruct(TO);
  worn = 1;
  worn_by = TP;
  add_action("show_reboot", "reboot");
  add_action("show_linztime", "austria");
  add_action("show_uktime", "uk");
  add_action("show_cttime","central");
  add_action("show_ettime","eastern");
  add_action("show_mttime","mountain");
  add_action("show_pctime","pacific");
  add_action("show_dutime","holland");
  add_action("show_sltime","slovaki");
  add_action("show_hutime","hungary");
  add_action("show_oztime","oz");

}

show_reboot(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
    say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    return TICK->qry_timer();
  }
}

show_linztime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The time in Austria is " + ctime(time()) + ".\n");
    return 1;
  }
}


show_uktime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The time in the UK is " + ctime(time()-3600) + ".\n");
    return 1;
  }
}

show_cttime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The Central time is " + ctime(time()-25200) + ".\n");
    return 1;
  }
}

show_ettime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The Eastern time is " + ctime(time()-21600) + ".\n");
    return 1;
  }
}

show_mttime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The Mountain time is " + ctime(time()-28800) + ".\n");
    return 1;
  }
}

show_pctime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The Pacific time is " + ctime(time()-32400) + ".\n");
    return 1;
  }
}

show_dutime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The time in Holland is " + ctime(time()) + ".\n");
    return 1;
  }
}

show_sltime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The time in Slovaki is " + ctime(time()) + ".\n");
    return 1;
  }
}


show_hutime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The time in Hungary is " + ctime(time()) + ".\n");
    return 1;
  }
}

show_oztime(arg) {
  if(!arg) {
    write("You look at your sundial.\n");
 say(TP->NAME + " looks at " + TP->POS + " sundial.\n");
    write("The time in Australia (NTP) is " + ctime(time()+36000) + ".\n");
    return 1;
  }
}



