inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("sheepslayer");
set_alias("sword");
set_short("Sheepslayer");
set_long(
"This is the famed Sheepslayer, a two-handed sword with the power to utterly\n"
+ "annihilate those wooly creatures. A sheep is etched into the hilt of this\n"
+ "fine weapon and the metal blade gleams brightly. The pride and joy\n"
+ "of any serious adventurer.\n");
set_value(6000);
set_weight(2);
set_class(14);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(50)<50 && attacker->query_race() == "sheep") {
write("You fiercely slash "+attacker->query_name()+" with the Sheepslayer!\n");
say(this_player()->query_name()+" fiercely slashes "+attacker->query_name()+" with the Sheepslayer!\n");
return 9;
   }
return 0;
 }
