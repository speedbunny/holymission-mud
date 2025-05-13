inherit "obj/monster";

reset(arg) {
        ::reset(arg);
         if (arg) return;
	  load_chat(10,({
            "The little rat nibbles on your toe.\n",
            "A u t c h ..The little rat bites you in your knee.\n",
            "The little rat smells your foot.\n",
            "The little rat searches around.\n",
            "The little rat squeeks intently.\n",
	  }));
	  load_a_chat(80,({
            "The little rat bites you in your nose.\n",
            "Squiieeeekkkk.\n",
	  }));
	set_name("rat");
	set_alias("brown rat");
	set_short("A little brown rat");
	set_long("A little brown rat, searching\n"+
                 "for something to eat.\n"); 
        set_level(2);
        set_size(1);
        set_whimpy(50);
	set_al(-10);
	set_move_at_reset(1);
}
 init() {
   if (present("cheese",this_player())) {
      attack_object(this_player());
      tell_room(environment(),"The rat smells your cheese !\n"); }
   ::init();
   }

    


