inherit "obj/monster";
#include "/players/akira/defs.h"
reset(arg){
    ::reset(arg);
    if (! arg) {
        set_name ("Yen Wang Yeh");
        set_alt_name("yeh");
set_long("This is the GOD Yen Wang Yeh, the Judge of the Dead! He\n"+
         "stands about eight feet tall and has skin as black a the\n"+
         "night sky. His face seems so still that if it where not\n"+
         "for his eyes looking at you, you would think him asleep.\n"+
         "Something about the way he moves tells you that it might\n"+
         "be a good idea to leave this place very fast!\n");
        set_al(-1000);
	set_ac(40);
        set_aggressive(1);
        set_level(70);
        set_wc(30);
        set_race("dragon");  /* There are weapons that can help here */
        set_number_of_arms(4);  /* Well he is a God! */
        set_dead_ob(this_object());
    }
}
init(){
    ::init();
    add_action("block", "feet");
    add_action("block", "cast");
    add_action("block", "death");
    add_action("block", "assassinate");
    add_action("block", "backstab");
    add_action("block", "smash");
    add_action("block", "choke");
    add_action("block", "but");
    add_action("block", "punch");
    add_action("block", "kick");
    add_action("block", "bodyslam");
    add_action("block", "knee");
    add_action("block", "bash");
    add_action("block", "backstab");
}
block (arg) {
    if(query_verb()== "feet") {
        if(arg== "yeh");
        write("He blocks you attack with VERY little effort!\n");
    say(this_player()->query_name()+"'s kick is blocked by Yeh!\n");
	this_player()->hit_player(50);
	return 1;
    }
    if(query_verb()== "smash"){
        if(arg== "yeh");
        write("Yeh slaps you attack out of his way VERY harshly!\n");
    say(this_player()->query_name()+"'s smash is slapped away!\n");
	this_player()->hit_player(40);
	return 1;
    }
    if(query_verb()== "cast"){
  this_player()->restore_spell_points(-(this_player()->query_spell_points()/2));
write("Yeh says: Your Magic isn't good enough for me!\n");
say(this_player()->query_name()+"'s spell is countered by Yeh!\n");
    return 1;
 }
    if(query_verb()== "choke"){
        if(arg== "yeh");
        write("He slaps your hands down and counter strikes!\n");
    say(this_player()->query_name()+"'s hands are slapped away!\n");
	this_player()->hit_player(100);
	return 1;
    }
    if(query_verb()== "but"){
        if(arg== "yeh");
        write("Yeh smiles, and headbutts you right back!\n");
    say(this_player()->query_name()+" is headbutted by Yeh!\n");
	this_player()->hit_player(150);
	return 1;
    }
    if(query_verb()== "punch"){
        if(arg== "yeh");
        write("Yeh parries your punch and counter strikes you!\n");
     say(this_player()->query_name()+"'s punch is parried!\n");
	this_player()->hit_player(20);
	return 1;
    }
    if(query_verb()=="kick"){
        if(arg== "yeh");
	write("Your kick is caught and thrown to the side!\n");
  say(this_player()->query_name()+"'s kick is thrown aside!\n");
	return 1;
    }
    if(query_verb()=="bash"){
        if(arg== "yeh");
        write("Yeh dodges your attack, you can hear him laughing at you!\n");
   say(this_player()->query_name()+"'s bash is dodged!\n");
	return 1;
    }
    if(query_verb()== "assassinate" && query_verb()=="backstab"){
        if(arg== "yeh"){
        write("Yeh says: Not today little one!\n");
	    this_object()->attack_obj(this_player());
	    if(this_player()->query_invis());
	    this_player()->set_vis();
	    return 1;
	}
    }
    if(query_verb()=="death"){
        if(arg== "yeh");
        write("He parries your death strike and hits you with one!\n");
   say(this_player()->query_name()+"'s hit with a Death Strike!!!\n");
	this_player()->hit_player(400);
	return 1;
    }
    if(query_verb()=="bodyslam"){
        write("Yeh plants himself, you do not even get him off the ground!\n");
	return 1;
    }
}
hit_player(dam){
                  switch(RAN(100)){
                  case 0..20:
                  this_player()->hit_player(50);
    write("Yeh throws a powerful kick to your head!\n");
                  break;
                  default: break;
                  case 21..30:
                  this_player()->hit_player(75);
   write("Yeh stomp kicks you right in the knee!\n");
                  break;
                  case 31..40:
                  this_player()->hit_player(100);
   write("Yeh gives you a swift kick bellow the belt!\n");
                  break;
     }
                  return :: hit_player(dam);
    }
int monster_died(object ob){
  write("You strike the final death blow on Yen Wang Yeh!\n");
  shout(this_player()->query_name()+" has killed Yen Wang Yeh!\n");
  return 0;
}
