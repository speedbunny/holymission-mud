inherit "room/room";

#define TP this_player()
#define TPRN TP->query_short_name()
#define TPQG TP->query_pronoun()

object obp1,obp2,boom;
int i,j,k,whosgo,tiles1,tiles2,playno,gameover,x,y;
int chx,chy,legal,oldtil1,oldtil2,oldwho,tt1,tt2,takeback;
string player1,player2,board,type,wriboard,oldboard,tempboard;
string number,qg1,qg2,hesheit;
reset (arg) {
	::reset(arg);
	if(!boom) {
		boom=clone_object("/players/portil/funobj/boomerang");
		move_object(boom,this_object());
		}
	if (arg) {return;}
	board=allocate(8);
	oldboard=allocate(8);
	tempboard=allocate(8);
	for(i=0;i<8;i++) {
		board[i]=allocate(8);
		oldboard[i]=allocate(8);
		tempboard[i]=allocate(8);
	}
	qg1="It";
	qg2="It";
	player1="nobody";
	player2="nobody";
	takeback=1;
	whosgo=1;
	gameover=1;
        playno=0;
	wriboard();
       	remove_call_out("nogo");

	set_light(1);
	short_desc="A large board game";
	long_desc="You are standing on a large board game.\n"
		+ "It is othello coded by Portil.\n\n"
		+ "Just type `help othello` for help!\n";

	dest_dir=({
		"/players/portil/games/tree","portal",
	});

	items = ({
		"board", "It is an othello board",
		"portal", "It shines a light blue"
	});
	}

init() {
	::init();

	add_action("board","board");
	add_action("play","play");
	add_action("resign","resign");
	add_action("restart","restart");
	add_action("last","last");
        add_action("help","help");
	add_action("pass","pass");
	add_action("movea","a");
	add_action("moveb","b");
	add_action("movec","c");
	add_action("moved","d");
	add_action("movee","e");
	add_action("movef","f");
	add_action("moveg","g");
	add_action("moveh","h");
	}

board(arg) {
	if(arg) return 0;
	write (wriboard);
	return 1;
	}

wriboard() {
	remove_call_out("nogo");
	call_out("nogo",1800);
	if(gameover==0) {
	wriboard="X is being played by "+player1+". "+capitalize(qg1)+" has "+
	tiles1;
		if(tiles1==1) {
			wriboard+=" tile.\n";
		} else {
			 wriboard+=" tiles.\n";
		}
	wriboard+="O is being played by "+player2+". "+capitalize(qg2)+" has "+
	tiles2;
		if(tiles2==1) {
			wriboard+=" tile.\n\n";
		} else {
	 		wriboard+=" tiles.\n\n";
		}
	}
	if(whosgo==1 && gameover==0) wriboard+="It is "+player1+" to go.\n\n";
	if(whosgo==2 && gameover==0) wriboard+="It is "+player2+" to go.\n\n";	
 	if(gameover==0) {
	prtboard();
	} else {
		wriboard="There isn`t a game in progress at the moment.\n";
		if(player1!="nobody") {
			wriboard+=player1+" is waiting for a partner.\n";
		} else if(player2!="nobody") {
			wriboard+=player2+" is waiting for a partner.\n";
		} else {
			wriboard+="There is nobody registered to play.\n";
		}}
	return ;
	}


prtboard() {
           wriboard+=" A B C D E F G H\n";
           wriboard+="-----------------\n";
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			wriboard+="|"+board[j][i];
               }
               wriboard+="| "+(i+1)+"\n";
               }
               wriboard+="-----------------\n";
                return;
       }

 play(arg) {
       if(arg) {return 0;}
	if(player1=="nobody" && TP!=obp2) {
		if(TP->query_money()<100) {
			write("You need 100 gold coins to play this game.\n"
			+"You don`t have that much.\n");
			return 1;
			}
		TP->add_money(-100);
		write("You pay 100 gold coins.\n");
		obp1=TP;
		player1=TPRN;
		playno++;
                write("You are playing X's\n");
                say(player1+" has registered to play X's\n");
		qg1=capitalize(TPQG);
		wriboard();
		return 1;

        } else if(player2=="nobody" && TP!=obp1) {
		if(TP->query_money()<100) {
			write("You need 100 gold coins to play this game.\n"
			+"You don`t have that much.\n");
			return 1;
			}
		TP->add_money(-100);
		write("You pay 100 gold coins.\n");
		obp2=TP;
		player2=TPRN;
		playno++;
		if(gameover==1) {
			gameover=0;
			}
                write("You are playing O's\n");
                say(player2+" has registered to play O's\n");
		qg2=capitalize(TPQG);
		rstboard();
		return 1;

	} else if(TP==obp1 || TP==obp2) {
                write("Don't be silly. You are already playing.\n");
		return 1;

	} else {
		write ("Sorry but "+player1+" is playing "
 		+player2+" at the moment.\n");
		return 1;
	}}


