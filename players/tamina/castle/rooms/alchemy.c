/*  This is the Alchemists' Room  */

#include "/players/tamina/defs.h"

inherit "room/room";
object ob1, ob2;
int p1_found, p2_found, p3_found;

void reset(int arg) 
{
  ob1 = present("roger");
  if (!ob1 || !living(ob1))
  MO (CLO (CMONS + "roger"), TO);

  ob2 = present("bernard");
  if (!ob2 || !living(ob2))
  MO (CLO (CMONS + "bernard"), TO);

  p1_found = 0;  p2_found = 0;  p3_found = 0;

  if (arg) return 0;

      	set_light(1);
	short_desc = "Alchemy Laboratory";
	long_desc = 
"You are in what must be the messiest room you have ever seen!\n"+
"It is so littered and untidy, that you can only imagine what it\n"+
"actually looks like cleared up!  The main things around the room\n"+
"are various tables, and stools, and shelves on the walls.\n";

	dest_dir = ({
          CROOMS + "n_junction","south",
        });

	items = ({
  "walls",
"These are completely covered in what looks to you like green slime "+
"or some sort of substance that sticks solidly to the wall",
  "shelves",
"These contain all manner of beakers, vials, potion bottles, flasks, "+
"books, pamphlets, scrolls, quills, and many other things that you "+
"cannot quite identify..",
  "tables",
"Wooden structures that stand solidly against the walls of the room.\n"+
"You see all manner of papers, and parchment on the tables",
  "stools",
"There are two 3-legged stools at either of the tables",
  "books",
"These are faded, dusty volumes that you don't seem to be able to pull"+
" down from the shelves..",
  "scrolls",
"You might want to have a closer look at these.  There could be something"+
" interesting there..",
  "pamphlets",
"These are intermingled with the scrolls on the shelves",
  "beakers",
"These are glass bottles that are full of strangely coloured liquids.\n"+
"You are not so sure if it would be wise to take these from the shelves..",
  "potions",
"These are glass bottles that are full of strangely coloured liquids.\n"+
"You are not so sure if it would be wise to take these from the shelves..",
  "slime",
"This looks decidedly strange, and you are very loathe to touch that",
  "quills",
"These are feathered writing implements",
     });

}

void init() 
{
  ::init();
  AA("do_search",  "search");
}

int do_search(string arg)
{
  object p1, p2, p3;

  if (present("roger") || present("bernard")) 
  {
    write("You cannot search through the Lab while the Alchemists are here !!\n");
    return 1;
  }
  switch (arg)
  {
    case "shelves":
    case "shelf":
    write(
"You look through the shelves, and find a huge array of bottles,\n"+
"beakers, potions, vials, and flasks.  On other shelves, you look \n"+
"through many tomes and volumes of books, piles of parchment, scrolls,\n"+
"and papers.  But there is nothing of interest on the shelves.\n");
    say(TPN+" looks through the shelves.\n");
    break;

    case "beakers":
    case "bottles":
      if (p1_found)
      {
        write("You find nothing of interest here.\n");
        return 1;
      }
      write(
"On looking through the multitude of strange bottles, you do manage to\n"+
"find an interesting little bottle that catches your eye.\n"); 
      say(TPN+" searches through the beakers and bottles, and finds something !\n");

      p1 = CLO ("/players/kryll/guild/poison/poison");

      p1->set_name("bottle");
      p1->set_alias("poison");
      p1->set_alt_name("vial");
      p1->set_short("Bottle of 'Alchemist Breath'");
      p1->set_long("This is a renowned poison created by Roger and Bernard.\n");
      p1->set_alchemic_value(590);
      p1->set_strength(20);

      TR(p1, TP);
      p1_found = 1;
      break;

    case "tables":
      write("You find nothing on the tables.\n");
      say(TPN+" looks in detail at the tables.\n");
      break;

    case "quills":
      write("You find nothing amid the quills.\n");
      say(TPN+" looks in detail at the quills.\n");
      break;

    case "stools":
      write("You find nothing amongst the stools.\n");
      say(TPN+" looks in detail at the stools.\n");
      break;

    case "flasks":
    case "vials":
      if (p2_found)
      {
        write("You don't find anything of interest.\n");
        return 1;
      }
      write(
"In amid the clutter of vials, you think you find something that looks\n"+
"rather valuable.  You decide to take it with you...\n");
      say(TPN+" finds something amongst the vials !\n");
      p2 = CLO (COBJ + "vial");
      TR(p2, TP);
      p2_found = 1;
      break;

    case "papers":
    case "parchment":
      write(
"You look through the pieces of parchment and paper, but\n"+
"find nothing that looks worth anything.\n");
      say(TPN+" looks in detail at the papers and parchment.\n");
      break;
  
    case "scrolls":
    case "books":
      if (p3_found)
      {
        write("You find nothing of interest here.\n");
        return 1;
      }
      write(
"You pull down a few of the books and scrolls, and a lovely looking\n"+
"piece of gold-leaf scroll falls to the floor.  You snatch it up before\n"+
"anyone else can take it.\n");
      say(
"A little gold-leaf scroll falls to the floor, which "+TPN+" promptly\n"+
"snatches up quickly !!\n");
      p3 = CLO (COBJ + "enc");
      TR(p3, TP);
      p3_found = 1;
      break;

    default:
      write("You cannot find that here to search through.\n");
      say(TPN+" looks in vain for something to search through.\n");
      break;
  }
  return 1;
}
