inherit "/room/room";

#include "/players/matt/defs.h"

status playing, whose_turn;
int *board, *which_ship, *hits, *total_hits;
string *letter;
object *player;
mixed *ships;

reset(arg) {
  if(arg) return;
  letter = ({ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" });
  ships = ({
    ({ "c", "carrier", 5}),
    ({ "b", "battleship", 4}),
    ({ "d", "destroyer", 3}),
    ({ "s", "submarine", 3}),
    ({ "r", "cruiser", 2}),
  });
  init_arrays();
  set_light(1);
  short_desc = "Battleship Room";
  long_desc =
    "    This small room reminds you of the inside of a large ship:\n" +
    "there are mock portholes in the walls, ropes hang from all\n" +
    "corners, and there is a steering wheel off to the side. There\n" +
    "is also, strangely, a small wooden table in the center of the\n" +
    "room with what looks like a game on it, and a sign on the wall.\n";

  dest_dir = ({
    NWCITY + "rooms/gamehall", "out",
  });

  items = ({
    "/room", "The room is modeled after a ship's interior",
    "portholes", "Small glass portholes",
    "walls", "Made of wood, the walls contain portholes",
    "ropes", "Ropes to add to the atmosphere",
    "corners", "Ropes hang from them",
    "steering wheel", "A mock wooden wheel",
    "wheel", "A wooden steering wheel",
    "table", "A small wooden table with a game on it",
    "game", "The game looks like Battleship",
    "sign", "A small sign that you could probably read",
  });
}

init() {
  ::init();
  add_action("read",      "read");
  add_action("rules",     "rules");
  add_action("challenge", "challenge");
  add_action("accept",    "accept");
  add_action("setup",     "setup");
  add_action("show",      "show");
  add_action("guess",     "guess");
  add_action("abort",     "abort");
}

read(arg) {
  if(arg == "sign") {
    write("You read the sign. It says:\n\n");
    write("    Welcome to Matt's Battleship Room. Here you can play\n");
    write("Battleship against another person. Commands are:\n");
    write("  - rules:              Shows you the rules of the game\n");
    write("  - challenge <player>: Challenges another player to a game\n");
    write("  - setup:              Lets you set up your ships\n");
    write("  - show:               Shows you the current boards\n");
    write("  - guess <row> <col>:  Fires at coordinate <row> <col>\n");
    write("  - abort:              Aborts the game\n\n");
    write("    Enjoy!     - Matt\n");
    return 1;
  }
}

rules(arg) {
  if(!arg) {
    TP->more_string(read_file(PATH + "text/batt_rules"));
    return 1;
  }
}

challenge(arg) {
  if(arg) {
    if(player[1]) {
      write("A challenge has already been issued.\n");
      return 1;
    }
    player[0] = TP;
    player[1] = present(arg, TO);
    if(player[1] == TP) {
      write("You can't challenge yourself!!\n");
      return 1;
    }
    if(player[1] && interactive(player[1])) {
      write("You challenge " + player[1]->NAME + " to a game.\n");
      call_out("end_accept", 30);
      TELL(player[1], TP->NAME + " challenges you to a game.\n");
      TELL(player[1], "Type \"accept\" within " +
	   find_call_out("end_accept") + " seconds to play.\n");
      return 1;
    }
    write("That player is not present.\n");
    return 1;
  }
  write("Syntax: challenge <player>\n");
  return 1;
}

accept(arg) {
  if(arg) return;
  if(find_call_out("end_accept")) {
    write("You accept the challenge.\n");
    TELL(player[0], TP->NAME + " accepts your challenge.\n");
    remove_call_out("end_accept");
    return 1;
  }
  write("No challenge has been issued.\n");
  return 1;
}

setup(arg) {
  status num;
  if(!player[0] || !player[1]) {
    write("A challenge first must be accepted.\n");
    return 1;
  }
  if(TP == player[1]) num = 1;
  if(playing || (which_ship[num] >= 4)) {
    write("You have already set up your ships.\n");
    return 1;
  }
  show_board(num);
  write("Place your " + CAP(ships[which_ship[num]][1]) +
	"; Length must be " + ships[which_ship[num]][2] + ": ");
  input_to("do_ship");
  return 1;
}

show(arg) {
  if(!playing) {
    write("You are not playing the game yet.\n");
    return 1;
  }
  if(TP == player[1]) show_board(1);
  else show_board();
  return 1;
}

guess(arg) {
  status num;
  int row, col, coord, i;
  string str;
  object person;
  if(!playing) {
    write("You are not playing the game yet.\n");
    return 1;
  }
  if(TP == player[1]) num = 1;
  if(num != whose_turn) {
    write("It is not your turn.\n");
    return 1;
  }
  if(!arg || (sscanf(arg, "%s %d", str, col) != 2)) {
    write("Guess at which coordinates?\n");
    return 1;
  }
  row = (1 + member_array(CAP(str), letter));
  if((row < 1) || (row > 10) || (col < 1) || (col > 10)) {
    write("Invalid coordinate.\n");
    return 1;
  }
  if(board[!num][row - 1][col - 1] >= 6) {
    write("You've already fired at that coordinate.\n");
    return 1;
  }
  write("You fire at " + CAP(str) + " " + col + ".\n");
  TELL(player[!num], TP->SNAME + " fires at " + CAP(str) + " " +
       col + ".\n");
  coord = board[!num][row - 1][col - 1];
  switch(coord) {
    case 0:
      board[!num][row - 1][col - 1] = 6;
      whose_turn = !whose_turn;
      write("You miss.\n");
      TELL(player[!num], CAP(TP->PRO) + " misses.\n");
      TELL(player[whose_turn], "It's your turn now.\n");
      return 1;
      break;
    case 1..5:
      board[!num][row - 1][col - 1] = coord + 6;
      hits[!num][coord - 1]++;
      total_hits[!num]++;
      write("BOOOOOM!! You " + get_hit(!num, (coord - 1)) + " " +
	    player[!num]->SNAME + "'s " + CAP(ships[(coord - 1)][1]) + "!\n");
      TELL(player[!num], CAP(TP->PRO) + " " + get_hit(!num, (coord - 1)) +
	   "s your " + CAP(ships[(coord - 1)][1]) + "!\n");
      if(total_hits[!num] >= 17) {
	write("You win the game!\n");
	TELL(player[!num], TP->SNAME + " wins the game!\n");
	person = filter_array(users(), "batt_filt", TO);
	for(i = 0; i < sizeof(person); i++)
	  TELL(person[i], player[!num]->SNAME + " shouts: " + TP->SNAME +
	       " sank my Battleship!!\n");
	write_file(LOGS + "battleship.log", TP->SNAME + " beat " +
		   player[!num]->SNAME + " on " + ctime(time()) + ".\n");
	playing = 0;
	whose_turn = 0;
	player[0] = 0;
	player[1] = 0;
	init_arrays();
	return 1;
      }
      whose_turn = !whose_turn;
      TELL(player[whose_turn], "It's your turn now.\n");
      return 1;
      break;
  }
}

abort(arg) {
  status num;
  if(arg) return;
  if(!playing) {
    write("You are not playing.\n");
    return 1;
  }
  if(TP == player[1]) num = 1;
  write("You abort the game.\n");
  TELL(player[!num], TP->SNAME + " aborts the game.\n");
  playing = 0;
  whose_turn = 0;
  player[0] = 0;
  player[1] = 0;
  return 1;
}

end_accept() {
  TELL(player[0], player[1]->SNAME + " fails to accept your challenge.\n");
  TELL(player[1], "Your time has run out.\n");
  player[0] = 0;
  player[1] = 0;
  return 1;
}

do_ship(arg) {
  status num, do_over, already_there;
  int row1, col1, row2, col2, i;
  string str1, str2;
  if(TP == player[1]) num = 1;
  if(arg == "q") {
    write("You abort the game.\n");
    TELL(player[!num], player[num]->SNAME + " aborts the game.\n");
    player[0] = 0;
    player[1] = 0;
    return 1;
  }
  if(sscanf(arg, "%s %d %s %d", str1, col1, str2, col2) != 4) do_over = 1;
  else {
    row1 = (1 + member_array(CAP(str1), letter));
    row2 = (1 + member_array(CAP(str2), letter));
    if((row1 < 1) || (row2 < 1) || (row1 > 10) || (row2 > 10) ||
       (col1 < 1) || (col2 < 1) || (col1 > 10) || (col2 > 10)) {
      write("Invalid coordinate.\n");
      do_over = 1;
    }
    else if(row1 == row2) {
      if(abs(col1 - col2) != (ships[which_ship[num]][2] - 1)) {
	write("The length of the " + ships[which_ship[num]][1] +
	      " must be " + ships[which_ship[num]][2] + ".\n");
	do_over = 1;
      }
      else {
	for(i = (min(col1, col2) - 1); i < max(col1, col2); i++)
	  if(board[num][row2 - 1][i])
	    already_there = 1;
	if(already_there) {
	  write("There is already a ship there.\n");
	  do_over = 1;
	}
	else {
	  write("You place the ship.\n");
	  for(i = (min(col1, col2) - 1); i < max(col1, col2); i++)
	    board[num][row2 - 1][i] = (1 + which_ship[num]);
	  which_ship[num]++;
	  do_over = 1;
	  if(which_ship[num] >= 5) {
	    do_over = 0;
	    TELL(player[!num], TP->SNAME + " finishes placing " +
		 TP->POS + " ships.\n");
	    if(which_ship[!num] >= 5) playing = 1;
	    return 1;
	  }
	}
      }
    }
    else if(col1 == col2) {
      if(abs(row1 - row2) != (ships[which_ship[num]][2] - 1)) {
	write("The length of the " + ships[which_ship[num]][1] +
	      " must be " + ships[which_ship[num]][2] + ".\n");
	do_over = 1;
      }
      else {
	for(i = (min(row1, row2) - 1); i < max(row1, row2); i++)
	  if(board[num][i][col2 - 1])
	    already_there = 1;
	if(already_there) {
	  write("There is already a ship there.\n");
	  do_over = 1;
	}
	else {
	  write("You place the ship.\n");
	  for(i = (min(row1, row2) - 1); i < max(row1, row2); i++)
	    board[num][i][col2 - 1] = (1 + which_ship[num]);
	  which_ship[num]++;
	  do_over = 1;
	  if(which_ship[num] >= 5) {
	    do_over = 0;
	    TELL(player[!num], TP->SNAME + " finishes placing " +
		 TP->POS + " ships.\n");
	    if(which_ship[!num] >= 5) playing = 1;
	    return 1;
	  }
	}
      }
    }
    else do_over = 1;
  }
  if(do_over && player[1]) {
    show_board(num);
    write("Place your " + CAP(ships[which_ship[num]][1]) +
	  "; Length must be " + ships[which_ship[num]][2] + ": ");
    input_to("do_ship");
  }
}
 
show_board(to_whom) {
  int i, j;
  string brd;
  brd =  "\n        YOUR BOARD                    OPPONENT'S BOARD\n" +
    "        ----------                    ----------------\n" +
    "     1 2 3 4 5 6 7 8 9 10            1 2 3 4 5 6 7 8 9 10\n\n";
  for(i = 0; i < 10; i++) {
    brd += " " + letter[i] + "  ";
    for(j = 0; j < 10; j++)
      brd += " " + get_symbol(to_whom, to_whom, i, j);
    brd += "         " + letter[i] + "  ";
    for(j = 0; j < 10; j++)
      brd += " " + get_symbol(to_whom, !to_whom, i, j);
    brd += "\n";
  }
  write(brd + "\n");
  return 1;
}

get_symbol(who, whose, row, col) {
  switch(board[whose][row][col]) {
    case 0:
      return ".";
      break;
    case 1..5:
      if(whose == who)
	return CAP(ships[board[who][row][col] - 1][0]);
      else return ".";
      break;
    case 6:
      return "o";
    case 7..11:
      if(whose == who)
	return "*";
      else return CAP(ships[board[whose][row][col] - 7][0]);
      break;
  }
}

get_hit(who, shipnum) {
  if(hits[who][shipnum] >= ships[shipnum][2]) return "sink";
  return "hit";
}

abs(num) {
  if(num >= 0) return num;
  return (- num);
}

min(num1, num2) {
  if(num1 < num2) return num1;
  return num2;
}

max(num1, num2) {
  if(num1 > num2) return num1;
  return num2;
}

batt_filt(obj) { return (obj != player[0]) && (obj != player[1]); }

init_arrays() {
  int i;
  player = allocate(2);
  which_ship = allocate(2);
  total_hits = allocate(2);
  hits = allocate(2);
  hits[0] = allocate(5);
  hits[1] = allocate(5);
  board = allocate(2);
  board[0] = allocate(10);
  board[1] = allocate(10);
  for(i = 0; i < 10; i++) {
    board[0][i] = allocate(10);
    board[1][i] = allocate(10);
  }
  return 1;
}

query_full() {
  int i, counter;
  object inv;
  inv = all_inventory(TO);
  for(i = 0; i < sizeof(inv); i++)
    if(interactive(inv[i])) counter++;
  if(counter >= 2) return 1;
}
