inherit "/obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("rosamunda");
    set_alias("wife");
    set_alt_name("keeper");
    set_short("Rosamunda, the bakers' wife");
    set_long("Rosamunda is the wife of the baker, she \n"+
             "can sell you bread.\n");
    set_race("hobbit");
    set_size(2);
    set_gender(2);
    load_chat(5,({"Rosamunda sings a merry song.\n",
                  "Rosamunda says: Hello!\n",
                  "Rosamunda eats a bread.\n",}));
    load_a_chat(5,({"Rosamunda screams.\n",
                    "Rosamunda says: OUCH!!\n",}));
    set_smell("Rosamunda smells just like everything here"
);
    set_level(15);
    set_hp(1000);
    set_ep(2000);
    set_al(100);
    set_wc(15);
    set_ac(4);
    set_aggressive(0);
    set_whimpy(-1);
    add_money(50 +random(50));
  }
}

