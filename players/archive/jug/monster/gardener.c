#include "/players/jug/defs.h"

inherit "/obj/monster";

reset(str) {
    object ac, wc;
    ::reset(str);
    if(str) return;
    set_name("gardener");
    set_short("The gardener");
    set_long("This is the gardener of this wonderful garden.\n" +
      "He looks rather busy, chasing away vermin from his plants.\n");
    set_race("human");
    set_level(15);
    set_ac(99);
    set_move_at_reset();

    ac = clone_object("obj/armour");
    ac->set_name("apron");
    ac->set_short("A gardener apron");
    ac->set_long("This apron is worn by the gardener in Jug`s castle,\n");
    ac->set_value(700);
    ac->set_weight(1);
    ac->set_ac(4);
    ac->set_info("gardener-apron (created by Jug)");
    transfer(ac, this_object());
    init_command("wear apron");

    ac = clone_object("obj/armour");
    ac->set_name("hat");
    ac->set_short("A gardener hat");
    ac->set_type("helmet");
    ac->set_long("This hat is worn by the gardener in Jug`s castle,\n");
    ac->set_value(300);
    ac->set_weight(1);
    ac->set_ac(2);
    transfer(ac, this_object());
    init_command("wear hat");

    wc = clone_object("obj/weapon");
    wc->set_name("rake");
    wc->set_class(15);
    wc->set_short("A gardener rake");
    wc->set_long("This rake is wielded by the gardener in Jug`s castle,\n");
    wc->set_value(1500);
    wc->set_weight(2);
    wc->set_info("gardener-rake (created by Jug)");
    transfer(wc, this_object());
    init_command("wield rake");

    load_chat(30, ({
      "The gardener says: Hello there!\n",
      "The gardneer says: Can you kill some vermin for me?\n",
      "The gardener says: Those darn moles.\n",
      "The gardener says: I love my honey.\n",
      "The gardener says: You know those rabbits breed like...\n",
      "The gardener scratches his head.\n",
      "The gardener rakes a bit.\n",
      "The gardener shrugs.\n",
      "The gardener blushes.\n",
    }));
}

init() {
    ::init();
    add_action("ask_weapon", "ask");
}

ask_weapon(str) {
    object shears;
    if(str == "gardener for shears" || str == "gardener for weapon" ||
      str == "for shears" || str == "for weapon") {
	write("You ask the gardener for a weapon.\n");
	say(this_player()->query_short_name() + " asks the gardener " +
	  "for a weapon.\n");
	if(!present("shears", this_player())) {
	    write("Gardener says: Ahh, now you can help me keep my garden " +
	      "clean.\n");
	    say("Gardener says to " + this_player()->query_short_name() +
	      ": Now you can help me keep my garden clean.\n");
	    write("The gardener gives you some pruning shears.\n");
	    say("The gardener gives"+CAP(PNAME)+" pruning shears.\n");
	    shears = clone_object("/players/jug/obj/p-shears");
	    transfer(shears, TP);
	    return 1;
	}
	write("Gardener says: I have already given you a weapon.\n");
	tell_room(E(TO),
	  "'Go away!!!, the gardener shouts.\n");
	return 1;
    }
    write("Ask for what?\n");
    return 1;
}
