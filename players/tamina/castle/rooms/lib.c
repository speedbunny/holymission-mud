/*  This is the Library in Camelot  */

#include "/players/tamina/defs.h"

inherit "room/room";
int searched, taken;

void reset(int arg) 
{
  ::reset(arg);
    taken = 0;
    searched = 0;
  if (arg) return;

    set_light(1);
    short_desc = "Library in Camelot";
    long_desc = 
"You are in what seems to be a library in Camelot.\n"+
"The room itself is quite unlike the other rooms in the castle.\n"+
"Light streams in through the windows, and falls against the walls of \n"+
"books which fill the entire room.  @@check_searched@@\n";

	dest_dir = ({
          CROOMS + "ewing5","west",
        });

	items = ({
  "books",
"There are hundreds of books lining the bookshelves on the walls",
  "shelves",
"@@check_searched@@",
  "walls",
"There are four of them, and they all have bookshelves on them",
  "windows",
"You can see a bleak, windy day outside the closed window",
     });

}

void init()
{
  ::init();
  AA("no_open", "open");
  AA("_search", "search");
  AA("_read",   "read");
}

string check_searched()
{
  if (searched)
  {
    return ("It looks as though someone has been searching around here");
  }
  else
    return ("");
}

int no_open(string str)
{
  if (str == "window" || str == "windows")
  {
    write("They seem to be solidly closed, and you are unable\n"+
	  "to open the windows.\n");
    say(TPN+" tries, and fails to open the windows.\n");
    return 1;
  }
}

int _search(string str)
{
  if (str == "books" || str == "shelves" || str == "bookshelves")
  {
    write("You find lots more books to read.\n");
    say(TPN+" searches through the books.\n");
    searched = 1;
    return 1;
  }
  else
  {
    NFAIL("Search what?\n");
    return 0;
  }
}

int _read(string str)
{
  if (str == "books" || str == "book")
  {
    switch(random(15))
    {
      case 14:
        if (taken)
        {
	  write("You find nothing to look at.\n");
	  return 1;
	}
	write("You find a book.\n"+
	      "You see that it is concerned with the magic of the Elements.\n");
       	if (transfer(clone_object(COBJ + "el_book"), TP))
       	{
	  write("You think it could be useful, but cannot carry it just now.\n"+
	        "So you put it back on the shelf for future use.\n");
          return 1;
        }
        else
	  write("You decide to take it for further study.\n");
	say(TPN+" looks in detail at the books.\n");
	taken = 1;
	return 1;
      break;

      case 1 .. 2:
	write("You find a book.\n"+
	     "It is a book about the medieval cooking recipes of the day.\n"+
	     "You see some of things these people eat, and quickly put\n"+
	     "it back on the shelf.\n");
	say(TPN+" looks in detail at the books.\n");
	return 1;
      break;

      case 3 .. 4:
	write("You find a book.\n"+
	     "You see that this book is about the construction of good armies\n"+
	     "This quickly bores you, and you put it back on the shelf.\n");
	say(TPN+" looks in detail at the books.\n");
	return 1;
      break;

      case 5 .. 6:
	write("You find a book.\n"+
	     "It is a book about metalwork in the creation of swords, and\n"+
	     "hammers, and arrowheads.  How dull...\n");
	say(TPN+" looks in detail at the books.\n");
	return 1;
      break;

      case 7 .. 8:
	write("You find a book.\n"+
	     "This book is about millinery, and sewing.  You find it\n"+
	     "quite tedious, and put it back on the shelf.\n");
	say(TPN+" looks in detail at the books.\n");
	return 1;
      break;

      default:
	write("You find nothing to look at.\n");
	say(TPN+" looks in detail at the books.\n");
	return 1;
      break;
    }
  }
  else
  {
    NFAIL("Search what?\n");
    return 0;
  }
}

