/* the chess masters hut */
inherit "room/room";

object chessmaster;
reset(arg) {
  if ( (!chessmaster) || (!living(chessmaster)) )
   {
    chessmaster = clone_object("players/shaka/monsters/chessmas");
    transfer(chessmaster,this_object());
   }
  if(arg) return;
  set_light(1);
  short_desc="A small hut";
  long_desc="You've entered the small hut of the chessmaster, he's \n"+
            "a very old man and he likes to play chess, in the middle \n"+
            "stands a round table with a chess board on it.\n";
  dest_dir = ({"players/shaka/mountain/path4","out",});
  items= ({"hut","a small hut",
           "table","a small table with a chessboard on it",
           "chessboard","a ordinary chessboard with black and white squares"});
}

