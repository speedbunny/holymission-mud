inherit "obj/monster";

#include "pieces.h" /* include piece integer codes */
/* hack & slashers who try to kill me are transfered to: */
#define DEST "/players/gladiator/chess/chesse4"

int moves,board,color,wx,wy,bx,by;
object player,alt_player;
status board_allocated,busy,move,wking,bking,wrook,brook;

reset(arg) {
  ::reset(arg);

  if (arg) return;
  set_name("chessmaster");
  set_alias("master");
  set_alt_name("player");
  set_short("The chessmaster");
  set_long("This is the chessmaster, he is very old and very wise.\n"+
           "He only likes to play chess, but DON'T KILL him! It is\n"+
           "said he has some sort of magic. If you want to play chess \n"+
           "just type <help chess> for more info.\n");
  load_chat(5,({"Chessmaster says: Come and play chess with your friends.\n",
                "Chessmaster says: I can't play chess(yet).\n",
                "Chessmaster says: I am still a beta version!\n",
                "Chessmaster moans: They're coding my brains right now!\n",}));
  set_race("hobbit");
  /* set_size(2); */
  set_gender(1);
  set_level(10);
  set_hp(700);
  set_al(500);
  set_wc(10);
  set_ac(20);
  set_aggressive(0);
  add_money(1000 + random(1000));
  set_whimpy(-1);
  busy=0;
  color=1;
  allocate_board();
  board_allocated=1;
}


init() {
  ::init();
add_action("info_chess","help");
add_action("parse_move","move");
add_action("challenge","challenge");
add_action("board","board");
add_action("end_it","st");
add_action("test","testcheck");
}

test(arg)
{
  write(check(1)+".\n");
  write(check(-1)+".\n");
  return 1;
}

info_chess(arg) {
  if (arg == "chess" || arg == "Chess")
   {
     write("\nHow to play chess with a player or with the chessmaster.\n"+
           "--------------------------------------------------------\n\n"+                 "It's like a standard chess game, you can either challenge\n"+
           "a player or challenge lpmud itself by challenging the \n"+
           "chessmaster.(Brains ver 0.91[beta])\n"+
           "To challenge a player type challenge <name>.\n"+
           "To challenge lpmud type challenge chessmaster.\n\n"+
           "Further help :\n"+
           "<help pieces>, for help on abreviation on pieces.\n"+
           "<help move>, how to move your pieces.\n"+
           "<help options>, for help on extra stuff.\n\n"+
           "If you find any bugs or do have some suggestions,\n"+
           "please mail me here or email me,\n\n"+
           "                         Shaka\n"+
           "           email:STU_ROEST@hrovx1.hro.nl\n"+
           "Credits: Xanathar the beholder, Gladiator and Bert.\n");
     return 1;
   }
  if (arg == "pieces" || arg == "Pieces")
   {
     write("\nThis chess uses the following abreviations for chess pieces.\n"+
           "Black pieces will be written in CAPITAL letters\n"+
           "The pieces:\n"+
           "piece           white           black\n"+
           "-------------------------------------\n"+
           "king              k               K  \n"+
           "queen             q               Q  \n"+
           "bishop            b               B  \n"+
           "knight            n               N  \n"+
           "rook              r               R  \n"+
           "pawn              p               P  \n");
     return 1;
   }
  if (arg == "move" || arg == "Move")
   {
    write("\nThe board looks like this:\n"+
     "   +---+---+---+---+---+---+---+---+   +---+\n"+
     " 8 | R |=N=| B |=Q=| K |=B=| N |=R=|   |   | white square\n"+
     "   +---+---+---+---+---+---+---+---+   +---+\n"+
     " 7 |=P=| P |=P=| P |=P=| P |=P=| P |\n"+
     "   +---+---+---+---+---+---+---+---+   +---+\n"+
     " 6 |   |===|   |===|   |===|   |===|   |===| black square\n"+
     "   +---+---+---+---+---+---+---+---+   +---+\n"+
     " 5 |===|   |===|   |===|   |===|   |\n"+
     "   +---+---+---+---+---+---+---+---+\n"+
     " 4 |   |===|   |===|   |===|   |===|\n"+
     "   +---+---+---+---+---+---+---+---+\n"+
     " 3 |===|   |===|   |===|   |===|   |\n"+
     "   +---+---+---+---+---+---+---+---+\n"+
     " 2 | p |=p=| p |=p=| p |=p=| p |=p=|\n"+
     "   +---+---+---+---+---+---+---+---+\n"+
     " 1 |=r=| n |=b=| q |=k=| b |=n=| r |\n"+
     "   +---+---+---+---+---+---+---+---+\n"+
     "     a   b   c   d   e   f   g   h\n"+
     "Moving is like the normal thing:<move e2-e4> should\n"+
     "move the pawn from e2 to e4, the chessmaster will\n"+
     "check for castling enpassant etc etc.\n");
     return 1;
   }
  if (arg == "options" || arg =="Options")
   {
     write("\nThe optional and usefull stuff:\n\n"+
           "giveup : seems obvious :-)\n"+
           "load   : load a previous game(one saved game a player)\n"+
           "save   : save the current layout of the board.\n"+
           "quit   : quits with playing, chessmaster will prompt you\n"+
           "         if you want to save.\n"+
           "new    : start a new game.\n"+
           "moves  : displays the current number of moves.\n");
     return 1;
   }

} /* end of chess_info(arg) */