rstboard() {
	for(i=0;i<8;i++) {
                for(j=0;j<8;j++) {
                        board[j][i]=" ";
		}}
	takeback=1;
        board[3][3]="X";
        board[4][4]="X";
        board[4][3]="O";
        board[3][4]="O";
	tiles1=2;
	tiles2=2;
	write_file("/players/portil/games/whoplays",
	  capitalize(obp1->query_real_name())+" played "+
	  capitalize(obp2->query_real_name())+" at "+ctime(time())+".\n");
	whosgo=1;
	gameover=0;
	wriboard();
	if(environment(obp1)==this_object()) command("board",obp1);
	if(environment(obp2)==this_object()) command("board",obp2);
	return;
	}
	
resign(arg) {
	if(arg) return 0;
	if(TP!=obp1 && TP!=obp2) {
                write("How can you resign if you are not playing?\n");
                return 1;
	} else if(TP==obp1) {
		write("You resign.\n");
		tell_room(environment(TP),"A voice screams: "
                + player1 + " resigned, " + player2 + " wins.\n");
		gameover=1;
		player1="nobody";
		player2="nobody";
                obp1=0;
                obp2=0;
                playno=0;
		wriboard();
		remove_call_out("nogo");

                return 1;
	} else {
		write("You resign.\n");
		tell_room(environment(TP),"A voice screams: "
                + player2 + " resigned, " + player1 + " wins.\n");
		gameover=1;
		player1="nobody";
		player2="nobody";
                obp1=0;
                obp2=0;
                playno=0;
		wriboard();
       		remove_call_out("nogo");
	        return 1;
        }
         return;
          }

restart(arg) {
	if(arg) return 0;
	if(TP!=obp1 && TP!=obp2) {
		write("You have to be playing to do that.\n");
	} else if(gameover==1) {
		write("You have to wait until you have a partner.\n");
	} else {
		tell_room(environment(TP),"The board has been reset"
		+ ".\n");
		rstboard();
		wriboard();
		}
	return 1;
	}

pass(arg) {
	if(arg) return 0;
	if(TP==obp1) {
		if (whosgo==1) {
			whosgo=2;
			tell_room(environment(TP),player1
                      + " has passed. "+player2+" to go.\n");
			wriboard();
			return 1;

		} else { 
			write("It`s not your go.\n");
			return 1;

		}} else if(TP==obp2) {
		if (whosgo==2) {
			whosgo=1;
			tell_room(environment(TP),player2
                     + " has passed. "+player1+" to go.\n");
			wriboard();
			return 1;

		} else { 
			write("It`s not your go.\n");
			return 1;

		}} else {
			write ("You are not playing.\n");
			return 1;
		}
	}

movea(arg) {
	if(!arg) return 0;
	x=0;
	number=arg;
	secondno();
	if(y==-1) return 1;
	makemove();
	return 1;
	}

moveb(arg) {
	if(!arg) return 0;
	x=1;
	number=arg;
	secondno();
	if(y==-1) return 1;
	makemove();
	return 1;
	}

movec(arg) {
	if(!arg) return 0;
	x=2;
	number=arg;
	secondno();
	if(y==-1) return 1;
	makemove();
	return 1;
	}

moved(arg) {
	if(!arg) return 0;
	x=3;
	number=arg;
	secondno();
	if(y==-1) return 1;
	makemove();
	return 1;
	}

movee(arg) {
	if(!arg) return 0;
	x=4;
	number=arg;
	secondno();
	if(y==-1) return 1;
	makemove();
	return 1;
	}

movef(arg) {
	if(!arg) return 0;
	x=5;
	number=arg;
	secondno();
	if(y==-1) return 1;
	makemove();
	return 1;
	}

moveg(arg) {
	if(!arg) return 0;
	x=6;
	number=arg;
	secondno();
	if(y==-1) return 1;
	makemove();
	return 1;
	}

moveh(arg) {
	if(!arg) return 0;
	x=7;
	number=arg;
	secondno();
	if(y==-1) return 1;
	makemove();
	return 1;
	}

secondno() {
	y=-1;	
	tt1=tiles1;
	tt2=tiles2;
	if(TP!=obp1 && TP!=obp2) {
		write("Your not playing.\n");
		return ;
		}
        if(TP==obp1 && whosgo==2 || TP==obp2 && whosgo==1) {
		write("It`s not your go.\n");
		return ;
		}
        if(playno==1) {
			write("You need an opponent.\n");
			return ;
                         }
	sscanf(number,"%d",i);
	if(i<1 || i>8) {
		write("Thats an invalid move.\n");
		return ;
		}
	y=i-1; 
	return ;
	}

