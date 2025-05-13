inherit "/players/steerpike/sims/implode_nicely";

#define SIZE 8

mixed *board;
mixed *last_board;
string player1;
string player2;
object player_ob1;
object player_ob2;
int score1;
int score2;
int playing;
int passed;
string waiting;
string alpha;

// HM compat stuff follows:

subjective(x) { return (x || this_player()) -> query_pronoun(); }
objective(x)  { return (x || this_player()) -> query_objective(); }
possessive(x) { return (x || this_player()) -> query_possessive(); }
format(x)     { return sprintf("%s-=75s\n", x); }
print(x)      { write(format(x)); }

reset(arg)
{
   if (arg) return;
   alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   reset_board();
}

copy_array(arg)
{
   mixed *ret;
   int i;
   ret = allocate(SIZE);
   for (i = 0 ; i < SIZE ; i ++)
      ret[i] = arg[i] + ({ });
   return ret;
}

reset_board(arg)
{
   int i;
   board = allocate(SIZE);
   for (i = 0 ; i < SIZE ; i ++)
      board[i] = allocate(SIZE);
   if (arg) return; /* test */
   board[3] = ({ 0, 0, 0, 2, 1, 0, 0, 0 });
   board[4] = ({ 0, 0, 0, 1, 2, 0, 0, 0 });
   score1 = 2;
   score2 = 2;
   last_board = copy_array(board);
}

alpha(i)
{
   if (i >= 0 && i <= 25)
      return alpha[i .. i];
}

id(str)
{
   return str == "board" || str == "othello" || str == "othello board";
}

short()
{
   return "an Othello board";
}

my_format(str)
{
   int len, foo;
   len = 75 - SIZE * 4;
   foo = len - strlen(str);
   return "                       "[0 .. (len - strlen(str)) / 2] + str + "\n";
}

long()
{
   write(query_long());
}

query_long()
{
   string x, tmp;
   int i, j;
   tmp = "";
   query_playing();
   x = "  +";
   for (i = 0 ; i < SIZE ; i ++)
      x += "---+";
   for (i = 0 ; i < SIZE ; i ++)
   {
      tmp += x;
      switch (i)
      {
	 case 0:
	    if (player1)
	       tmp += my_format(capitalize(player1) + " (O) " + score1);
	    else
	       tmp += my_format("No-one is playing at the moment.");
	    break;
	 case 1:
	    if (player1)
	       tmp += my_format("v");
	    else
	       tmp += "\n";
	    break;
	 case 2:
	    if (player2)
	       tmp += my_format(capitalize(player2) + " (X) " + score2);
	    else
	       tmp += "\n";
	    break;
	 case 4:
	    if (playing)
	    {
	       tmp += my_format(capitalize(playing == 1 ? player1 : player2)
		  + " to play.");
	    } else {
	       tmp += "\n";
	    }
	    break;
	 default:
	    tmp += "\n";
	    break;
      }
      tmp += ((i + 1) + " ");
      for (j = 0 ; j < SIZE ; j ++)
      {
	 switch (board[i][j])
	 {
	    case 0: tmp += "|   "; break;
	    case 1: tmp += "| O "; break;
	    case 2: tmp += "| X "; break;
	 }
      }
      tmp += "|\n";
   }
   tmp += x + my_format("Type \"help othello\" for help.") + "    ";
   for (i = 0 ; i < SIZE ; i ++)
      tmp += alpha(i) + "   ";
   return tmp + "\n";
}

query_playing()
{
   if (!playing)
      return 0;
   if (!player_ob1 || !present(player_ob1, environment()))
   {
      player_ob1 = present(player1, environment());
      if (!player_ob1 && !living(player_ob1))
	 return game_abandoned(player1);
   }
   if (!player_ob2 || !present(player_ob2, environment()))
   {
      player_ob2 = present(player2, environment());
      if (!player_ob2 && !living(player_ob2))
	 return game_abandoned(player2);
   }
   return 1;
}

static game_abandoned(str)
{
   player_ob1 = 0;
   player_ob2 = 0;
   playing = 0;
   tell_room(environment(),
      "The game has been abandoned because " + capitalize(str)
      + " has left.\n");
   return 0;
}

