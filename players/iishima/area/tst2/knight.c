inherit "obj/monster";

void reset(){
::reset();
set_name("knight of darkness");
set_race("demon");
set_short("Knight of Darkness");
set_alias("knight");
set_long("This creature looks very dangerous!  This is The Daemon Lord's Knight of\n"+
         "Darkness.  When you look at him you tremble in fear!  He is 10 feet tall,\n"+
         "and has evil, glowing eyes.  Any wise person would not attack this creature.\n");
set_level(19);
set_hp(375);
}
