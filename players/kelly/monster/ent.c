inherit "obj/monster";

reset(arg) {

    object br;

    ::reset(arg);
    if(arg) return;

    set_name("ent");
    set_level(30);
    set_dex(15);
    set_str(10);
    set_hp(1000);
    set_al(-250);
    set_race("ent");
    set_size(5);
    set_short("A ent");
    set_long("It looks like a tree, but it lives.\n");
    set_ac(20);
    set_wc(10);
    set_aggressive(0);
    load_chat(10,
             ({ "The ent cuts of some branches to improve the growing of the trees.\n",
                "The ent scratches himself with his brachy arms.\n",
             }));
    load_a_chat(20,
               ({ "The ent says: Slowly, slowly, not so fast.\n",
                  "The ent says: This is ridiculous.\n",
                  "The ent frowns.\n",
               }));

    if(!present("branch")) {
        move_object(clone_object("/players/mangla/objects/branch"),
                    this_object());
        init_command("wield branch");
    }
}