check_all_flips(x, y)
{
   string *flipped;
   flipped = ({ });
   flipped += check_flip(x, y, -1, 0);
   flipped += check_flip(x, y, -1, 1);
   flipped += check_flip(x, y, 0, 1);
   flipped += check_flip(x, y, 1, 1);
   flipped += check_flip(x, y, 1, 0);
   flipped += check_flip(x, y, 1, -1);
   flipped += check_flip(x, y, 0, -1);
   flipped += check_flip(x, y, -1, -1);
   return flipped;
}

check_flip(x, y, xmove, ymove)
{
   int color, i, sz;
   int *poss;
   string *ret;
   color = board[x][y];
   poss = ({ });
   while (1)
   {
      x += xmove;
      y += ymove;
      if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
	 return ({ });
      if (!board[x][y])
	 return ({ });
      if (board[x][y] == color)
      {
	 if (sz = sizeof(poss))
	 {
	    ret = allocate(sz / 2);
	    for (i = 0 ; i < sizeof(poss) ; i += 2)
	    {
	       board[poss[i]][poss[i + 1]] = color;
	       ret[i / 2] = alpha(poss[i + 1]) + (poss[i] + 1);
	    }
	    return ret;
	 }
	 return ({ });
      }
      poss += ({ x, y });
   }
}

query_legal_moves()
{
   int i, j;
   mixed *tmp;
   string *moves;
   moves = ({ });
   for (i = 0 ; i < SIZE ; i ++)
   {
      for (j = 0 ; j < SIZE ; j ++)
      {
	 if (!board[i][j])
	 {
	    tmp = copy_array(board);
	    board[i][j] = playing;
	    if (sizeof(check_all_flips(i, j)))
	    {
	       moves += ({ alpha(j) + (i + 1) });
	       board = copy_array(tmp);
	    }
	    board[i][j] = 0;
	 }
      }
   }
   return moves;
}

update_game_status()
{
   int i, j;
   score1 = 0;
   score2 = 0;
   for (i = 0 ; i < SIZE ; i ++)
   {
      for (j = 0 ; j < SIZE ; j ++)
      {
	 switch (board[i][j])
	 {
	    case 1: score1 ++; break;
	    case 2: score2 ++; break;
	 }
      }
   }
   if (score1 + score2 == SIZE * SIZE)
      game_over("The whole board is filled, and the game is over.");
}

game_over(str)
{
   tell_room(environment(),
      format(str) + "The final score is: " + capitalize(player1) + ": "
      + score1 + ", " + capitalize(player2) + ": " + score2 + ".\n");
   if (score1 > score2)
   {
      tell_object(player_ob1, "You are the winner.\n");
      tell_room(environment(), capitalize(player1) + " is the winner.\n",
	 ({ player_ob1 }));
   } else if (score2 > score1) {
      tell_object(player_ob2, "You are the winner.\n");
      tell_room(environment(), capitalize(player2) + " is the winner.\n",
	 ({ player_ob2 }));
   } else {
      tell_room(environment(),
	 "Phew. That was close! The game ends in a draw.\n");
   }
   playing = 0;
   player_ob1 = 0;
   player_ob2 = 0;
}

init()
{
   if (!interactive(this_player()))
      return;
   add_action("join_game", "join");
   add_action("play_move", "play");
   add_action("play_move", "place");
   add_action("pass_move", "pass");
   add_action("do_moves", "moves");
   add_action("do_oops", "oops");
   add_action("randomplay", "randomplay");
   add_action("resign_game", "resign");
   add_action("help_othello", "help");
}

