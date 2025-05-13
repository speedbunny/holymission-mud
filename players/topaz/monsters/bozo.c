inherit "/players/whisky/seaworld/monster/monster.c";

int count;

reset(arg) {
        ::reset(arg);
     if (arg) return;
    load_chat(12,({
            "Bozo makes you laugh.\nYou fall down laughing.\n",
            "Bozo makes a funny face at you.\n",
            "Bozo jumps around laughing.\n",
    }));
    load_a_chat(40,({
      "Bozo says: Hey!  Quit clowning around!\n",
      "Bozo looks for help from the crowd.\n",
      "Bozo the clown begs you to stop this madness!\n",
    }));
    load_match(this_object(),
         ({
           "say_hello",    ({"arrives"}),
           "follow",    ({"leaves"}),
         }));
  set_name("bozo");
  set_alias("bozo the clown");
  set_short("Bozo the clown");
  set_long("This is Bozo the clown!\n" +
           "He looks very friendly.  He's just minding his\n" +
           "own business.  Please don't bother him.\n");
        set_level(5);
        set_hp(240);
        add_money(random(51));
        set_whimpy();
  set_al(500);
  set_aggressive(0);
  set_move_at_reset(0);
}


    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
  notify( "Bozo says: Hi " + who + ", nice to see you !\n");
    }
}
    

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
        command(where);
}
