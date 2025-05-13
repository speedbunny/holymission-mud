#define ME this_object()
inherit "/obj/monster";
 
int WIELDED; reset(arg) {
    ::reset(arg);
     if(arg) return;
 
    move_object(clone_object("/players/alex/weapons/kmace"),ME);
    command ("wield mace");
    move_object(clone_object("/players/alex/armour/bplatemail"),ME);
    command("wear ",ME);
    move_object(clone_object("/players/alex/armour/bshield"),ME);
    command("wear ",ME);
    move_object(clone_object("/players/alex/armour/bhelmet"),ME);
    command("wear ",ME);
 
    set_name("Death knight");
    set_alias("knight");
    set_short("Death knight");
    set_long("A undead Death knight\n" +
             "He looks to have ernt his name the hard way.\n");
    set_gender(1);
    set_level(42);
    set_aggressive(0);
    set_al(-500);
    set_chance(15);
    set_spell_mess1("The knight blows his icy breath over you.");
    set_spell_mess2("The knight pushes his hand into your chest and stops your heart.");
    set_spell_dam(100);
    add_money(4000);
}
init() {
add_action("kill","kill");
::init();
}
kill() {
if (present("black broadsword",this_player())){
        destruct(present("black broadsword",this_player()));
     if (present("bring",this_player())){
          destruct(present("bring",this_player()));
        }
 
      if (present("bcrown",this_player()));{ 
        destruct(present("bcrown",this_player()));
        }
 
        write (
        "As you sink the sword into the Death knights heart the sword \n"+    
        "flares up and the knight screams in agony, the knight reals away\n"+ 
        "from you taking the sword from your hand, he turns faster and \n"+   
        "faster, streams of light come of him then with a BANG he is gone \n"+
        "leaving his weapons, armour and a faint thankyou on the air behind him.\n"+  
        "As you check your inventory you find other objects have been take by the knight as he left.\n"+      
        "The great Lords sword has done its work and has gone back to Alex sword.\n");
 
return 1;
}
 
 
 
  else {
    write("You try to kill the Death knight but realise that you are not prepared for him.\n");
    return 1;
            }
}
