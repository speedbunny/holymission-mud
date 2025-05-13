#define TP       this_player()
#define TPN      (string)this_player()->query_name()
#define TPRN     (string)this_player()->query_real_name()
#define TO       this_object()
#define RRATE    3      /* regeneration rate */
#define RTIME    6      /* regeneration time */

#pragma strict_types

inherit "obj/armour"; 

int quiet;               /* flag: turn off regeneration message */
object owner;		 /* who carries the wand ? (for heart_beat */

void reset(int arg){

    ::reset(arg);

    if(!arg) {
	set_name("ring");
	set_short("Green ring with magic runes");
	set_long(
	  "The green ring has magical runes engraved upon the gold band and green gem.\n"+
	  "The light reflected from the green gem is most comforting and you feel\n"+
	  "that the ring is one with benevolent magic. The ring is light and\n"+
	  "while it seems like other precious rings, you just cannot bear to\n"+
	  "part with it.\n");
	set_ac(1);
	set_value(10000);
	set_weight(1);
	set_alias("regeneration ring"); 
	set_type("ring");
	enable_commands();
	quiet=1;
    }
}

void init(){
    ::init();
    add_action("shutup","twist");
}

mixed wear(string str){

    if(!worn) {
	write("The power of the ring pulses trough your body.\n");
	say(TPN + " emits a soft green glow.\n");
	owner=TP;
	set_heart_beat(1);
    }
    return ::wear(str);
}

status query_mage_wear(){ return 1; }

mixed remove(string str){
    if(worn) {
	write("A foreign energy seems to leave your body.\n");
	say(TPN + " stops glowing.\n");
	set_heart_beat(0);
    }
    return ::remove(str);
}

void heart_beat(){
    owner->heal_self(1);
    if(!quiet)
	tell_object(owner,"You feel regenerating.\n");
}

status shutup(){
    quiet=!quiet;
    write("KLICK!\n");
    return 1;
}

mixed drop(string sil){
    if(worn) {
	write("A foreign energy seems to leave your body.\n");
	say(TPN + " stops glowing.\n");
	set_heart_beat(0);
    }
    return ::drop(sil);
}