challenge(str)
{
  if(busy)
   {
     write("Somebody else is already playing chess!\n");
     return 1;
   }
  if(!str)
   {
     write("Challenge whom?\n");
     return 1;
   }
  busy=1;
  player=this_player();
  alt_player=present(str,environment(this_object()));
  if(!alt_player)
   {
     write("No such player here!\n");
     busy=0;
     return 1;
   }
  if(alt_player==player)
   {
     write("Challenge yourself? I don't think so!\n");
     busy=0;
     alt_player=0;
     player=0;
     return 1;
   }
  if(alt_player==this_object())
   {
     write("I'm not yet ready to play chess!, you can challenge\n"
          +"another player though.\n");
     busy=0;
     alt_player=0;
     player=0;
     return 1;
   }
  tell_object(alt_player,"You've been challenged for a game of chess by "+
                          player->query_name()+".\n");
  color=1;
  tell_room(environment(this_object()),player->query_name()+" plays white.\n"+
                                   alt_player->query_name()+" plays black.\n");
  fill_board();
  log_file("chessmaster.games",ctime(time())+" "+player->query_real_name()+
           " challenged "+alt_player->query_real_name()+
           " for a game of chess.\n");
  load_chat(1,({"Chessmaster scratches his head.\n",
                "Chessmaster says: This is tricky.\n",
                "Chessmaster takes a look at the chessboard.\n",}));
  return 1;
} /* end of challenge() */

end_it()
{
   tell_room(environment(this_object()),"Chessgame has been terminated by: "
           +this_player()->query_name()+".\n");
   load_chat(5,({"Chessmaster says: Come and play chess with your friends.\n",
                   "Chessmaster says: I can't play chess(yet).\n",
                   "Chessmaster says: I am still a beta version!\n",
                   "Chessmaster moans: They're coding my brains right now!\n",}));
   player=0;
   alt_player=0;
   busy=0;
   move=0;
   return 1;
} /* end of end_it() */

board()
{
   write("You take a good look at the chessboard.\n");
   say(this_player()->query_name()+" takes a look at the chessboard.\n",
       this_player());
   display_board();
   return 1;
}

parse_move(arg)
{
string prefix,suffix;
int xs,ys,xe,ye;
status error;

  if(move) return 0;
  if(!busy)
   {
     write("No game in progress!\n");
     return 1;
   }
  if( (color==1 && (this_player()!=player)) )
   {
     write("It's not your time to move!\n");
     return 1;
   }
  if( (color==-1 && (this_player()!=alt_player)) )
   {
     write("It's not your time to move!\n");
     return 1;
   }
  if(!arg)
   {
     write("Please give an argument for a move!\n");
     return 1;
   }
  move=1;
  if(sscanf(arg,"%s-%s",prefix,suffix) !=2)
   {
     write("Error in your move syntax!\n");
     move=0;
     return 1;
   }
  xs=convert_x(prefix);
  if(xs<0)
   {
     write("Illegal x-character in first move-coordinate(a..h only)\n");
     move=0;
     return 1;
   }
  ys=convert_y(prefix);
  if(ys<0)
   {
     write("Illegal y-number in first move-coordinate(1..8 only)\n");
     move=0;
     return 1;
   }
  xe=convert_x(suffix);
  if(xe<0)
   {
     write("Illegal x-character in second move-coordinate(a..h only)\n");
     move=0;
     return 1;
   }
  ye=convert_y(suffix);
  if(ye<0)
   {
     write("Illegal y-number in second move-coordinate(1..8 only)\n");
     move=0;
     return 1;
   }
  error=check_it(xs,ys,xe,ye,color);
  if(!error)
   {
     if(color==1) color=-1; else color=1;
     say(this_player()->query_real_name()+
         " moves a piece on the chessboard.\n");
   }
  display_board();
  move=0;
  return 1;
} /* end of parse_move() */

