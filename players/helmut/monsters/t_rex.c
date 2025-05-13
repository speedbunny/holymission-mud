inherit "obj/monster";
#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Tyrannosaurus Rex");
    set_alt_name("trex");
    set_short("Tyrannosaurus Rex");
    set_alias("rex");
    set_long("You recoil in fright from this nightmarish apparition.\n"+
      "Standing tall and proud on huge, powerful legs, this\n"+
      "titan of invincibility rules the world without challenge.\n"+
      "Twenty-five cm long teeth sprout from jaws capable of\n"+
      "swallowing even a giant in one massive gulp.  The massive\n"+
      "head tosses from side to side as he surveys his surroundings.\n"+
      "Suddenly, he roars with ear-splitting intensity, and gazes\n"+
      "in your direction.  Your blood runs cold, and you remember\n"+
      "something about standing still...\n");
    set_level(200);
    set_number_of_arms(3);
    set_hp(125000);
    set_ac(40);
    set_wc(125);
    set_spell_mess1("The T-Rex lunges, and snaps its tremendous jaws shut on its victim.");
    set_spell_mess2("The T-Rex lunges, catching you off guard, and the sun disappears as the monstrous jaws snap shut around you.");
    set_chance(20);
    set_spell_dam(500);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
    }
}
int query_str()
{
    return 200;
}
