inherit "obj/treasure";

#define TO environment(this_object())

reset(arg) {
	if (arg) return;
	set_id("operator");
	}

get() {return 0;}
int score,score2,fow,ballno,out,rand,scores,arrnum;
string waysofout,waystoscore;

init() {
	::init();

	fow=allocate(4);
	waysofout=allocate(6);
	waystoscore=allocate(8);
	scores=allocate(8);
	fow[0]=-1;
	fow[1]=-1;
	fow[2]=-1;
	fow[3]=-1;


	waysofout[0]="The batter is out lbw.\n";
	waysofout[1]="The batters` stumps are smashed into three pieces.\n";
	waysofout[2]="The batter hits a short ball and goes for a run.\n"
                    +"He doesnt quite make it and is run out.\n";
	waysofout[3]="The batter steps forward from the crease and misses the ball.\n"
		    +"One of the fielder throws the ball at the stumps and hits.\n";
	waysofout[4]="The batter lobs one high in the air and it is easily caught"
		    +" by one of the fielders.\n";
	waysofout[5]="The batter swings his bat back to hit the ball and knocks"
		    +"the stumps down with it.\n";

	waystoscore[0]="Hits the ball to the ground.\n";
	scores[0]=0;
	waystoscore[1]="Hits it away and scores one run.\n";
	scores[1]=1;
	waystoscore[2]="Knocks the ball quite hard and scores two runs.\n";
	scores[2]=2;
	waystoscore[3]="Thumps the ball to the edge of the pitch to score three"
		      +" runs.\n";
	scores[3]=3;
	waystoscore[4]="Hits the ball very hard and gets a boundary. Fours runs.\n";
	scores[4]=4;
	waystoscore[5]="Bang. The ball goes screaming through the air.\n"
		      +"The ball just misses you as it goes for six.\n";
	scores[5]=6;
	waystoscore[6]="The ball goes wide. One run and an extra ball.\n";
	scores[6]=-1;
	waystoscore[7]="The bowler accidently steps over his line before bowling.\n"
		+"A no ball is called from somwhere. One run and an extra ball.\n";
	scores[7]=-1;
	startgame();
        remove_call_out("next_ball");
	call_out("next_ball",20);
	}

startgame() {
		score=0;
		score2=0;
		ballno=1;
		out=0;
		}


next_ball() {
 /*       if(environment(this_player())!=environment(this_object())) return; */
	ballno++;
       if (random(20)==0) {
		howzat();
	} else {
		addrun();
	}
	allover();
        call_out("next_ball",20);
	return 1;
	     }

addrun() {
	rand=random(100);
	if (rand<23) {
		arrnum=0;
	} else if(rand<53) {
		arrnum=1;
	} else if(rand<63) {
		arrnum=2;
	} else if(rand<73) {
		arrnum=3;
	} else if(rand<88) {
		arrnum=4;
	} else if(rand<90) {
		arrnum=5;
	} else if(rand<95) {
		arrnum=6;
	} else if(rand<100) {
		arrnum=7;
	}
	tell_room(TO,"\nThe bowler runs up and hurls the ball skillfully towards the batter.\n");
	tell_room(TO,waystoscore[arrnum]);
	if(scores[arrnum]==-1) {
		score=score+2;
		ballno--;
		}
	score=score+scores[arrnum];
	return 1;
	}

allover() {
	if (ballno==7) {
		ballno=1;
		tell_room(TO,"It is the end of the over. A new bowler takes over"
		+   " and the batters change ends.\n");
		} 
		return 1;
	}

howzat() {
	tell_room(TO,waysofout[random(6)]);
	tell_room(TO,"The batter walks depondently back to the pavillion.\n");
	fow[out]=score;
	out++;
	
	if (out==4) {
		tell_room(TO,"The team is all out for "+score+".\n");
		if (!score2) {
		tell_room(TO,"Team B is now going to bat.\n");
		score2=score;
		score=0;
		out=0;
		ballno=1;
		fow[0]=-1;
		fow[1]=-1;
		fow[2]=-1;
		fow[3]=-1;
	} else {
		if(score2>score) {
		tell_room(TO,"Team A wins!\n");
	} else if(score2<score) {
                tell_room(TO,"Team B wins!\n");
	} else if(score2=score) {
		tell_room(TO,"The game was a draw.\n");
	} 
		tell_room(TO,"Another game is started up immediatley.\n");
		startgame();
	}} else {
		tell_room(TO,"The score is now "+score+" for "+out+".\n");
	}
}

		