convert_x(str)
{
int ret_code,i;

  ret_code=-1;
  i=str[0];
  switch(i)
   {
     case 97  : ret_code=0;
                break;
     case 98  : ret_code=1;
                break;
     case 99  : ret_code=2;
                break;
     case 100 : ret_code=3;
                break;
     case 101 : ret_code=4;
                break;
     case 102 : ret_code=5;
                break;
     case 103 : ret_code=6;
                break;
     case 104 : ret_code=7;
                break;
   }
  return ret_code;
} /* end of convert_x() */

convert_y(str)
{
int ret_code,i;

  ret_code=-1;
  i=str[1];
  switch(i)
   {
     case 49 : ret_code=0;
               break;
     case 50 : ret_code=1;
               break;
     case 51 : ret_code=2;
               break;
     case 52 : ret_code=3;
               break;
     case 53 : ret_code=4;
               break;
     case 54 : ret_code=5;
               break;
     case 55 : ret_code=6;
               break;
     case 56 : ret_code=7;
               break;
   }
  return ret_code;
} /* end of convert_x() */


allocate_board()
{
  board=allocate(64);
  return;
} /* end of allocate_board() */

/* the next 2 routines will translate 2-dimensional to a 1-dimensional
   array */

put_piece(x,y,code)
{
int index;

  index=x+(8*y);
  board[index]=code;
  return;
} /* end of put_piece() */

square(x,y)
{
int index,val;

  index=x+(8*y);
  if(index<0 || index>63) return OUT_OF_BORDER;
  val=board[index];
  return val;
} /*end of square() */

fill_board()
{
int i;
  for(i=0;i<=63;i++)
   board[i]=0;
  for(i=0;i<=7;i++) /* remember array goes 0..7 not 1..8 ! */
   {
     put_piece(i,1,PAWN);
     put_piece(i,6,-PAWN);
   }
  put_piece(0,0,ROOK);   put_piece(0,7,-ROOK);
  put_piece(1,0,KNIGHT); put_piece(1,7,-KNIGHT);
  put_piece(2,0,BISHOP); put_piece(2,7,-BISHOP);
  put_piece(3,0,QUEEN);  put_piece(3,7,-QUEEN);
  put_piece(4,0,KING);   put_piece(4,7,-KING);
  put_piece(5,0,BISHOP); put_piece(5,7,-BISHOP);
  put_piece(6,0,KNIGHT); put_piece(6,7,-KNIGHT);
  put_piece(7,0,ROOK);   put_piece(7,7,-ROOK);
  wx=4;wy=0;bx=4;by=7;
  wking=0;bking=0;wrook=0;brook=0;
  return;
}/* end of fill_board() */

abs(val)
{
  if (val>=0) return val;
  return -val;
} /* end of abs() */

display_board()
{
int x,y;
status blk; /* is the square black or white? */
string bk;

 write("+---+---+---+---+---+---+---+---+\n");
 blk=0;
 for(y=7;y>=0;y--)
  {
    write("|");
    for(x=0;x<=7;x++)
     {
       if(blk) bk="="; else bk=" ";
       switch(square(x,y))
        {
          case -KING   : write(bk+"K"+bk+"|");
                         break;
          case -QUEEN  : write(bk+"Q"+bk+"|");
                         break;
          case -BISHOP : write(bk+"B"+bk+"|");
                         break;
          case -KNIGHT : write(bk+"N"+bk+"|");
                         break;
          case -ROOK   : write(bk+"R"+bk+"|");
                         break;
          case -PAWN   : write(bk+"P"+bk+"|");
                         break;
          case  EMPTY  : write(bk+bk+bk+"|");
                         break;
          case  PAWN   : write(bk+"p"+bk+"|");
                         break;
          case  ROOK   : write(bk+"r"+bk+"|");
                         break;
          case  KNIGHT : write(bk+"n"+bk+"|");
                         break;
          case  BISHOP : write(bk+"b"+bk+"|");
                         break;
          case  QUEEN  : write(bk+"q"+bk+"|");
                         break;
          case  KING   : write(bk+"k"+bk+"|");
                         break;
        }
       blk=(!blk);
     }
    write(" "+(y+1)+"\n");
    write("+---+---+---+---+---+---+---+---+\n");
    blk=(!blk);
  }
 write("  A   B   C   D   E   F   G   H \n");
} /* end of display_board() */

