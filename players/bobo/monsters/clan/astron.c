inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("astronomer");
   set_level(15);
   set_wc(20);
   set_ac(6);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Astronomer");
   set_long("This man is pouring over a large stone tablet, and seems to\n"+
            "be making calculations of some sort.  He is wearing light\n"+
            "clothing and a metal headband.\n");
   load_chat(6,({
      "The astronomer says: Yes, yes I see now.",
      "The astronomer says: You see this here, yes...",
      "The astronomer says: The black bird is an omen.",
      "The astronomer says: The world is going to end, we're all going to die."
   }));
}
