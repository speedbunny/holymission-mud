inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling child");
   set_alias("child");
   set_alt_name("girl");
   set_level(3);
   set_al(100);
   set_gender(2);
   set_race("halfling");
   set_short("Child");
   set_long("This poor little halfling girl has obviously been crying a\n"+
            "long time.  Her eyes are red and swollen.\n");
   add_money(10);
   load_chat(3,({
      "The girl screams and cries very loudly.\n",
      "The girl bawls: Have you seen my doll?\n",
      "The girl shrieks: Where's my dolly?\n",
      "The girl yells: I want my dolly!\n"
   }) );
}

