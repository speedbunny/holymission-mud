inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if (arg) return;

        set_name("human");
        set_short("A clever looking human");
        set_alias("human");
        set_long("This human holds some very interesting secrets.\n");
        set_level(2);

 
        load_chat(5,({
                "Human says: The dark one is too strong for me to kill.\n",
                "Human says:  Help me kill the dark one.\n",
                "Human says:  Get the sword, thats the only way.\n",
								"Human says:  Don't be foolish with the dark one.\n",
        }));

        load_a_chat(15,({
                "Human shouts: You'll die for this!\n",
        }));
}
