#define ME this_object()
inherit "/obj/monster"; 
 
   reset(arg) {
    ::reset(arg);
     if (arg) return 1;
    move_object(clone_object("/players/alex/weapons/bpclaw"),ME);
    command("wield claw");
 
    set_name("Black panther");
    set_alias("panther");
    set_alt_name ("black panther");    
    set_short("A black panther");
    set_long(
             "As you look at him you feal scared to your toes\n"+
             "his claws are VERY sharp and his teath boy those teath\n"+
             "they make ole sabertooth look small.\n" +
             "As you gasp in awe at this magnificent creature you think\n"+
             "that you had better be VERY hard befor you can even\n"+
             "scratch this one.\n"
            );
              
    set_gender(1);
    set_level(20);
    set_aggressive(0);
    set_al(1000);
    set_chance(20);
    set_spell_mess1("The panther slaps his paws togeather and darkness surounds you.");
    set_spell_mess2("The panther calls out a word of command and a team\n"+
                    "of small shadow cats atack you.");
    set_spell_dam(20);
}
 
