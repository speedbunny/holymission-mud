
/* Tegerl, 28.3.1995 */
/* rooms/castle/tourn */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"
#define TPN this_player()->query_name()

int counter;

query_long()
{
 if (counter <= 0)
    return (    "This is the tournament place. " +
           "You just came in time. The tournament is almost over. " +
           "There is only one knight left. " +
           "This is your chance to win the tournament and the hand of the princess, "+
           "and don't forget, .... the country. "+
	   "So take the risk and challenge the last knight. "+
           "To the north you can see the grandstand of the royals.\n" );

 return (    "This is the tournament place. " +
         "The tournament is already over. You are to late. " +
         "There is already a winner. Sorry, but that's life. " +
         "To the north you can see the grandstand of the royals.\n" );
}
 
void reset(int arg) 
{
 ::reset(arg);
 if (arg) return;

set_light(1);
short_desc="The tournament place";
long_desc="@@query_long@@";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/crowd", "south",
    });

items=({
    "place","You can see that the tournament already took place for a while as you can see blood and body parts everywhere",
    "grandstand","All people who are important in this town are there",
    "blood","It is the blood of many knights",
    "boody parts","As you look at them you have to burp",
    "boody part","As you look at it you have to burp",
    "parts","As you look at them you have to burp",
    "part","As you look at it you have to burp",
 });

 smell = "You smell death and pain.";
 ::reset(arg);
}

void init() {
 ::init();
 add_action("chall","challenge");
}

int chall(string str) {
if (!(str=="knight"))
   {
   write("challenge whom ?\n");
   return 1;
   }
if (str=="knight");
   {
    if (counter <=0)
    {
    write("You step into the middle of the arena.\n");
    write("Your voice echos from everywhere as you shout: \n");
    write("'You defeated all of them, but not me, show that you deserve the victory !!' \n");
    write("As the words are spoken the knight mounts his horse and comes to extinct you.\n");
    say(TPN+" steps into the middle of the arena.\n");
    say(TPN+"'s voice echos from everywhere as "+ TPN+" shouts: \n");
    say("'You defeated all of them, but not me, show that you deserve the victory !!'\n");
    say("As the words are spoken the knight mounts his horse and comes to extinct "+TPN+".\n");
    transfer(clone_object("/players/tegerl/jabberwocky/monsters/tkni"),(this_object()));
    counter++;
    }
   else
    {
    write("Eh, the tournament is over.\n");
    }
  return 1;
   }
} 