check_border(x,y,player)
{
int i; /* this will be returned */
status noway;

  noway=0;
  if( (x<0) || (y<0) || (x>7) || (y>7) ) noway=1;
  if (!noway)
   {
    i=0;
    if(square(x,y)*player>0) i=1; /* collision with own piece color */
    if(square(x,y)*player<0) i=2; /* collision with other piece */
   }
  if (noway) i=3;
  return i;
} /* end of int check_border() */

check_pawn(xs,ys,xe,ye,clr)
{
status error; /* this will be returned */

  if( (clr>0) && (ys>ye) ) error=1;
  if ( (clr<1) && (ys<ye) ) error=1;
  /* exceptions row 1 and 6 */
  if( (ys!=6) && (clr<0) && (abs(ys-ye)!=1) ) error=1;
  if ( (ys==6) && (clr<0) )
   {
    if (abs(ys-ye)>2) error=1;
    if (square(xs,ys-1) != 0) error=1;
   }
  if ( (ys!=1) && (clr>0) && (abs(ys-ye)!=1) ) error=1;
  if ( (ys==1) && (clr>0) )
   {
    if (abs(ys-ye)>2) error=1;
    if (square(xs,ys+1) != 0) error=1;
   }
  if (!error)
   {
    if(abs(xs-xe)>1) error=1; /* no diagonal please! */
    if( (abs(xs-xe)==1) && (square(xe,ye)*clr>=0) ) error=1;
    if( (abs(xs-xe)==0) && (square(xe,ye)!=0) ) error=1;
   }
  return error;
} /* end of status check_pawn() */


check_line(xs,ys,xe,ye,dx,dy,clr)
{
int coll;
status error; /* This will be returned */

  coll=0;
  error=1;
  while(!coll && error)
   {
     xs=xs+dx;
     ys=ys+dy;
     coll=check_border(xs,ys,clr);
     if ( (xs==xe) && (ys==ye) && (coll!=3) && (coll!=1) ) error=0;
   }
  return error;
} /* end of check_line() */

check_rook(xs,ys,xe,ye,clr)
{
int dx,dy;
int xm,ym;
status error; /* this will be returned */

 error=1;
  xm=xs;ym=ys;
  dx=-1;dy=0;
   error=check_line(xs,ys,xe,ye,dx,dy,clr);
  if(!error) return error;
  xs=xm;ys=ym;
  dx=1;dy=0;
   error=check_line(xs,ys,xe,ye,dx,dy,clr);
  if(!error) return error;
  xs=xm;ys=ym;
  dx=0;dy=1;
   error=check_line(xs,ys,xe,ye,dx,dy,clr);
  if(!error) return error;
  xs=xm;ys=ym;
  dx=0;dy=-1;
   error=check_line(xs,ys,xe,ye,dx,dy,clr);
  return error;
} /* end of check_rook() */

check_bishop(xs,ys,xe,ye,clr)
{
int dx,dy;
int xm,ym;
status error; /* this will be returned */

 error=1;
  xm=xs;ym=ys;
  dx=-1;dy=-1;
   error=check_line(xs,ys,xe,ye,dx,dy,clr);
  if(!error) return error;
  xs=xm;ys=ym;
  dx=1;dy=1;
   error=check_line(xs,ys,xe,ye,dx,dy,clr);
  if(!error) return error;
  xs=xm;ys=ym;
  dx=-1;dy=1;
   error=check_line(xs,ys,xe,ye,dx,dy,clr);
  if(!error) return error;
  xs=xm;ys=ym;
  dx=1;dy=-1;
   error=check_line(xs,ys,xe,ye,dx,dy,clr);
  return error;
} /* end of check_bishop() */

