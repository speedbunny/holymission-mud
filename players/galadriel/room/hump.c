inherit "room/room";

status searched;

linewrap(str,maxlen) {
  string *words,curstring;
  int i,len,curlen;
  
  words=explode(str," ");
  for (i=0; i<sizeof(words); i++) {
    if (!i) {
      curstring=words[i];
      curlen=strlen(words[i]);
    }
    else {
      if (curlen+1+strlen(words[i])>=maxlen) {
        curstring+="\n"+words[i];
        curlen=strlen(words[i]);
      }
      else {
        curstring+=" "+words[i];
        curlen+=strlen(words[i])+1;
      }
    }
  }
  return curstring;
}

init () {
  ::init();
  add_action ("search","search");
  add_action ("down",  "down",1);
}

reset (arg) {
  string beechdesc, heapdesc, bankdesc;
  searched=0;
  if (!arg) {
    set_light (1);
    short_desc="Humpbacked bridge";
    long_desc=
      "You are on a humpbacked bridge, crossing a peaceful river flowing from the\n" + 
      "north, greened with bushes and sappy beech trees. On the bridge a small\n" +
      "heap of beech twigs and rotting leaves spread a sweetish mouldy smell, and\n" +
      "a small path north through the bushes prove that people and animals use to\n" +
      "go down to reach the clear water of the river. A small track starts at\n" +
      "the southeast side of the bridge and leads along the river bank.\n";
    beechdesc =
      "They look healthy, getting their water from the river";
    heapdesc =
      "Many a twigs, sticks and half-rotten leaves from the last storm cover\n"+
      "the trash that people have dropped or lost there. It might be an idea to\n" +
      "search the leaves if there is something useful left in that heap";
    bankdesc =
      "The river bank looks steep here but could be less steep when you are\n" +
      "farther from the bridge";
    items = ({
      "bridge",
         "An old, wellbuilt bridge made of heavy stones, framed by a dirty heap\n" +
         "of leaves on each side",
      "bushes",
         "Sappy green bushes, which drink from the water of the river",
      "beeches",      beechdesc,
      "beechtrees",   beechdesc,
      "beech trees",  beechdesc,
      "trees",        beechdesc,
      "leaves",      heapdesc,
      "heap",        heapdesc,
      "beech twigs", heapdesc,
      "twigs",       heapdesc,
      "bank",        bankdesc,
      "riverbank",   bankdesc,
      "river bank",  bankdesc,
      "track","A track leads southeast along the riverbank. It follows the\n" +
              "winding curves of the river as far as you can see",
      "path",
         "A narrow path, leading straight down to the water. It looks slippery\n" +
         "with all those leaves on the ground and it would take all your skills\n" +
         "not to slide into the water",
      "water",
         "It is clear and looks very deep",
      "river",
         "The river is very deep, too deep for a man to stand on the bottom",
    }); 
       
    smell= "The air is filled with the sweetish smell of rotten leaves.";
    dest_dir = ({
      "room/wild1","west",
      "players/galadriel/room/path1","southeast",
      "room/vill_green","east",
      "players/wolfi/room/in_river","down",
    });
  }
}

down () {
  write ("You slip and slide down the path into the river.\n");
  this_player()->move_player("down#players/wolfi/room/in_river");
  return 1;
}

  
search (str) {
  string invis_msg;
  object temp;
  invis_msg="You hear a rustling noise as the heap of leaves moves aside!\n";

  if (!str || str=="bridge" || str=="room") {
    write ("You search on the street and find a heap of twigs and leaves.\n");
    return 1;
  }
  if (str=="heap" || str=="twigs" || str=="leaves" || str=="beech twigs" ) {
    if (this_player()->query_ghost()) {
      write ("Your incorporeal hands pass right through the heap.\n");
      return 1;
    }
    if (searched) {
      write ("You stir up the leaves, but you find nothing useful left.\n");
      if (this_player()->query_invis()) {
        say (invis_msg);
        return 1;
      }
      say (linewrap (this_player()->short() +
       " stirs up the leaves on the road.\n",78));
      return 1;
    }
    searched=1;

/* money-calculating should be done by the player-obj, independent to changes */
    write 
      ("You find 10 gold coins, a tiny matchbox and a dry, combustable stick.\n");
    if (this_player()->query_invis())
      say (invis_msg +
        "Some gold appears - and disappears again, how mystically!\n" +
        "A tiny matchbox and a dry, combustible stick raise from the ground -\n" +
        "and vanish also.\n");
    else 
      say (linewrap(this_player()->short() + " stirs up the leaves and finds " +
        "some money, a tiny matchbox and a dry stick.\n",78));
    this_player()->add_money(10);

/* the player will pick up the matchbox */
    temp=clone_object("players/galadriel/fire/matchbox");
    
    if (transfer(temp,this_player())) {
      write ("You have no hands left to pick up the matchbox.\n");
      if (this_player()->query_invis()) {
        say ("A matchbox falls to the ground.\n");
      }
      else
        say (this_player()->short() + " drops a matchbox.\n");
      move_object (temp,this_object());
    }
    
/* and a dry stick */
    temp=clone_object("obj/torch");
    temp->set_name("stick");
    temp->set_short("a stick");
    temp->set_long("This stick is slightly black on one end.\n");
    temp->set_fuel(500);
    temp->set_weight(1);
    
    if (transfer(temp,this_player())) {
      write ("You have no hands left to pick up the stick.\n");
      if (this_player()->query_invis()) {
        say ("A stick falls to the ground.\n");
      }
      else
        say (this_player()->short() + " drops a stick.\n");
      move_object (temp,this_object());
    } 
    return 1;
  }
  write ("You find nothing special.\n");
  return 1;
}
