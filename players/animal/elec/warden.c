inherit "obj/monster";
string chat, a_chat;
 
reset(arg) {
  ::reset(arg);
    set_name("warden");
    set_level(11);
    set_hp(500);
    set_al(0);
    set_race("human");
    set_gender(1);
    set_short("The warden");
    set_long("He is a tough warden.\n");
    set_wc(12);
    set_ac(17);
    set_aggressive(0);
    chat = ({"Warden says: I cure criminals for LIFE.\n", 
               "Warden sighs deeply.\n", 
               "Warden says: I don't always enjoy my job,"+
               " but most of the time I do.\n", 
               "Warden looks closely at you.\n", 
               "Warden says: I love the smell of burnt flesh.\n", 
               "Warden grins evilly.\n", 
               "Warden grins evilly.\n",
               "Warden cackles with glee!\n"});
    a_chat = ({"Warden says: You should be hanged!\n", 
                 "Warden says: You are nothing.\n", 
                 "Warden says: Wanna try this rope?\n"});
    load_chat(4, chat);
    load_a_chat(10, a_chat);
    enable_commands();
  }