check_knight(xs,ys,xe,ye,clr)
{
status error; /* this will be returned */

  error=1;
   if( (xs+1==xe) && (ys+2==ye) ) error=0;
   if( (xs+1==xe) && (ys-2==ye) ) error=0;
   if( (xs+2==xe) && (ys+1==ye) ) error=0;
   if( (xs+2==xe) && (ys-1==ye) ) error=0;
   if( (xs-1==xe) && (ys+2==ye) ) error=0;
   if( (xs-1==xe) && (ys-2==ye) ) error=0;
   if( (xs-2==xe) && (ys+1==ye) ) error=0;
   if( (xs-2==xe) && (ys=1==ye) ) error=0;
  return error;
} /* end of check_knight() */

check_king(xs,ys,xe,ye,clr)
{
status error; /* this will be returned */

  error=1;
   if( (xs+1==xe) && (ys+1==ye) ) error=0;
   if( (xs+1==xe) && (ys+0==ye) ) error=0;
   if( (xs+1==xe) && (ys-1==ye) ) error=0;
   if( (xs+0==xe) && (ys+1==ye) ) error=0;
   if( (xs+0==xe) && (ys-1==ye) ) error=0;
   if( (xs-1==xe) && (ys+1==ye) ) error=0;
   if( (xs-1==xe) && (ys+0==ye) ) error=0;
   if( (xs-1==xe) && (ys-1==ye) ) error=0;
    if( (square(xe,ye)*clr==-KING)) error=1;/* wanna take another king, noway */
  return error;
} /* end of check_king() */

check_queen(xs,ys,xe,ye,clr)
{
status error; /* this will be returned */
int dx,dy;
int xm,ym;

  error=1;
   xm=xs;ym=ys;
   dx=-1;dy=0;
    error=check_line(xs,ys,xe,ye,dx,dy,clr);
   if(!error) return error;
   xs=xm;ys=ym;
   dx=1;dy=0;
    error=check_line(xs,ys,xe,ye,dx,dy,clr);
   if(!error) return error;
   xs=xm;ys=ym;
   dx=0;dy=1;
    error=check_line(xs,ys,xe,ye,dx,dy,clr);
   if(!error) return error;
   xs=xm;ys=ym;
   dx=0;dy=-1;
    error=check_line(xs,ys,xe,ye,dx,dy,clr);
   if(!error) return error;
   xs=xm;ys=ym;
   dx=-1;dy=-1;
    error=check_line(xs,ys,xe,ye,dx,dy,clr);
   if(!error) return error;
   xs=xm;ys=ym;
   dx=1;dy=1;
    error=check_line(xs,ys,xe,ye,dx,dy,clr);
   if(!error) return error;
   xs=xm;ys=ym;
   dx=-1;dy=1;
    error=check_line(xs,ys,xe,ye,dx,dy,clr);
   if(!error) return error;
   xs=xm;ys=ym;
   dx=1;dy=-1;
    error=check_line(xs,ys,xe,ye,dx,dy,clr);
  return error;
} /* end of check_queen() */

check_piece(x,y,piece)
{
int i; /* this is returned */
status noway;
  i=3;
  noway=0;
  if( (x<0) || (y<0) || (x>7) || (y>7) ) noway=1;
  if (!noway)
   {
    if(square(x,y)==piece) i=1; /* collision with own piece color */
    if(square(x,y)==EMPTY) i=2; /* empty square */
   }
  if (noway) i=3;
  return i;
} /* end of check_piece() */

query_king(x,y,clr)
{
status found; /* this will be returned */

  found=0;
  if(clr==WHITE)
   {
     if( (x+1==bx) && (y+1==by) ) found=1;
     if( (x+1==bx) && (y+0==by) ) found=1;
     if( (x+1==bx) && (y-1==by) ) found=1;
     if( (x+0==bx) && (y+1==by) ) found=1;
     if( (x+0==bx) && (y-1==by) ) found=1;
     if( (x-1==bx) && (y+1==by) ) found=1;
     if( (x-1==bx) && (y+0==by) ) found=1;
     if( (x-1==bx) && (y-1==by) ) found=1;
   }
  else
   {
     if( (x+1==wx) && (y+1==wy) ) found=1;
     if( (x+1==wx) && (y+0==wy) ) found=1;
     if( (x+1==wx) && (y-1==wy) ) found=1;
     if( (x+0==wx) && (y+1==wy) ) found=1;
     if( (x+0==wx) && (y-1==wy) ) found=1;
     if( (x-1==wx) && (y+1==wy) ) found=1;
     if( (x-1==wx) && (y+0==wy) ) found=1;
     if( (x-1==wx) && (y-1==wy) ) found=1;
    }
  return found;
} /* end of query_king() */

