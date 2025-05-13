string *problems;
mixed *solutions;
int current_problem;

reset(arg) {
  if(!arg || current_problem==-1) current_problem=random(6);
  if(arg) return;
  problems=({ "........\n.....P..\n....r.K.\n........\n"
	+ "........\n........\n........\n.......k\n",
	"....r.k.\n...qP..p\n......p.\n.p......\n"
	+ "p......Q\nP....RP.\n.......P\n......K.\n",
	"..kq....\np.pn..P.\nP.p.p...\n........\n"
	+ "K.......\n.P...N..\n...R.P..\n........\n",
	"..k.....\np.p..R.Q\n.pq.p.r.\n....p...\n"
	+ "........\n..P.....\nPP....r.\n..KR....\n",
	"...k....\n........\n........\np......p\n"
	+ "P......P\n........\n..K.....\n........\n",
	".....rk.\n.pqr.ppp\np.n.pn..\n........\n"
	+ "....P..Q\n.PN.R...\nPB...PPP\n.....RK.\n" });
  solutions=({ ({ "kg5", "k-n5", "k-kt5", "g6g5", "g6-g5", "k-g5", "k - n5",
	"g6 - g5", "k - g5" }),
	({ "rf8", "r-f8", "f3f8", "f3-f8", "r-f8", "r - f8", "f3 - f8",
	"r - f8" }),
	({ "rd7", "rxq", "r-q7", "rxd7", "d2d7", "d2-d7", "d2xd7", "r-d7",
	"r x q", "r - q7", "r x d7", "d2 - d7", "d2 x d7", "r - d7" }),
	({ "rd8", "r-q8", "d1d8", "d1-d8", "r-d8", "r - q8", "d1 - d8",
	"r - d8" }),
	({ "k-q2", "kd2", "c2d2", "c2-d2", "k-d2", "k - q2", "c2 - d2",
	"k - d2", }),
	({ "n-q5", "nd5", "c3d5", "c3-d5", "n-d5", "n - q5", "c3 - d5",
	"n - d5" }) });

  move_object(this_object(),"players/moonchild/gnome/pub");
}


id(str) { return str=="problem" || str=="chess problem"; }

short() { return "Chess problem"; }

long() {
  write(!present("player",environment()) ?
	"The pieces are scattered everywhere.\n" :
	current_problem==-1 ? "The chess player looks tired.\n" :
	"The current position is:\n\n" + show_prob(problems[current_problem])
	+ "\nWhite (capital letters) to play and win.\n"
	+ "The chess player understands many forms of notation, eg:\n"
	+ "N-K2, Ne2, G1E2.... (or so we have been told).\n");
  return;
}

show_prob(str) {
  string *lines,res;
  int i;
  res="";
  lines=explode(str,"\n");
  for(i=0;i<8;i++) res+=((8-i) + " " + lines[i] + "\n");
  return res+"\n  abcdefgh\n";
}

new_problem(arg) {
  int old_pr;
  if(arg==3) current_problem=-1;
  else {
    old_pr=current_problem;
    while(current_problem==old_pr) current_problem=random(6);
  }
}

check_answer(str) {
  int i;
  status flag;
  if(current_problem==-1) return 0;
  str=lower_case(str);
  for(i=0;i<sizeof(solutions[current_problem]);i++)
	if(str==solutions[current_problem][i]) return 1;
  return 0;
}
