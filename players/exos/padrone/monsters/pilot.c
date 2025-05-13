inherit "obj/monster";

reset(flag) {
    ::reset(flag);
    if(flag) return;
    set_name("pilot");
    set_alias("castle pilot");
    set_level(3);
    set_gender(1);
    set_wc(5);
    set_ep(140);
    set_al(-100);
    set_short("The pilot who is controlling the walking castle");
    set_long("This is a pilot. Using the controls on the bridge,\n" +
      "he can move the walking castle.\n");
    set_aggressive(0);
}
