inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("father");
   set_level(4);
   set_ac(1);
   set_wc(7);
   set_al(50);
   set_gender(1);
   set_race("human");
   set_short("Father");
   set_long("This poor man has lost his litle boy in the scare.  He is\n"+
            "searching desperately for his son and enlisting all the help\n"+
            "he can.\n");
   add_money(75);
   load_chat(3,({
      "The man says:  Have you seen my son?\n",
      "The man says: I'm looking for my little boy.\n",
      "The man says: Will you help me find my son?\n",
   }) );
}

