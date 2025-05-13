#include "/sys/defs.h"

inherit "room/room";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_light(1);
  short_desc = "Kryll's cave";
  long_desc = 
    "Blah blah blah blah, blah blah blah blah.\n";
  dest_dir = ({
    "/room/church", "church",
    "/room/post", "post",
    "/room/adv_guild", "guild",
  });
  hidden_dir = ({
    "/players/kryll/castle", "castle",
  });
  property = ({ "no_teleport", "no_steal", "no_sneak" });
}
 
void init() {
  string ipnum;
  object herpob;
 
  ::init();
  if(TP->RNAME == "kryll") {
    ipnum = query_ip_number(TP);
    if( 0 && ipnum[0..2] != "208") {
      TELL(TP, "You are hacking into this character illegally.\n");
      TELL(TP, "This occurance has been logged.\n");
      log_file("mangla.rep", "Kryll hacker at " + ctime() +
               " from " + ipnum + "\n");
      if(herpob = find_player("herp")) {
        TELL(herpob, "ALERT: Someone just hacked into Kryll's character.\n");
        TELL(herpob, "ALERT: Occurance logged in /log/mangla.rep\n");
        TELL(herpob, "ALERT: This is not the first time.\n");
      }
      destruct(TP);
      return;
    }
  }
  add_action("tester", "tester");
}

status tester(string str) {
  object ob;

/*
  if(!str)
    return 0;
  if(file_size(str+".c") < 1) {
    write("Test what?\n");
    return 1;
  }
 
  ob = clone_object(str);
  if(ob) {
    ob->set_owner();
    ob->start();
    write("Ok.\n");
  }
*/
  return 1;
}
