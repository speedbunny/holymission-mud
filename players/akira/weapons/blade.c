inherit "/obj/weapon";
reset(arg){
::reset(arg);
set_name("Infinity Blade");
set_alias("blade");
set_short("Infinity Blade");
set_long("This is the Infinity Balde of the Timelords. The handle is\n"+
         "made from the finest metals, but the blade, well that is made\n"+
         "from infinity. The blade has no real shape to it, and when you\n"+
         "look at it, the blade seems to look back at you. Small bolts\n"+
         "of power keep shooting from the blade.\n");
set_hit_func(this_object());
set_weight(3);
set_value(10000);
set_class(20);
set_max_salvo(1);
set_wc_per_shot(this_player()->query_level()+1);
set_sound("SMACK! A shot shoots forth!\n");
set_value_per_shot(20);
}
init(){
::init();
add_action("no_wield", "wield");
add_action("_cut", "cut");
}
_cut(str){
if(! str){
notify_fail("Cut what?\n");
return 0;
}
if(str= "reality"){
write("Your blades cuts a hole in reality, and you are pulled through.\n");
say(this_player()->query_name()+" uses his sword to cut through the fabric\n"+
    "of time and space. He then enters the rip and vanishes.\n");
this_player()->move_player("up#players/nylakoorub/guild/room");
return 1;
}
}
no_wield(str){
if(this_player()->query_guild() !=10){
write("You are not ready for this power!\n");
this_player()->hit_player(this_player()->query_hp()-1);
return 1;
}
}
weapon_hit(ob){
if(random(20) <= 5)
write("Your blade cuts at your victims very reality!\n");
say(this_player()->query_name()+"'s blade cuts at his opponets reality!\n");
return 50;
}
