#define NAME "emerald"
#define DEST "/players/emerald/workroom"

inherit "room/room";

void reset(int arg) {

    ::reset(arg);

    if(arg) return;

    "players/emerald/perilous/carriage"->xxx();
    set_light(1);

    short_desc="Castle of " + NAME;

    long_desc=
              "This is the "+short_desc+".\n"+
              NAME + " is a rather new wizard, but it is an amazing castle\n"+
              "just the same. However, the gates are closed.\n";
    items=({ 
            "castle","@@short",   /* we need that to get the 'castle' id */
          });
    move_object(this_object(), DEST);
}

init() {
    ::init();
    add_action("enter", "enter");
}

int enter(string str) {

    if (!id(str))
        return 0;
    write("It is not an open castle.\n");
    return 1;
}

void make_quest() {
  object gold;
  object soup;
  object lion;
  object sword;

  gold = clone_object("obj/quest_obj");
  gold->set_name("goldbar");
  gold->set_hint(
    "The king of the realm is facing a shortage in the treasury.  His solution\n"+
    "is therefore to add vast quantities of gold to it.  However, raising\n"+
    "taxes on a land of lead mines won't work.  Instead, he has designated\n"+
    "the town alchemist as the official gold maker.  But the alchemist so\n"+
    "far has not been able to figure out how it's done, and the patience\n"+
    "of the king is wearing a bit thin.  See if you can help Charles the\n"+
    "Alchemist turn lead into gold.\n");
  gold->set_short_hint("Turn lead into gold.");
  gold->set_weight(20);
  gold->set_killing(2);
  gold->add_quest();

  soup=clone_object("obj/quest_obj");
  soup->set_name("fishsoup");
  soup->set_hint(
    "The cook for the Druid Lakmir has died, leaving the Druid without a\n"+
    "supply of his favourite dinner, fish soup.  An advertisement has been\n"+
    "posted for the position, and if the Druid does not get his fish soup\n"+
    "soon, he has threatened to turn the whole mud into an oak tree!  See\n"+
    "if you can provide the Druid Lakmir with his dinner.\n");
  soup->set_short_hint("Make dinner for the Druid Lakmir.");
  soup->set_weight(20);
  soup->set_killing(2);
  soup->add_quest();

  lion=clone_object("obj/quest_obj");
  lion->set_name("lion");
  lion->set_hint(
    "The Prince of Lions wants the good king's head.  Get the head and \n"+
    "give it to the prince.\n");
  lion->set_short_hint("Get the good king's head.");
  lion->set_weight(20);
  lion->set_killing(4);
  lion->add_quest();

  sword=clone_object("obj/quest_obj");
  sword->set_name("dragon_slayer");
  sword->set_hint(
"Seek ye in the hot and cold lands the forging of the mighty Dragon Slayer!\n"
"Let your footsteps be guided to the master Smith.  Only he knows the secrets\n"
"which coax the forge to birth a Dragon Slayer.\n");
  sword->set_short_hint("Solve the Quest Perilous.");
  sword->set_weight(45);
  sword->set_killing(5);
  sword->add_quest();

}
