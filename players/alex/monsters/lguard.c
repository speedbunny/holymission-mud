inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
   
    set_name("last guard");
    set_alias("guard");
    set_alt_name("ghost");  
    set_short("A very dead guard");
    set_long("The guard has been dead for some time now but you can see\n"+ 
              "that his sorrow has not decreased.  A hundred and one arrows\n"+
              "still pierce his now incorperial body, he will not let you\n"+
              "have the crown.\n");
    set_gender(1);
    set_level(20);
    set_aggressive(0);
    set_al(-100);
    set_chance(50);
    set_spell_mess1("You watch him pull an arrow out of his body\n"+
         "and hurl it at his attacker.");
    set_spell_mess2("The last guard pulls an arrow from his chest and throws\n"+
                    "it at you, as they hit they hurt ALOT then vanish.");
    set_spell_dam(20);
}
init() {
  ::init();
  add_action("get","get"); 
  add_action("get","take");
}
get(string str) {
  switch(str) {   
    case "crown" :
    case "bcrown" :
    case "Highlord's Alex crown" :
        write("The guard see's you trying to take the crown and screams.\n"+ 
              "He will not let you take it.\n");
        return 1;
      }
 return 0;
}
