inherit "/room/room";
object wkn;
 reset(arg){
 wkn=clone_object("/players/patience/guild/sorcerer_spells/wkn1");
 transfer(wkn,this_object());
 set_light(1);
 short_desc=("A shit");
 long_desc=("You are in the big shit.\n");
 smell="You feel terrible smell of the shit.";
 items=({"shit","You are in the big shit"});

 ::reset(arg);
}