query_pawn(x,y,clr)
{
status check; /* this is returned */

  check=0;
  if(clr==WHITE)
   {
     if(square(x+1,y+1)==-PAWN) check=1;
     if(square(x-1,y+1)==-PAWN) check=1;
   }
  else
   {
     if(square(x+1,y-1)==PAWN) check=1;
     if(square(x-1,y-1)==PAWN) check=1;
   }
  return check;
} /* end of query_pawn() */

check_for(x,y,dx,dy,code)
{
int i;
status found; /* This will be returned */

  i=2;
  found=1;
  while(i==2)
   {
     x=x+dx;
     y=y+dy;
     i=check_piece(x,y,code);
     if(i==3) found=0;
   }
  return found;
} /* end of check_for() */

query_rook(x,y,clr)
{
int dx,dy;
int xm,ym;
status check; /* this will be returned */

 check=0;
  xm=x;ym=y;
  dx=-1;dy=0;
   check=check_for(x,y,dx,dy,-clr*ROOK);
  if(check) return check;
  x=xm;y=ym;
  dx=1;dy=0;
   check=check_for(x,y,dx,dy,-clr*ROOK);
  if(check) return check;
  x=xm;y=ym;
  dx=0;dy=1;
   check=check_for(x,y,dx,dy,-clr*ROOK);
  if(check) return check;
  x=xm;y=ym;
  dx=0;dy=-1;
   check=check_for(x,y,dx,dy,-clr*ROOK);
  return check;
} /* end of query_rook() */

query_knight(x,y,clr)
{
status check; /* this is returned */

  check=0;
   if(square(x+2,y+1)==-clr*KNIGHT) check=1;
   if(square(x-2,y+1)==-clr*KNIGHT) check=1;
   if(square(x+2,y-1)==-clr*KNIGHT) check=1;
   if(square(x-2,y-1)==-clr*KNIGHT) check=1;
   if(square(x+1,y+2)==-clr*KNIGHT) check=1;
   if(square(x-1,y+2)==-clr*KNIGHT) check=1;
   if(square(x+1,y-2)==-clr*KNIGHT) check=1;
   if(square(x-1,y-2)==-clr*KNIGHT) check=1;
  return check;
} /* end of query_knight() */

query_bishop(x,y,clr)
{
int dx,dy;
int xm,ym;
status check; /* this will be returned */

 check=0;
  xm=x;ym=y;
  dx=-1;dy=-1;
   check=check_for(x,y,dx,dy,-clr*BISHOP);
  if(check) return check;
  x=xm;y=ym;
  dx=1;dy=1;
   check=check_for(x,y,dx,dy,-clr*BISHOP);
  if(check) return check;
  x=xm;y=ym;
  dx=-1;dy=1;
   check=check_for(x,y,dx,dy,-clr*BISHOP);
  if(check) return check;
  x=xm;y=ym;
  dx=1;dy=-1;
   check=check_for(x,y,dx,dy,-clr*BISHOP);
  return check;
} /* end of query_rook() */

query_queen(x,y,clr)
{
status check;
int dx,dy;
int xm,ym;

  check=0;
   xm=x;ym=y;
   dx=1;dy=0;
    check=check_for(x,y,dx,dy,-clr*QUEEN);
   if(check) return check;
   x=xm;y=ym;
   dx=-1;dy=0;
    check=check_for(x,y,dx,dy,-clr*QUEEN);
   if(check) return check;
   x=xm;y=ym;
   dx=0;dy=1;
    check=check_for(x,y,dx,dy,-clr*QUEEN);
   if(check) return check;
   x=xm;y=ym;
   dx=0;dy=-1;
    check=check_for(x,y,dx,dy,-clr*QUEEN);
   if(check) return check;
   x=xm;y=ym;
   dx=1;dy=1;
    check=check_for(x,y,dx,dy,-clr*QUEEN);
   if(check) return check;
   x=xm;y=ym;
   dx=-1;dy=-1;
    check=check_for(x,y,dx,dy,-clr*QUEEN);
   if(check) return check;
   x=xm;y=ym;
   dx=1;dy=-1;
    check=check_for(x,y,dx,dy,-clr*QUEEN);
   if(check) return check;
   x=xm;y=ym;
   dx=-1;dy=1;
    check=check_for(x,y,dx,dy,-clr*QUEEN);
  return check;
} /* end of query_queen() */

