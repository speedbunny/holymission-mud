#define NAME "brainsprain"
#define DEST "/players/brainsprain/workroom"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

inherit "room/room";

void reset(int arg) {

    ::reset(arg);

    if(arg) return;

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
  object brother, light;

#if 0
  light = clone_object("/obj/quest_obj");
  light->set_name("steal_light");
  light->set_hint(
           "Return Count Bismarck's powerful staff to him and you will\n"+
           "be rewarded.  This quest is fairly easy but will take some\n"+
           "true hack and slash and a bit of brains.\n");
  light->set_short_hint("Steal the Light from the Dark.");
  light->set_weight(20);
  light->set_killing(5);
  light->add_quest();
#endif

  brother = clone_object("/obj/quest_obj");
  brother->set_name("dwarven_brothers");
  brother->set_hint(
           "Prove to Thorin that his brother Thelgar is still alive.\n"+
           "This is a newbie quest but will take some real exploration\n"+
           "of the mud.  Thorin is picky and will only talk to those\n"+
           " that he thinks are dwarven.\n");
  brother->set_short_hint("Reunite the Dwarven Brothers.");
  brother->set_weight(10);
 brother->set_killing(1);
  brother->add_quest();
}
