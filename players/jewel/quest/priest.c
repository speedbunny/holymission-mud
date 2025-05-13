inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(!arg) {
        set_name("priest");
        set_level(10);
        set_race("human");
        set_al(200);
        set_short("a priest");
        set_long("A nice looking robed figure with an irritated look.\n");
        set_wc(12); 
        set_ac(5);
        set_no_steal();
        load_chat(20,({ 
  "The priest says: Please sacrifice some money for the poor and homeless...\n",
  "The priest says: Sacrifice money, so the gods will be on your side!\n"
                     }));
    }
}