check(colr)
{
status chk;

  chk=0;
  if(colr==WHITE)
   {
     chk=query_queen(wx,wy,WHITE);
     if(chk) return chk;
     chk=query_rook(wx,wy,WHITE);
     if(chk) return chk;
     chk=query_bishop(wx,wy,WHITE);
     if(chk) return chk;
     chk=query_knight(wx,wy,WHITE);
     if(chk) return chk;
     chk=query_pawn(wx,wy,WHITE);
     if(chk) return chk;
     chk=query_king(wx,wy,WHITE);/*not a real check, but no adjacment kings!*/
     if(chk) return chk;
     return 0;
   }
  else
   {
     chk=query_queen(bx,by,BLACK);
     if(chk) return chk;
     chk=query_rook(bx,by,BLACK);
     if(chk) return chk;
     chk=query_bishop(bx,by,BLACK);
     if(chk) return chk;
     chk=query_knight(bx,by,BLACK);
     if(chk) return chk;
     chk=query_pawn(bx,by,BLACK);
     if(chk) return chk;
     chk=query_king(bx,by,BLACK);/*not a real check, but no adjacment kings!*/
     if(chk) return chk;
     return 0;
   }
} /* end of check(); */

checkmate(kleurtje)
{
int xm,ym,i;

  if(kleurtje==WHITE)
   {
     xm=wx;ym=wy;
     if(square(xm,ym+1)==EMPTY)
      {
        wy=ym+1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm+1,ym+1)==EMPTY)
      {
        wx=xm+1;wy=ym+1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm+1,ym)==EMPTY)
      {
        wx=xm+1;wy=ym;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm+1,ym-1)==EMPTY)
      {
        wx=xm+1;wy=ym-1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm,ym-1)==EMPTY)
      {
        wx=xm;wy=ym-1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm-1,ym-1)==EMPTY)
      {
        wx=xm-1;wy=ym-1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm-1,ym)==EMPTY)
      {
        wx=xm-1;wy=ym;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm-1,ym+1)==EMPTY)
      {
        wx=xm-1;wy=ym+1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     wx=xm;wy=ym;
     return 1;
   }
  else
   {
     xm=wx;ym=wy;
     if(square(xm,ym+1)==EMPTY)
      {
        wy=ym+1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm+1,ym+1)==EMPTY)
      {
        wx=xm+1;wy=ym+1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm+1,ym)==EMPTY)
      {
        wx=xm+1;wy=ym;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm+1,ym-1)==EMPTY)
      {
        wx=xm+1;wy=ym-1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm,ym-1)==EMPTY)
      {
        wx=xm;wy=ym-1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm-1,ym-1)==EMPTY)
      {
        wx=xm-1;wy=ym-1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm-1,ym)==EMPTY)
      {
        wx=xm-1;wy=ym;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     if(square(xm-1,ym+1)==EMPTY)
      {
        wx=xm-1;wy=ym+1;
        if(!check(WHITE))
         {
           wx=xm;wy=ym;
           return 0;
         }
      }
     wx=xm;wy=ym;
     return 1;
   }
} /* end of checkmate() */

