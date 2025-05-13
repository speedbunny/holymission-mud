

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Former Healing Shop";
    no_castle_flag = 0;
    long_desc = 
        "You are in what used to be the Keidall Healing Shop. Signs of a scuffle are\n"
        + "apparent in this shack and there is no trace of the woman who used to run the\n"
        + "store, although you can see many dried blood stains smeared across the walls.\n"
        + "Since she had no heirs it looks as if Keidall will be without a healing shop\n"
        + "for a while. Maybe you could look for the bandits who wrecked this shop.\n";
    items = ({
         "blood","Ugly, old splatters of blood with some pieces of flesh here and there",
        });
    dest_dir = 
        ({
        "/players/silas/fghant/keidall5", "north",
        });
}

query_light() {
    return 1;
}
