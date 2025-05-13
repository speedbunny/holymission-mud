inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling child");
   set_alias("child");
   set_level(3);
   set_wc(6);
   set_ac(1);
   set_al(25);
   set_gender(1);
   set_race("halfling");
   set_short("Child");
   set_long("The child sitting in front of you is especially dirty.  He\n"+
            "seems to be covered in dirt and grime.");
   add_money(10);
   load_chat(5,({
      "The child says: I don't like the nursery.\n",
      "The child says: The people in the nursery beat me.\n",
      "The child says: I like to play in the dirt.\n"
   }) );
}

