inherit "obj/weapon";
int i;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("scimitar");
    set_alias("Al-Akbar");
    set_read("Al-Akbar");
    set_alt_name("sword");
    set_short("A Glowing Scimitar");
    set_long(
      "This is an Arabian scimitar.  It is light and swift, so light in fact\n"+
      "you wonder how you ever swung another weapon!  Runes are engraved in the\n"+
      "blade.\n");
    set_class(15);
    set_light(1);
    set_hit_func(this_object());
    set_weight(2);
    set_value(10000);
}

weapon_hit(attacker) {
    int i, dam;
    string tome, tothem;
    i=random(20);
    switch(i) {
    case 0:
	tome="You feel Al-Akbar dig deep!";
	dam=5; break;
    case 1:
	tome="Al-Akbar happily drinks the blood of his foe!";
	dam=10; break;
    case 2:
	tome="Al-Akbar vibrates as it slices through its foe!";
	dam=15; break;
    case 3:
	tome="Al-Akbar slices right through its foe's bones!";
	dam=20; break;
    case 4:
	tome="Al-Akbar easily slices clear through its foe!";
	dam=25; break;
    case 5:
	tome="Al-Akbar guides your hand for a Parry - Strike!";
	tothem=this_player()->query_name()+" performs a great Parry - Strike maneuver!";
	dam=30; break;
    case 6:
	tome="Al-Akbar guides your hand for a vicious backhand slash!";
	tothem=this_player()->query_name()+" hits with a vicious backhand slash!";
	dam=35; break;
    case 7:
	tome="Al-Akbar guides your hand for a perfect reverse thrust!";
	tothem=this_player()->query_name()+" hits with a perfect reverse thrust!";
	dam=40; break;
    case 8:
	tome="Al-Akbar hits again while giggling inanely!";
	tothem=this_player()->query_name()+" hits again!  You hear a weird giggling noise.";
	dam=45; break;
    case 9:
	tome = "AL-Akbar strikes again, screaming 'DEATH TO ALL FOES!'";
	tothem = this_player()->query_name() + " swings again!  A wierd voice screams ' DEATH TO ALL FOES!'";
	dam=50; break;
    case 10:
	tome="Al-Akbar guides you through a double parry - thrust!";
	tothem=this_player()->query_name()+" does a perfect parry - thrust - parry - thrust!";
	dam=55; break;
    case 11:
	tome="Al-Akbar makes a quick triple slash!";
	tothem=this_player()->query_name()+" makes a quick triple slash!";
	dam=60; break;
    case 12:
	tome="Al-Akbar strikes 3 times, screaming 'KILL KILL KILL!'";
	tothem=this_player()->query_name()+" hits 3 times, while a voice screams 'KILL KILL KILL!'";
	dam=65; break;
    case 13:
	tome="Al-Akbar strikes 3 times, screaming 'MAY YOU ROT IN HELL!'";
	tothem=this_player()->query_name()+" hits 3 times, while a voice screams 'MAY YOU ROT IN HELL!'";
	dam=70; break;
    case 14:
	tome="Al-Akbar strikes 3 times while chanting 'BLOOD AND GUTS!'";
	tothem="As "+this_player()->query_name()+" swings 3 times, you hear a voice chanting 'BLOOD AND GUTS!'";
	dam=75; break;
    case 15:
	tome="Al-Akbar leaps away and pummels your opponent, screaming 'HACK!'";
	tothem=this_player()->query_name()+" releases the blade as it pummels its foe, a voice screams 'HACK!'";
	dam=80; break;
    case 16:
	tome="Al-Akbar leaps at your opponent, screaming 'MEET YOUR MAKER!'";
	tothem="The blade leaps away, a voice screams 'MEET YOUR MAKER!'";
	dam=85; break;
    case 17:
	tome = "Al-Akbar leaps at your opponent, screaming 'DEATH TO THE INFIDEL'!";
	tothem = "The blade leaps away, a voice screams 'DEATH TO THE INFIDEL!'";
	dam=90; break;
    case 18:
	tome="Al-Akbar leaps at your opponent, screaming 'I WILL KILL YOU!'";
	tothem="The blade leaps away, a voice screams 'I WILL KILL YOU!'";
	dam=95; break;
    case 19:
	tome="Al-Akbar leaps at your opponent, screaming 'NIH!'";
	tothem="The blade leaps away, a voice screams 'NIH!'";
	dam=100; break;
    default:
	return 0; break;
    }
    write(tome+"\n");
    say(tothem+"\n",this_player());
    if (this_player()->query_immortal()) write("Al-Akbar whispers: "+dam+" damage!\n");
    return dam;
}

wield (str) {
    ::wield(str);
    if(id(str)) {
	write("A strange voice says: 'Hello I am Al-Akbar!, are you my new master?'\n"+
	  "You realize it comes from the Scimitar!\n");
	say("A strange voice whispers: 'Hello I am Al-Akbar!, are you my new master?'\n"+
	  "as "+this_player()->query_name()+" wields a glowing scimitar.\n");
	return 1;
    }
}
