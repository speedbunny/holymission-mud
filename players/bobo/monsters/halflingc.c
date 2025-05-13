inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling child");
   set_alias("child");
   set_alt_name("boy");
   set_level(3);
   set_wc(6);
   set_ac(1);
   set_al(20);
   set_gender(1);
   set_race("halfling");
   set_short("Child");
   set_long("The little halfling is very dirty.  He is scurrying about\n"+
            "the room attempting to hide things.\n");
   add_money(10);
   load_chat(8,({
      "The child says:  I like playing here, it's nice and quiet.\n",
      "The child says: Sometimes my daddy works on the new tunnel.\n"
   }) );
}

