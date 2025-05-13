#define FP find_player("portil")

set_shadow() {
	shadow(FP,1);
}

query_presentation() {
	string name;
	if(query_idle(find_player("portil"))>120) return "Portil seems to be idle. (Take a short while to respond)";

        switch(random(11)) {
		case 0:
			return "Lord Portil fills your screen with his long title.                                                                                                   Oh yes he does.                                                                                    Well if you dont believe me think again.                                                                   In fact he going to have another line.                                                    Eponone tells you: Hello!";
		case 1:
			return "Lord Portil changes his title too often";
		case 2:
			return "Lord Portil lover of all things in the kipper clan";
		case 3:
			return "Lord Portil loves small furry animals (OOo-eerrr)";
		case 4:
			name=capitalize(this_player()->query_real_name());
			return "Lord Portil tells you: "+name+" is the best mudder I know!";
		case 5:
			return "Lord Portil says: Blark is useless at football";
		case 6:
			return "Lord Portil thinks that Manchester United are THE best";
		case 7:
			return "Lord Portil can`t wait to go to Alton Towers!";
		case 8:
			return "Lord Portil eats small animals for fun (Grrrrr)";
		case 9:
			return "Lord Portil pokes you in the eye";
		case 10:
			return "Lagbeast the Xtank addict";
	}
}
