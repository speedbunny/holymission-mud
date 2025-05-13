inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("mole");
    set_short("A mole");
    set_long("This seems to be one of the moles the gardener is worried\n" +
      "about. It looks out from a heap of earth and seems to be very\n" +
      "content to destroy the beauty of the garden.\n");
    set_race("mammal");
    set_level(1);
    set_wc(2);
    set_ac(1);
    set_al(-50);
    add_money(50);
}
