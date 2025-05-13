inherit "obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("orc archer");
    set_alias("archer");
    set_alt_name("orc");
    set_short("Orc archer");
    set_long("This is an archer in the ranks of the orc army. He has \n"+
             "very keen eyes, which he uses to fling his arrows at his \n"+
             "opponents.\n");
    set_race("orc");
    set_gender(1);
    load_a_chat(10,({"Orc archer says: My arrows will kill you!\n",
                     "Orc archer grins evily.\n",
                     "Orc archer says: I can hit a fly in the dark!\n",
                     "Orc archer says: I won't miss!\n",}));
    set_level(15);
   set_hp(800);
    set_ep(1500);
    set_al(-500);
    set_wc(5);
    set_ac(4);
    set_aggressive(1);
    set_whimpy(-1);
    add_money(100 +random(100));
    transfer(clone_object("/players/shaka/weapons/bow")
    ,this_object());
    transfer(clone_object("/players/shaka/armour/holder")
    ,this_object());
    init_command("wield bow");
    init_command("wear holder");
  }
}
