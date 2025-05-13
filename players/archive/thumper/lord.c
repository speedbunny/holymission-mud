/* Thumper's Houron Monster */
inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("The evil Lord Houron ");
    set_level(10);
    set_hp(500);
    set_ep(250);
    set_al(-500);
    set_gender(1);
   set_race("houron");
    set_short("The mighty Lord Houron");
   set_long("An evil Houron Lord bent on killing all!\n");
    set_wc(10);
    set_ac(1);
    set_aggressive(10);
   set_size(8);
    load_chat(10, ({
        "The Houron snarls .\n",
       "The houron screams DIE!\n",
      }) );
}