check_it(xs,ys,xe,ye,color)
{
status error,f1,f2,ck;
int piece;

  error=0;
  if((xs==4) && (ys==0) && (xe==7) && (ye==0) && (color==1) && (!error))
   {
     if(wking)
      {
        write("Your king has already been moved, no castling possible!\n");
        return 1;
      }
     if(wrook)
      {
        write("Your rook has already been moved, no castling possible!\n");
        return 1;
      }
     if((square(5,0)==EMPTY) && (square(6,0)==EMPTY))
      {
        put_piece(xe,ye,KING);
        put_piece(xs,ys,ROOK);
        wking=1;
        wrook=1;
        write("Castling....");
        return 0;
      }
     else
      error=1;
   }
  if((xs==4) && (ys==7) && (xe==7) && (ye==7) && (color==-1) && (!error))
   {
     if(bking)
      {
        write("Your king has already been moved, no castling possible!\n");
        return 1;
      }
     if(brook)
      {
        write("Your rook has already been moved, no castling possible!\n");
        return 1;
      }
     if((square(5,7)==EMPTY) && (square(6,7)==EMPTY))
      {
        put_piece(xe,ye,KING);
        put_piece(xs,ys,ROOK);
        bking=1;
        brook=1;
        write("Castling....");
        return 0;
      }
     else
      error=1;
   }
  if((xs==4) && (ys==0) && (xe==0) && (ye==0) && (color==1) && (!error))
   {
     if(wking)
      {
        write("Your king has already been moved, no castling possible!\n");
        return 1;
      }
     if(wrook)
      {
        write("Your rook has already been moved, no castling possible!\n");
        return 1;
      }
     if((square(3,0)==EMPTY) && (square(2,0)==EMPTY) && (square(1,0)==EMPTY))
      {
        put_piece(xe,ye,KING);
        put_piece(xs,ys,ROOK);
        wking=1;
        wrook=1;
        write("Castling....");
        return 0;
      }
     else
      error=1;
   }
  if((xs==4) && (ys==7) && (xe==0) && (ye==7) && (color==-1) && (!error))
   {
     if(bking)
      {
        write("Your king has already been moved, no castling possible!\n");
        return 1;
      }
     if(brook)
      {
        write("Your rook has already been moved, no castling possible!\n");
        return 1;
      }
     if((square(3,7)==EMPTY) && (square(2,7)==EMPTY) && (square(1,7)==EMPTY))
      {
        put_piece(xe,ye,KING);
        put_piece(xs,ys,ROOK);
        bking=1;
        brook=1;
        write("Castling....");
        return 0;
      }
     else
      error=1;
   }
  if (square(xs,ys)*color<0)
    {
      error=1;
      write("Not your own Piece / No Piece there!\n");
    }
  if(!error)
   if (square(xe,ye)*color>1)
    {
      error=1;
      write("You can't take your own piece!\n");
    }
  if(!error)
   {
      error=1;
      switch(abs(square(xs,ys)))
       {
         case EMPTY  : error=1;
                       break;
         case PAWN   : error=check_pawn(xs,ys,xe,ye,color);
                       break;
         case ROOK   : error=check_rook(xs,ys,xe,ye,color);
                       f2=1;
                       break;
         case KNIGHT : error=check_knight(xs,ys,xe,ye,color);
                       break;
         case BISHOP : error=check_bishop(xs,ys,xe,ye,color);
                       break;
         case QUEEN  : error=check_queen(xs,ys,xe,ye,color);
                       break;
         case KING   : error=check_king(xs,ys,xe,ye,color);
                       f1=1;
                       break;
       }
   }
  if(!error)
   {
     piece=square(xe,ye);
     put_piece(xe,ye,square(xs,ys));
     put_piece(xs,ys,EMPTY);
     if(f1)
      {
        if(color==WHITE)
         {
           wx=xe;
           wy=ye;
         }
        if(color==BLACK)
         {
           bx=xe;
           by=ye;
         }
      }
     ck=check(color);
     if(ck)
      {
        if(f1)
         {
           if(color==WHITE)
            {
              wx=xs;
              wy=ys;
            }
           if(color==BLACK)
            {
              bx=xs;
              by=ys;
            }
         }
        put_piece(xs,ys,square(xe,ye));
        put_piece(xe,ye,piece);
        write("You can't move there!\n");
        return 1;
      }
     if(f1)
      {
        if(color==WHITE)
          wking=1;
        if(color==BLACK)
          wking=1;
      }
     if(f2)
      {
        if(color==WHITE)
          wrook=1;
        if(color==BLACK)
          brook=1;
      }
     ck=check(-color);
     if(ck)
      {
        if(color==WHITE)
          write("Black is check..");
        if(color==BLACK)
          write("White is check..");
      /*if(checkmate(-color))
         {
           write("and mate!\n");
           write(this_player()->query_real_name()+" wins!\n");
           player=0;alt_player=0;
           return 0;
         } */

       write("\n");
      }
   }
  if(error)
    write("You can't move there!\n");
  return error;
} /* end of check_it() */

attack()
{
object victim;
string naam;
  if(::attack())
   {
    victim = this_object()->query_attack();
    naam = victim->query_real_name();
    tell_object(victim,
        "Chessmaster gets angry and summons you to another dimension!\n");
    victim->stop_fight();
    this_object()->stop_fight();
    transfer(victim,DEST);
    say("Chessmaster summons "+naam+" to another dimension.\n");
    log_file("chessmaster.kill",ctime(time())+" "+naam+" "+
             victim->query_level()+" tried to kill me!\n");
    return 1;
   }
 return 0;
} /* end of altered attack function */

