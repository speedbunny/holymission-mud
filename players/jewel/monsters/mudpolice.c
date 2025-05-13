inherit "obj/monster";

reset(arg)  {
    ::reset(arg);
    if (arg) 
        return;
    set_name("MudPolice");
    set_alias("police");
    set_alt_name("mudpolice");
    set_race("human");
    set_level(1);
    set_ep(0);
    set_hp(1);
    set_wc(5);
    set_al(100);
    set_short("A MUDPolice Officer");
    set_long("A uniformed MUDPolice officer sent here to investigate you.\n");
    set_aggressive(0);
    set_dead_ob(this_object());
    load_chat(50, ({
        "MudPolice Officer says:  Why do you annoy your fellow players?\n",
        "MudPolice twirls his nightstick and says: Just the facts, please!\n",
        "MudPolice raises his mudbadge and shouts: HALT! CEASE and DESIST!!\n",
        "MudPolice frisks you and announces:  You have the right to remain SILENT!!\n",
        "MudPolice eyes you cautiously and asks: Do you understand the rules?\n",
        "MudPolice takes you by the hand and asks: Do you have problems at home?\n",
        "MudPolice officer raises his eyebrow at you.\n",
        "MudPolice asks:  Why do you bring your insecurities with you to the MUD?\n",
        "MudPolice screams: Hold it right there, buddy!\n",
        "MudPolice eats a donut and spills powdered sugar all over you.\n",
        "MudPolice asks:  Where is the nearest donut shop, buddy?\n",
        "MudPolice tries to sell you a ticket to the Police Officers' Ball.\n",
        "MudPolice polishes his badge.\n",
        "MudPolice looks you up and down.\n",
        "MudPolice displays his gleaming gun.\n",
        "MudPolice pulls out a bag of donuts.\n",
        "MudPolice eyes you warily.\n",
    }));
              }

monster_died(ob) {
    object o;

    write("\n");
    write("A MudPolice officer has been brutally killed!!\n" +
          "Two more officers are dispatched to investigate.\n\n" +
          "Two more officres arrive and carry away the corpse for a proper funeral.\n\n");
    o = clone_object("players/jewel/monsters/mudpolice");
    move_object(o, environment(ob));
    o = clone_object("players/jewel/monsters/mudpolice");
    move_object(o, environment(ob));
    destruct(ob);
    return 1;
}

init() {
    ::init();
    add_action("Goaway", "goaway");
}

Goaway() {
    write("MudPolice says: yes sir!\n");
    destruct(this_object());
    return 1;
}
