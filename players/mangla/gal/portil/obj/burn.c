int freq,freqplus,dam,damplus;

id(string str) { return(str=="burn"||str=="portilburn"); }

drop() {return 1;}

get() {return 1;}

hitplayer() {
	switch(random(2)) {
	case 0:
	write("You can feel the heat burning your body.\n");
	break;
	case 1:
	write("You feel faint as the heat takes away your energy.\n");
	case 2:
	break;
	write("Your energy seems to be ebbing away in the heat.\n");
	}
	this_player()->hit_player((random(dam)+damplus),3);
	this_player()->show_hp();
	call_out("hitplayer",(random(freq)+freqplus));
	return;
}

set_damage(int a,int b) { dam=a; damplus=b; }
set_frequency(int a,int b) {
	freq=a; freqplus=b;
	hitplayer();
}

destructme() {
	remove_call_out("hitplayer");
	destruct(this_object());
}
