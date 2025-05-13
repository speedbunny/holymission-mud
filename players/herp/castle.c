reset(arg) {
   if (arg) return;

   /* Load autoloading objects */
/*
   "players/herp/obj/cleaner"->reset();
   "players/herp/obj/ohrring"->reset();
   "players/herp/obj/notify"->reset();
*/
   "players/herp/workroom"->reset();
}
 
make_quest() {
   object ob;

   /* Set up the "Quest" */

   ob=clone_object("obj/quest_obj");
   ob->set_name("ask_god");
   ob->set_hint("Get the Mud God to sponsor you.\n");
   ob->set_short_hint("Get a sponsor");
   ob->set_compulsory(1);
   ob->set_creator("Root");
   ob->add_quest();

   /* Quest: The abbey of the Rose */

   ob=clone_object("obj/quest_obj");
   ob->set_name("abbey");
   ob->set_short_hint("Help the master of the Abbey of the Rose");
   ob->set_weight(20);
   ob->set_killing(5);
   ob->set_hint(
"In an abbey not far from the town, the monks there keep dying.\n"+
"The master is in despair, all his very best and well-educated followers\n"+
"died one after another. He can't help himself, and needs the clear mind and\n"+
"brilliant intellectual power of a witted adventurer.\n");
   ob->add_quest();
}
