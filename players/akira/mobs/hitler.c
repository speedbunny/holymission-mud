inherit "obj/monster";
reset(arg){
    ::reset(arg);
    set_name("Hitler");
    set_alias("hitler");
    set_short("Adolph Hitler");
    set_long("This is the commander and chief of all German forces. He\n"+
      "has locked himself in this bunker and is sending out orders\n"+
      "to an army that is already defeated. From the look in his\n"+
      "eyes he is quite mad.\n");
set_number_of_arms(2);
    set_level(22);
    set_ac(17);
    set_wc(13);
    set_aggressive(1);
}