makemove() {
	if(board[x][y]!=" ") {
		write("You cant go there. There is already"
                    + " a tile in that square.\n");
		return;
	}
        if(TP==obp1) {
		type="X";
	} else { 
		type="O";
	} 
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			tempboard[i][j]=board[i][j];
		}}
	legal=0;
	chx=-1;
	chy=-1;
	flipem();
	chx=0;
	chy=-1;
	flipem();
	chx=1;
	chy=-1;
	flipem();
	chx=1;
	chy=0;
	flipem();
	chx=1;
	chy=1;
	flipem();
	chx=0;
	chy=1;
	flipem();
	chx=-1;
	chy=1;
	flipem();
        chx=-1;
        chy=0;
	flipem();
        if(legal==0) {
		write("You can`t flip any pieces if you go there.\n");
		return;
       } else if(whosgo==1) {
                tiles1++;
		write("You place an X on the board.\n");
		oldwho=1;
                whosgo=2;
                say(player1+" places an X on the board.\n");
		wriboard();
		command("board",obp1);
		if(environment(TP)==environment(obp2)) command("board",obp2);

	} else {
                tiles2++;
		write("You place an O on the board.\n");
		oldwho=2;
                whosgo=1;
                say(player2+" places an O on the board.\n");
		wriboard();
		if(environment(TP)==environment(obp1)) command("board",obp1);
		command("board",obp2);
       }
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			oldboard[i][j]=tempboard[i][j];
		}}
	oldtil1=tt1;
	oldtil2=tt2;
	takeback=0;
       if(tiles1==0 || (tiles1+tiles2)==64 && tiles1<tiles2) {
	shout("A voice screams: "+player2+
        " beat "+player1+" at othello!\n");
        gameover=1;
        player1="nobody";
        player2="nobody";
        obp1=0;
        obp2=0;
        playno=0;
	wriboard();
       	remove_call_out("nogo");

	} else if(tiles2==0 || (tiles1+tiles2)==64 && tiles2<tiles1) {
	shout("A voice screams: "+player1+
        " beat "+player2+" at othello!\n");
        gameover=1;
        player1="nobody";
        player2="nobody";
        obp1=0;
        obp2=0;
        playno=0;
	wriboard();
       	remove_call_out("nogo");

        }
        else if(tiles1==32 && tiles2==32)  {
        tell_room(environment(TP),"A voice screams: "+player1+" and "
        +player2+" just drew at othello!\n");
        gameover=1;
        player1="nobody";
        player2="nobody";
        obp1=0;
        obp2=0;
        playno=0;
	wriboard();
       	remove_call_out("nogo");

        } return;
       }

flipem() {
	i=x;
	j=y;
        if((i+chx)==-1 || (i+chx)==8 || (j+chy)==-1 || (j+chy)==8) return 0;
        if(board[i+chx][j+chy]==type || board[i+chx][j+chy]==" ") return 0;
       for(k=1;k<9;k++) {
                  i=i+chx;
                  j=j+chy;
      if(i==-1 || j==-1 || i==8 || j==8 || board[i][j]==" ") {
                   return;
                }
        if(board[i][j]==type) break;
            }
        i=x;
        j=y;
          board[i][j]=type;
       for(k=1;k<9;k++) {
                 i=i+chx;
                 j=j+chy;
        if(board[i][j]==type) break;
                 if(whosgo==1) {
                         ++tiles1;
                         --tiles2;
                } else {
                         --tiles1;
                         ++tiles2;
                }
                board[i][j]=type;
             }
            legal=1;
            return;
          }


help(arg) {
	if(arg!="othello") return;
	say(TPRN+" checks out the rules and commands.\n");
	cat ("/players/portil/games/othrules");
	return 1;
         }

last(arg) {
	if(arg) return;
	if(TP!=obp1 && TP!=obp2) {
			write("You can`t do that if you arent playing.\n");
			return 1;
		}
	if(takeback==1) {
		write("You cant do that at the moment.\n");
		return 1;
			}
	if(whosgo==1 && TP!=obp2 || whosgo==2 && TP!=obp1) {
		write("Its your go. You cant use that.\n");
		return 1;
		}
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			board[i][j]=oldboard[i][j];
		}}
	whosgo=oldwho;
	tiles1=oldtil1;
	tiles2=oldtil2;
	takeback=1;
	if(TPQG=="he") hesheit="his"; 
	if(TPQG=="she") hesheit="her"; 
	if(TPQG=="it") hesheit="its"; 
	say(TPRN+" has taken "+hesheit+" move back.\n");
	write("You take your last move back the board.\n");

	wriboard();
	if(environment(obp1)==this_object()) command("board",obp1);
	if(environment(obp2)==this_object()) command("board",obp2);
	return 1;
	}
	
nogo() {
	if(playno==1 && obp1) tell_object(obp1,"You took too long to find a"
		+ " partner.\nYou have been thrown off the othello board.\n");
	if(whosgo==1 && playno==2) {
		if(obp1) tell_object(obp1,"You took too long over your move.\n"
		+" You have been thrown off the othello board.\n");
		if(obp2) tell_object(obp2,player1+" took too long to make"
		+" a move.\nYou have been thrown off the othello board.\n");
	} else if(whosgo==2 && playno==2) {
		if(obp2) tell_object(obp2,"You took too long over your move.\n"
		+" You have been thrown off the othello board.\n");
		if(obp1) tell_object(obp1,player2+" took too long to make"
		+" a move.\nYou have been thrown off the othello board.\n");
	}
        gameover=1;
        player1="nobody";
        player2="nobody";
        obp1=0;
        obp2=0;
        playno=0;
	wriboard();
	remove_call_out("nogo");
	return;
	}
