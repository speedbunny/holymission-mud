inherit "obj/monster";
reset(arg) {
   ::reset(arg);
   set_alt_name("a dog");
   set_name("dog");
   set_alias("the dog");
   set_level(1);
   set_gender(1);
   set_move_at_reset();
   set_whimpy(1);
   set_wc(7);
   set_ac(2);
   set_short("A thin brown dog");
   set_long( 
   "A thin brown dog with it's ribs showing. It slobbers happily at you.\nThe dog wags it's tail at your attention.\n");
   set_al(50);
   set_aggressive(0);

  load_chat(7,({
   "The dog looks at you and wags it's tail.\n",
   "The dog slobbers on you.\n",
   "\n\t\"Woof!\"\n",
  }));
}

init(arg) {
   ::init();
   add_action("pet","pet");
}

pet(str) {
   if(!str) {
      write("Pet what?\n");
      return 1;
   }
   if(str=="dog") {
      write("The dog's tail goes into overdrive!\n");
      return 1;
   }
   return 0;
}
