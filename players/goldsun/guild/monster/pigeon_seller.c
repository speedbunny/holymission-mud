inherit "obj/monster";

reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("pigeon seller");
      set_alt_name("seller");
      set_short("A pigeon seller");
      set_long("He looks like a man ready to do a bit of a deal with you.\n");
      set_gender(1);
      set_level(15);
      set_al(215);
      set_weight(10);
      set_race("human");
      set_dead_ob(this_object());
      load_chat(17,({
        "The pigeon seller says: Buy your pigeons from me for only 50 gold coins.\n",
        "The pigeon seller says: I never really wanted to be a pigeon seller. I always wanted to be a lumberjack.\n",
        "The pigeon seller says: All you need to do is type `buy pigeon` to get one.\n",
        "The pigeon seller says: They make great pets you know.\n",
        "The pigeon seller says: Aren`t these pigeons cute. Just like me!\n",
        "From somewhere a pigeon says: Coooooooo.\n",
        "The pigeon seller sings a short song about pigeons.\n"
      }));
}

init() {
        ::init();
        add_action("buy","buy");
}

buy(arg) {
        if(!arg && arg!="pigeon") {
                notify_fail("Buy what?\n");
                return 0;
        }
        if(present("pigeon",this_player())) {
                write("The pigeon seller tells you: Sorry but my stocks are a bit short and I dont want to sell more than one to one person.\n");
                return 1;
        }
        if(this_player()->query_money()<50) { 
                write("The pigeon seller tells you: But you dont have enough money. It costs 50 gold coins.\n");
                return 1;
        }
        this_player()->add_money(-50);
        write("The pigeon seller takes 50 gold coins off you and runs out of the room only to return moments later with a pigeon in a cage which he hands to you.\n");     
        transfer(clone_object
         ("players/portil/guild/obj/carrier_pigeon"),this_player());
        say(this_player()->query_name()+" buys a pigeon from the pigeon seller.\n");
        return 1;
}
