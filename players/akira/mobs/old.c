inherit "obj/monster";
reset(arg){
::reset(arg);
if(! arg) {
set_name("old one");
set_alt_name("one");
set_short(" Old One ");
set_long("This is the last survivor of the Great Summoner Wars. For his "+
         "crimes against the world, he has been cursed to forever guard "+
         "this temple. He is the oldest person you have ever seen, but "+
         "you can feel great power around him. He wears the robes of a "+
         "arch-summoner, but you can see no monsters at his sides.\n");
set_level(90);
set_al(-1000);
set_hp(5000);
set_ac(50);
set_wc(70);
set_aggressive( 1 );
}
}
