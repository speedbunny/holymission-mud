inherit "obj/monster";

string chat_str, function, type, match;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  if(!chat_str) {
    chat_str = allocate(2);
    chat_str[0] = "The Frost Giant Prisoner moans.\n";
    chat_str[1] = "Frost Giant Prisoner says: Will you help me?\n";
    function = allocate(2);
    type = allocate(2);
    match = allocate(2);
    function[0] = "say_hello";
    type[0] = "arrives";
    function[1] = "help_me";
    type[1] = "says:";
  }
  set_name("frost giant prisoner");
  set_alias("prisoner");
  set_short("Frost Giant Prisoner");
  set_race("giant");
  set_long("This Frost Giant looks dirty and dispirited.\n");
  set_level(15);
  set_ac(2);
  set_hp(350);
  set_wc(25);
  set_al(-350);
  load_chat(15, chat_str);
  set_match(this_object(),function,type,match);
}

say_hello(str) {
 string who;
 if(sscanf(str, "%s arrives.",who) == 1) {
   say("Frost Giant says: At last!!!\n");
   say("Frost Giant says: "+who+" can you help me? If you do I will give\n");
   say("                   you something......Yes?\n");
   return 1;
 }
}

help_me(str) {
  string who, junk;
  sscanf(str,"%s says:%s",who,junk);
  if(who != "Frost Giant Prisoner") {
    say("Frost Giant says: Good. You must first open my shackles, "+who+"\n");
    return 1;
  }
}
