inherit "obj/monster";
 
    reset(arg) {
     ::reset(arg);
  if (arg) return 1;
 
 
        set_name("bunny");
        set_level(2);
        set_al(500);
        set_alias("nice Bunny");
        set_short("A nice looking bunny");
        set_long("As you look at this bunny which is hopping over the field\n"+
                 "you feal a bit hungry.\n" );
 
 
        set_wc(1);
        set_ac(0) ;
 
        set_aggressive(0);
 
        set_spell_mess1("The bunny cries in pain and you feal Reaaallly bad.");
        set_spell_mess2("The bunny looks at you with those bunny eye's, you git");
        set_chance(75);  
        set_spell_dam(1); 
 
        add_money(10);
}
 
