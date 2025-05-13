inherit "/room/std_bank";

reset(arg) {
    if (!arg);
    set_light(1);
    short_desc=":::::::  Azgar's Bank  :::::::";
    long_desc=
        "You are in Azgar's bank. Some large men are sitting behind the "+
        "desk, waiting to take care of your business. Behind the counter"+
        "there is an information 'sign' fixed to the wall.\n";

    dest_dir= ({ "/players/gareth/guild/hall2","north",
	              });
    items = ({
              "men","Very LARGE men, which would kick your ass",
              "sign","There is something written on it",
              "counter","Azgar is counting coins",
              "walls","They are made of steel!",
              "Azgar","He looks at you and then smiles at the vault",
            });
    clerk = "Azgar";
    taxes = 0;
    save_file = "/players/gareth/guild/banker";
    load_info();


}


