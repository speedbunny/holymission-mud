inherit "obj/treasure";

reset(arg) {
  set_id("sign");
  set_short("A HUGE SIGN--> READ SIGN");
  set_long("read this sign\n");
  set_read("\n"+
"This has to do with the GUILDS.\n"+
"It seems that every guild I goto has some player whining about how\n"+
"weak there guild has become. Personaly I have become fed up with it!\n"+
"ALL OF THE GUILDS ARE 10 TIMES MORE POWERFUL THAN THE ADVENTURER CLASS\n"+
"and 100 times more fun. The original idea for the guilds was to make\n"+
"making wizard more fun, add some spice and variaty to life. The LAST\n"+
"thing we want to do is make making wizard quicker and easier. Sure, we\n"+
"want to make it easier for you to kill monsters, etc. But we must\n"+
"balance that with keeping you in 'equality' with the adventurer class\n"+
"(with regards to time to make wizard)\n"+
"   So please people, lets stop all the complaining and just go have fun!\n"+
"\nIf people would like to change guilds:\nJust ask you're friendly wizard\n");
   set_value(0);
}

get() { return 0; }
