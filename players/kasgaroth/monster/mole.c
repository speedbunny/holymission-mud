inherit "obj/monster";

reset(str) {
    ::reset(str);
    if(str) return;
    set_name("mole");
    set_short("A mole");
    set_long("This seems to be one of the moles the gardener is worried\n" +
      "about. It looks out from a heap of earth and seems to be very\n" +
      "content to destroy the garden's peaceful beauty.\n");
    set_race("rodent");
    set_level(1);
    set_wc(2);
    set_ac(1);
    set_al(-50);
    add_money(50);
}
