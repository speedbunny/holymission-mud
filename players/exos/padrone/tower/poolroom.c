/* Ethereal Cashimor, 190393, updated to room/room, changed to medieval times
   and edited one typo */
inherit "room/room";
#include "/obj/lw.h"

object mermaid, guard, weapon;
object murderer;
status wait;

/* For the NEW, IMPROVED monster class: */
string chat_str, a_chat_str;

init() {
  ::init();
  add_action("enter", "enter");
  add_action("dive", "dive");
}

extra_long(str) {
    if ((str == "pool") || (str == "swimming pool")) {
	write("The pool looks surprisingly deep.\n");
	return 1;
    }
    else
	return 0;
}

reset(arg) {
  if(!arg) {
    items=({"pool","The pool looks surprisingly deep",
            "swimming pool","The pool looks surprisingly deep",
            "walls","They are covered with interesting tiles",
            "tiles","The designs are abstract, but beautiful"});
    set_light(1);
    dest_dir=({"players/padrone/tower/hall","east",
               "players/padrone/tower/bedroom","southeast"});
    short_desc="Pool room";
    long_desc="You are in a room with a small swimming pool. The walls are "
            + "covered with exquisite tiles, and the water in the beautiful "
            + "little pool glitters softly green. This room seems far away "
            + "from the evil and violence in the world, and probably the "
            + "Wizard himself comes here to relax when he has time.\n";
    smell="The place smells of fresh water.";
  }
  if (!mermaid) {
    mermaid = clone_object("obj/monster");	
    /* NEW, IMPROVED monster class! */
    mermaid->set_name("mermaid");
    mermaid->set_race("mermaid");
    mermaid->set_level(1);
    mermaid->set_female();
    mermaid->set_hp(40);
    mermaid->set_wc(1);
    mermaid->set_al(600);
    mermaid->set_short("A cute little mermaid");
    mermaid->set_long(lw("The mermaid is a small, beautiful creature, happily "
                       + "splashing around in the pool. She looks at you "
                       + "innocently with her large green eyes, and being a "
                       + "hardened warrior you estimate that it would "
                       + "probably be very easy to kill her. But you also "
                       + "understand that it could be a very, very bad move "
                       + "indeed to kill this little mermaid, who must be a "
                       + "very close friend of the Wizard's...\n"));
    mermaid->set_spell_mess1("The mermaid splashes some water at her attacker.");
    mermaid->set_spell_mess2("The mermaid splashes some water at you.");
    mermaid->set_chance(20);
    mermaid->set_spell_dam(1);
    mermaid->set_dead_ob(this_object());
    move_object(mermaid, this_object());

    /* The NEW, IMPROVED monster calls: */
    if (!chat_str) setup_arrays();
    mermaid->load_chat(10, chat_str);
    mermaid->load_a_chat(50, a_chat_str);
  }
}


/* Called when mermaid died */
monster_died(poor_mermaid) {
  wait = 1;
  set_heart_beat(1);
  murderer = poor_mermaid->query_attack();
  if(murderer) {
    "players/padrone/inside/sheriffs_office"->wanted(murderer,
      "the murder of a mermaid",0);
  }
  return 0;
}

dive(str) {
  if((!str)||(str=="in pool")||(str=="into pool")) {
    return enter("pool");
  }
  else {
    notify_fail("Dive what?\n");
    return 0;    
  }
}

enter(str) {
  if((!str)||(str!="pool")) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(!mermaid) {
    write(lw("The water is dark with the poor little mermaid's blood. You "
           + "dare not enter.\n"));
    return 1;     
  }
  this_player()->move_player("down into the water of the pool#players/padrone/tower/in_pool");
  return 1;
}

heart_beat() {
string murderers_name;

  if(wait) {
    wait = 0;
    return;
  }
  set_heart_beat(0);
  tell_room(this_object(),
    "The dying mermaid's horrible screams have alerted a security guard.\n");
  guard = clone_object("obj/monster");
  guard->set_name("security guard");
  guard->set_alias("guard");
  guard->set_level(5);
  guard->set_hp(110);
  guard->set_al(-50);
  guard->set_short("A security guard");
  guard->set_long(lw("This is a security guard in a dark suit with a helmet. " 
                   + "He is responsible for the security here, and he hates "
                   + "mermaid-killers!\n"));
  guard->set_aggressive(1);
  guard->set_male();
  guard->set_spell_mess1("The guard yells: Eat my bolts, Murderer! Bloodsucker! Fool!");
  guard->set_spell_mess2("The guard yells at you: Eat my bolts, Murderer! Bloodsucker! Fool!");
  guard->set_chance(50);
  move_object(guard, this_object());
  weapon=clone_object("players/padrone/obj/m16f");
  weapon->set_monsters_reload_at_reset(1);
  transfer(weapon, guard);
  guard->init_command("wield crossbow");
  murderers_name=murderer->query_name();
  tell_room(this_object(),
    "The security guard says: You're dead meat, "+murderers_name+"!\n");
  guard->attacked_by(murderer);
}

/* For the NEW, IMPROVED monster class: */
setup_arrays() {
  chat_str=({"The mermaid smiles happily.\n",
	     "The mermaid splashes happily.\n"});
  a_chat_str=({"The mermaid begs: Please don't kill me!\n",
	       "The mermaid asks you: Why do you do this?\n",
	       "The mermaid screams for help.\n",
	       "The mermaid screams for help.\n",
	       "The mermaid bleeds on you.\n"});
} /* setup_arrays */




