inherit "obj/thing.c";

#pragma strict_types

void reset(int arg)
  {
  ::reset(arg);
  if (arg) return;
  set_name("advertisement");
  set_alias("ad");
  set_short("An advertisement");
  set_long("An advertisement for Nokey's centralroom.\n"+
           "You guess you should read it.\n");
  set_weight(0);
  set_read(
  "For the sake of friendship and fun I am offering all you wizards\n"+
  "an easy way to connect to many many other workrooms. The idea is\n"+
  "to put a central inbetween all workrooms. So your workroom will\n"+
  "only need one exit to the centralroom to go to a range of other\n"+
  "wizards workrooms. And it's incredibly easy to make this work too!\n"+
  "All you need is the following function added to your workroom:\n"+
  "int connected_to_center() { return 1; }\n"+
  "And you need an exit in your dest_dir going to:\n"+
  "\"/players/nokey/centralroom\"\n"+
  "Pretty easy to do eh?\n"+
  "After you have entered this into the code of your workroom and\n"+
  "updated it, go to the centralroom and 'press reset' there.\n"+
  "This will put your workroom in the exits as well.\n"+
  "\nHave fun with it ;-)    No Key.\n"+
  "P.S. This ad will self destruct when dropped.\n"
  );
  }

void autodest()
  {
  write("The note vanishes in a bright flash of magic!\n");
  say("The note vanishes in a bright flash of magic!\n");
  destruct(this_object());
  }

int drop()
  {
  call_out("autodest",0);
  return 0;
  }
