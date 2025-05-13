check( arg, tp, tr ) {
	string what;
	int i;
	object gem;
	if (sscanf(arg, "pole with %s", what)) {
		if (!present(what,tp)) {
			write("You don't have any "+what+".\n");
			return 1;
		}
		say(tp->query_name()+" touches the pole with "+what+".\n", tp );
		switch(what) {
			case "carbonyx" : i = 0; break;
			case "lilimond" : i = 1; break;
			case "gnomopaz" : i = 2; break;
			case "carbomarine" : i = 3; break;
			case "micropyrith" : i = 4; break;
			case "gnomonyx" : i = 5; break;
			case "lilimaranth" : i = 6; break;
			case "gnomoruby" : i = 7; break;
			case "carbosapphire" : i = 8; break;
			case "gnomathyst" : i = 9; break;
			default : write("Nothing happens.\n"); return 1;
		}	
		gem = present(what+"174",tp);
		if (!gem) {
			write("Nothing happens.\n");
			return 1;
		}
		/* transfer(gem, tr); */
		destruct(gem);
		say("The "+what+" crumbles to dust.\n", tp);
		write("The "+what+" crumbles to dust.\n");
		return 1;
	}
	return 0;
}
