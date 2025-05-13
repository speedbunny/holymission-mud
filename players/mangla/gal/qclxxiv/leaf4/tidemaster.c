/* The camouflaged tide controller for the tidal zone */
#define quarterticks 10
#define minwaterlevel 2
#define maxwaterlevel 6
#define maxtidetick 3

int hour, quarter, tidetick, waterlevel, rising, windcol;
string hour2latin, quarter2latin;
string depthlong, depth_rise, depth_fall;
string movecost; /* movecost is for swimming/walking (depth-dep) */
string movetext; /* text at init / exit hit_player */
string staycost; /* for staying (depth-dep, not in boat) */
string staytext; /* text at heartbeat hit_player */

id(str) { return str == "clock" || str == "tidemaster"; }
short() { return "An old clock"; }
get()	{ return 0; } /* controller should stay in its place */
query_weight() { return 100; }

/*
init()  { 
	add_action("print_tide", "print_tide" );
}
*/
water_level() { return waterlevel; }
is_rising() { return rising; }
is_falling() { return !rising; }

reset(arg) {
	string a, b;
	if (arg) return;
	windcol = random(7);
	hour = random(12)+1;
	quarter = random(4);
	tidetick = random(maxtidetick);
	waterlevel = random(maxwaterlevel-minwaterlevel)+minwaterlevel;
	rising = random(2); /* 1: rising, o: falling */
	hour2latin = ({ "O", "I", "II", "III", "IV", "V", "VI", 
						"VII", "VIII", "IX", "X", "XI", "XII", });
	quarter2latin = ({ "XII", "III", "VI", "IX", });
/*
	depthlong = allocate(10);
	depth_fall= allocate(10);
	depth_rise= allocate(10);
	movecost= allocate(10);
	staycost= allocate(10);
	movetext=allocate(10);
	staytext=allocate(10);
	if (depthlong==0 || depth_fall==0 || depth_rise==0 || movecost==0
				|| staycost==0 || movetext==0 || staytext==0 ) {
		write( "Fail to allocate arrays in tideroom\n");
		say( "Fail to allocate arrays in tideroom\n");
		return 0;
	}
*/
	movecost = ({ 0, 0, 1, 2, 4, 8, 16, 32, 64, 128  });
	staycost = ({ 0, 0, 0, 0, 2, 4, 8, 16, 32, 64 });
	depthlong = ({
"Far above the waterlevel upon a sandbank. The sand is nearly dry.\n",
"On a sandbank. The sand is not so wet here.\n",
"On a sandbank. The sand is soaked here.\n",
"In a feet deep water. Clearly there is a sandbank down here.\n",
"In deeper water. Apparently there is a sandbank down here.\n",
"In somewhat waving water. You can hardly touch the bottom with your feet.\n",
"Somewhat deeper waving water.\n",
"Deep water. The waves get higher here.\n",
"Rough and deep water. The waves get nasty.\n",
"Very rough and deep water. The waves are mean.\n"
	});
	/* if depth_fall 0 is addressed, prev depth was 1 (corr.) etc. */
	depth_fall = ({
"The sand seems to get even more dry.\n",
"The sand seems to get dry a bit.\n",
"The water withdraws, leaving the sand soaked.\n",
"The water is falling, just a feet of water left.\n",
"The water is falling, the bottom seems to become visible.\n",
"The water seems to get calmer.\n",
"The water seems to get calmer.\n",
"The waves seem to get a bit less nasty now.\n",
"The waves seem to get a bit less mean now.\n",
"The waves seem to get a bit less mean now.\n"  /* last one should not occur */
	});
	/* if depth_rise 4 is addressed, prev depth was 3 (corr.) etc. */
	depth_rise= ({
"The sand seems to get a bit less dry.\n", /* first should not occur */
"The sand seems to get a bit more wet.\n",
"The sand becomes soaked.\n",
"The water comes up, already a feet of water covers the bottom.\n",
"The water comes up, the bottom is hardly visible anymore.\n",
"The water comes up, waves getting a bit rougher.\n",
"The waves get rougher.\n",
"The waves get rougher.\n",
"The waves become nasty now.\n",
"The waves become plain mean now.\n"  
	});
	movetext = ({
"Walking on dry sand.\n",
"Walking on less dry sand.\n",
"Walking on soaked sand.\n",
"Walking in a feet of water.\n",
"Wading through the water.\n",
"Half wading, half swimming through the water.\n",
"Swimming through the water. It's quite an effort.\n",
"Swimming through the rough waves. The efforts it takes makes you weaker.\n",
"Swimming through the nasty waves. It costs great efforts, you get weaker.\n",
"Swimming through the mean waves. It costs enormous efforts, you're drained.\n"
	});
	staytext = ({
"Foggyness veils the air.\n",
"A cold breeze is blowing. Fog is ever present.\n",
"The fog and the breeze produce cold-waves, making your flesh creep.\n",
"The foggy coldness and the cold water make you shiver.\n",
"The ice-cold water starts to weaken you.\n",
"The ice-cold water, now and then gulfing over your head, weakens you.\n",
"Keeping above in the biting cold, rough water, weakens you a lot.\n",
"As you try to keep your head above the water, you're weakening rapidly.\n",
"The ice-cold water, nasty waves, and the cold foggy air are draining you.\n",
"The ice-cold water, mean waves, and the foggish cold air are killing you.\n"
	});
	if (sscanf(file_name(this_object()), "%s#%s", a, b)>=2)
		call_out("clock_tick", quarterticks);
}

depth_description( i ) {
	return depthlong[i];
}

depth_transition_rise( i ) {
	return depth_rise[i];
}

depth_transition_fall( i ) {
	return depth_fall[i];
}

/* arg should be 0..9: corr. depth */
stay_cost( i ) {
	return staycost[i];	
}

/* arg should be 0..9: corr. depth */
move_cost( i ) {
	return movecost[i];	
}

move_text( i ) {
	return movetext[i];
}

stay_text( i ) {
	return staytext[i];
}

dive_text( i ) {
	if (i<3 ) return "You can not dive here!\n";
	if (i<5 ) return "It's to undeep here.\n";
	return "The water is so cold and rough, diving is not done here.\n";
}

long()  { 
	write("This is a very old clock mounted on a solidly grounded pole.\n");
	write( "The shorter hand points to "+hour2latin[hour]
			+", a longer hand points to "+quarter2latin[quarter] + ".\n" );
}

clock_tick() {
	windcol = random(7);
	if (++quarter>3) {
		quarter=0;
		if (++hour>12) hour=1;
	}
	if (++tidetick>=maxtidetick) { /* one tidetick a quarter */
		tidetick=0;  /* every maxtidetick'th tidetick change tide one phase */
		tide_tick();
	}
	call_out("clock_tick", quarterticks);
}

wind_col() { return windcol; }

tide_tick() {
	if (rising) {
		if (++waterlevel>=maxwaterlevel) rising=0;
	}
	else {
		if (--waterlevel<=minwaterlevel) rising=1;
	}	
}

error(str) {
	say(str);
	return 0;
}

print_tide() {
	if (rising) write("The tide is rising.");
	else write("The tide is falling.");
	write(" The waterlevel is "+waterlevel+".\n");
	return 1;
}
