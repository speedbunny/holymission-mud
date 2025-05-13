inherit "obj/monster";

void critical();
void drain();
void death();
void beam();
void energy();

object target;
int find_target();
void notify(string mess1, string mess2, object tar);

reset (arg) {
    ::reset(arg);
    if(arg) return;
    set_name("xoran");
    set_alias("beholder");
    set_alt_name("tyrant");
    set_short("Tyrant Xoran");
    set_long(
      "This is the Evil Tyrant Xoran, Lord of all the beholders and the\n"
      +"second in command to Thraxus the Possesor.  He hovers before you\n"
      +"seemingly uninterested in your presence.  He has stood the tests of\n"
      +"time and does not think a group of stalwart warriors shall remove\n"
      +"him from this plane of existance.\n");
    set_race("beholder");
    set_gender(1);
    set_level(40);
    call_out("eyes", 12);
    set_hp(10000);
    set_al(-1800);

    set_aggressive(0);


}

void eyes(){
    int attack;
    if(!environment() || !find_target()) {
	call_out("eyes", 12);
	return;
    }
    attack=random(80);
    if(attack==1){
	critical();
	drain();
	death();
	beam();
	energy();
    }
    if(attack<3 && attack>1) {
	critical();
	drain();
	beam();
	energy();
    }
    if(attack>3 
      && attack<7) {
	critical();
	drain();
	energy();
    }
    if(attack>7 && attack<10) {
	critical();
	drain();
    }

    if (attack>10 && attack<20) {
	death();
    }
    if(attack>20 && attack<30) {
	critical();
    }
    if (attack>30 && attack<40) {
	drain();
    }
    if (attack>40 && attack<50) {
	energy();
    }
    if (attack>50 && attack<60) {
	beam();
    }
    call_out("eyes",3);
    return;
}

void death() {
    if(this_object()->query_hp()<8000){
	tell_room(environment(this_object()),
	  "The eye of death tries to stare at you, but it falls limp to the side from\n"
	  +"its extensive injuries dealt to it.\n");
	return;
    }
    notify("Xoran's eye of Death stares at his victim!", "Xoran's eye of Death stares at you, you feel death enter your very soul!", target);
    target->hit_player(30+random (30));
    return;
}
void critical(){
    if(this_object()->query_hp()<6000){
	tell_room(environment(this_object()),
	  "Xoran tries to use his eye against you, but only a bloody stump remains.\n");
	return;
    }
    notify("A stream of electrical energy shoots forth from Xoran's eye!","A stream of electrical energy shoots forth from Xoram's eye\n" +"and strikes you in the neck. Critically hitting you!", target);
    target->hit_player(25+random(25));
    return;
}
void drain(){
    if(this_object()->query_hp()<4000){
	tell_room(environment(this_object()),
	  "Xoran screams in agony as his eye spurts forth blood.\n");
	return;
    }
    notify("One of Xoran's eyes drains the lifeforce from its victim!","You feel the lifeforce drained from you body as you stare into his eyes!", target);
    target->hit_player(20+(20));
    return;
}
void energy(){
    if(this_object()->query_hp()<2000){
	tell_room(environment(this_object()),
	  "Xoran howl's in pain as his eye burns from the damage brought forth upon it!\n");
	return;
    }
    notify("Xoran's eye shoots forth a sphere of bio-energy which \n"+
      "explodes upon his victim!",
      "A sphere of bio-energy from Xoran's eye explodes in your chest!", target);
    target->hit_player(15+(15));
    return;
}
void beam(){
    if(this_object()->query_hp()<1000){
	tell_room(environment(this_object()),
	  "Xoran tries to fire a beam of light, but from the damage\n"+
	  "it took the eye fizzles.\n");
	return;
    }
    notify("A beam of light strikes its victim with a searing burn!", "A beam of light sears you across the arm!!", target);
    target->hit_player(10+random(10));
    return;
}
int find_target() {
    target=this_object()->query_attack();
    if(!target || !present(target, environment()) || target->query_ghost())
	return 0;
    return 1;
}
void notify(string mess1, string mess2, object tar){
    say(mess1+"\n", tar);
    tell_object(tar, mess2+"\n");
    return;
}