join_game(str)
{
   object ob;
   string n;
   if (str != "game")
   {
      notify_fail("Join what?\n");
      return 0;
   }
   n = this_player() -> query_real_name();
   if (query_playing())
   {
      write("There is already a game in progress between "
	 + (n == player1 ? "you" : capitalize(player1)) + " and "
	 + (n == player2 ? "you" : capitalize(player2)) + ".\n");
      return 1;
   }
   if (waiting)
   {
      if (n == waiting)
      {
	 write("You are already waiting to join a game.\n");
	 return 1;
      }
      if ((ob = present(waiting, environment())) && living(ob))
      {
	 if (random(2))
	 {
	    write("You have started a game with " + capitalize(waiting)
	       + ". You will play first.\n");
	    tell_object(ob,
	       capitalize(n) + " has started a game with you. "
	       + capitalize(subjective()) + " will play first.\n");
	    tell_room(environment(),
	       capitalize(n) + " has started a game with "
	       + capitalize(waiting) + ". " + capitalize(n)
	       + " will play first.\n", ({ this_player(), ob }));
	    player1 = n;
	    player2 = waiting;
	    player_ob1 = this_player();
	    player_ob2 = ob;
	 } else {
	    write("You have started a game with " + capitalize(waiting)
	       + ". " + capitalize(subjective(ob)) + " will play first.\n");
	    tell_object(ob,
	       capitalize(n)
	       + " has started a game with you. You will play first.\n");
	    tell_room(environment(),
	       capitalize(n) + " has started a game with "
	       + capitalize(waiting) + ". " + capitalize(waiting)
	       + " will play first.\n", ({ this_player(), ob }));
	    player1 = waiting;
	    player2 = n;
	    player_ob1 = ob;
	    player_ob2 = this_player();
	 }
	 waiting = 0;
	 playing = 1;
	 reset_board();
      } else {
	 waiting = 0;
      }
      return 1;
   }
   waiting = n;
   write("You are now waiting to join a game.\n");
   say(capitalize(n) + " is now waiting to join a game.\n");
   return 1;
}

play_move(str)
{
   int x, y;
   mixed flipped;
   string n, s;
   object ob;
   if (!query_playing())
   {
      notify_fail("You can't play a move when there's no game in progress.\n");
      return 0;
   }
   n = this_player() -> query_real_name();
   if (n != player1 && n != player2)
   {
      notify_fail("Doh. You're not even playing in this game.\n");
      return 0;
   }
   if (n == (playing == 1 ? player2 : player1))
   {
      write("It isn't your turn to play.\n");
      return 1;
   }
   if (!str || strlen(str) != 2)
   {
      notify_fail("Syntax: play <square>, eg: play a3, play 6b.\n");
      return 0;
   }
   str = lower_case(str);
   if (str[0] >= '1' && str[0] <= '9')
   {
      x = str[0] - '1';
      y = str[1] - 'a';
      str = capitalize(str[1 .. 1] + str[0 .. 0]);
   } else {
      y = str[0] - 'a';
      x = str[1] - '1';
      str = capitalize(str);
   }
   if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
   {
      notify_fail("That would go off the edge of the board!\n");
      return 0;
   }
   if (board[x][y])
   {
      write("There is already a counter on that square on the board.\n");
      return 1;
   }
   last_board = copy_array(board);
   board[x][y] = playing;
   flipped = check_all_flips(x, y);
   if (sizeof(flipped))
   {
      s = sizeof(flipped) == 1 ? "" : "s";
      flipped = print_nicely(flipped);
      print("You play a counter onto " + str
	 + ", flipping your opponent's tile" + s + " on " + flipped + ".");
      tell_object(playing == 1 ? player_ob2 : player_ob1,
	 format(capitalize(n) + " plays a counter onto " + str
	    + ", flipping your tile" + s + " on " + flipped + "."));
      tell_room(environment(),
	 format(capitalize(n) + " plays a counter onto " + str
	    + ", flipping " + possessive() + " opponent's tile" + s + " on "
	    + flipped + "."), ({ player_ob1, player_ob2 }));
      playing = playing == 2 ? 1 : 2;
      passed = 0;
      update_game_status();
      map_array(users() & all_inventory(environment()), "tell_em",
	 this_object(), query_long());
   } else {
      write("That move does not flip a counter, and is thus illegal.\n");
      board[x][y] = 0;
   }
   return 1;
}

tell_em(ob, str) { tell_object(ob, str); }

