inherit "obj/monster";
reset(arg) {
   object money;
   ::reset(arg);
   if(arg) return;
   set_name("villager");
   set_alt_name("the villager");
   set_alias("man");
   set_level(6);
   set_wc(8);
   set_ac(3);
   set_short("A villager");
   set_long(
   "The villager is dressed as you would expect a peasant to dress. He wears\n\
short torn trousers, and a torn rag for a shirt. They don't seem to help\n\
keep him any cooler, though, as his face is red, and sweat pours off his\n\
body. He is hard at work pulling weeds from around the crops.\n");
   set_al(350);
   set_gender(1);
   set_whimpy(1);
   set_aggressive(0);
   money = clone_object("/obj/money");
   money->set_money(random(25)+20);
   move_object(money, this_object());

   load_chat(9,({
   "\nThe villager says \"I wonder what Stanley is working on today?\"\n",
   "\nA loud noise comes from the trees, as if a large animal is moving quickly\n" +
   "through the forest. The villager jerks upright and stares bugeyed at the\n" +
   "trees, and starts backing fearfully towards the hamlet! Moments later, a\n" +
   "deer comes bounding out of the woods, and through the field. Visibly shaken,\n" +
   "the villager returns to his work, and is soon back into his rut.\n",
   "\nThe villager yawns.\n", 
   "\nThe villager leans back to stretch.\n",
   "\nThe villager tells you \"I keep forgetting what's planted here...\"\n",
   "\nThe villager tells you \"You missed some weeds, there.\"\n",
   "\nA boy comes, gives the villagers some water, and leaves back towards the hamlet.\n",
   "\nYou hear some excited chatter from some villagers down the field.\n",
   "\nThe villager sighs and rests a moment.\n",
   "\nSome field hands stumble towards the edge of the field carrying a big rock.\n",
   "\nThe villager asks you \"Come by to lend a hand?\"\n",
   "\nThe villager stands and looks at the sky, then resumes his work.\n",
   "\nThe villager finds a large rock in the soil. He calls some field hands\n" +
   "over to help remove it.\n",
   "\nThe villager jolts out of a daydream and checks to see if anyone noticed.\n",
   "\n   \"I sure hope the wizards of this land help US out someday!\"\n",
   "\n   \"Did Lord Charles ever find where the kobolds came from?\"\n",
   "\nThe villager looks longingly at the shade of the forest, but seems oddly\n" +
   "afraid of going anywhere near the trees.\n",
   "\nThe villager suddenly stands alert and studies the forest.\n",
   "\nThe villager stares angrily at the field. \"I hate farming!\"\n",
  }));
}

attack(arg)
   {
   int counter;
   counter=random(100);
   if(query_attack())
      {
      if(counter<10)
         {
         tell_room(environment(this_object()),
         "The villager shouts \"HELP!!\"\n" +
         "A man rushes in from the fields to see what the matter is.\n");
         move_object(clone_object("/players/stanley/mobs/man"),
           environment(this_object()));
         ::attack();
         }
      if(counter>90)
         {
         tell_room(environment(this_object()),
         "The villager throws a clump of dirt at you!\n");
         ::attack();
         } 
      }
   }