pass_move()
{
   int i, j;
   string n;
   mixed *tmp;
   if (!query_playing())
   {
      notify_fail("You can't play when there's no game in progress.\n");
      return 0;
   }
   n = this_player() -> query_real_name();
   if (n != player1 && n != player2)
   {
      notify_fail("Doh. You're not even playing in this game.\n");
      return 0;
   }
   if (n == (playing == 1 ? player2 : player1))
   {
      write("It isn't your turn to play.\n");
      return 1;
   }
   for (i = 0 ; i < SIZE ; i ++)
   {
      for (j = 0 ; j < SIZE ; j ++)
      {
	 if (!board[i][j])
	 {
	    tmp = copy_array(board);
	    board[i][j] = playing;
	    if (sizeof(check_all_flips(i, j)))
	    {
	       write("You cannot pass, as you have legal moves available.\n");
	       board = copy_array(tmp);
	       return 1;
	    }
	    board[i][j] = 0;
	 }
      }
   }
   write("You sigh deeply as you pass.\n");
   say(this_player() -> query_name()
      + " sighs deeply as " + subjective() + " passes " + possessive()
      + " turn.\n");
   if (passed)
   {
      game_over("No plays are possible for either player, so the game ends.");
      return 1;
   }
   passed = 1;
   playing = playing == 2 ? 1 : 2;
   return 1;
}

do_moves()
{
   string n;
   string *m;
   if (!query_playing())
   {
      notify_fail("You can't play when there's no game in progress.\n");
      return 0;
   }
   n = this_player() -> query_real_name();
   if (n != player1 && n != player2)
   {
      notify_fail("Doh. You're not even playing in this game.\n");
      return 0;
   }
   if (n == (playing == 1 ? player2 : player1))
   {
      write("It isn't your turn to play.\n");
      return 1;
   }
   if (sizeof(m = query_legal_moves()))
   {
      print("You may legally place a counter on " + print_nicely(m, "or")
	 + ".");
   } else {
      write("You have no legal plays, and must pass.\n");
   }
   return 1;
}

randomplay()
{
   string n;
   string *m;
   if (!query_playing())
   {
      notify_fail("You can't play a move when there's no game in progress.\n");
      return 0;
   }
   n = this_player() -> query_real_name();
   if (n != player1 && n != player2)
   {
      notify_fail("Doh. You're not even playing in this game.\n");
      return 0;
   }
   if (n == (playing == 1 ? player2 : player1))
   {
      write("It isn't your turn to play.\n");
      return 1;
   }
   if (sizeof(m = query_legal_moves()))
      return play_move(m[random(sizeof(m))]);
   write("You don't have any legal moves, and must pass.\n");
   return 1;
}

do_oops()
{
   string n;
   if (!query_playing())
   {
      notify_fail("You can't take back a move when you're not playing!\n");
      return 0;
   }
   n = this_player() -> query_real_name();
   if (n != player1 && n != player2)
   {
      notify_fail("Doh. You're not even playing in this game.\n");
      return 0;
   }
   if (n == (playing == 1 ? player1 : player2))
   {
      write("It isn't your turn to play.\n");
      return 1;
   }
   if (score1 == 2 && score2 == 2)
   {
      write("You can't take back a move when none have been played.\n");
      return 1;
   }
   playing = (playing == 1 ? 2 : 1);
   board = copy_array(last_board);
   write("You take back your last move.\n");
   say(this_player() -> query_name() + " takes back " + possessive()
      + " last move.\n");
   return 1;
}

resign_game(str)
{
   string n;
   if (str == "game")
   {
      if (query_playing())
      {
	 n = this_player() -> query_real_name();
	 if (n == player1 || n == player2)
	 {
	    write("You resign the game."
	       + capitalize(n == player1 ? player2 : player1) + " has won.\n");
	    say(capitalize(n) + " resigns the game. "
	       + capitalize(n == player1 ? player2 : player1) + " has won.\n");
	    playing = 0;
	    return 1;
	 }
	 notify_fail("Doh. You're not even playing.\n");
      } else {
	 notify_fail("Doh. There isn't even a game in progress.\n");
      }
   } else {
      notify_fail("Resign what?\n");
   }
   return 0;
}

help_othello(str)
{
   if (!str)
   {
      write("Type \"help othello\" for help about playing Othello.\n");
   } else if (lower_case(str) == "othello") {
      if (!(str = read_file("/players/steerpike/games/othello.help")))
	 write("Tell Steerpike to hurry up and write the help for Othello.\n");
      else
	 this_player() -> more("/players/steerpike/games/othello.help");
      return 1;
   }
}
