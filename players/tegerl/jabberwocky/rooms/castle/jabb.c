

/* Coded by Tegerl, 11.12.1995 */
/* rooms/castle/knight */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{
if (!arg);
{
set_light(1);
short_desc="A desperate area";

long_desc=
    "This is a desperate area north of the town. " +
    "All around you, there is only desert. " +
    "You wonder how anyone could persuade you to make this job, the risk is much too big, " +
    "nobody who had ever seen the Jabberwocky came back alive.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/knight", "south",
  });

items=({
    "ground","Your footprints seem to be the only ones around here",
});

property = ({ "no_teleport" });

smell = "Hot, dry air, almost too hot to breath.";
  
  }
}
int init()
{
  ::init();
  if (interactive(this_player()))
  {
  if (this_player()->query_level() >= 30) {return 1;}

  call_out ("intro", 5);
  call_out ("first", 15);
  call_out ("check", 20);

 }
} 

intro()
{
   if(present(this_player()))
      write ("In the distance a horrible creature appears, and it is heading into your direction!!\n");
     return;
}

first()
{
   if(present(this_player()))
      write ("The creature has almost reached you now, it has to be the JABBERWOCKY!!\n RUN AWAY!!!!!\n");
     return; 
}

check()
{
   if(present(this_player()))
    if(this_player()->query_intoxination() <= 15)
      {write ("As you see the monster comming nearer and nearer you panic and try to run away.\n");
       move_object(this_player(), "/players/tegerl/jabberwocky/rooms/castle/knight");
       return 1;}
    write ("As you see the monster comming nearer and nearer you panic and try to run away.\n" +
      "But you are much too drunk! You fall on your butt!!\n" +
      "You try to find cover under your shield, your lance stares straight into the sky.\n" +
      "Jabberwocky now has reached you and leans down to kill you,\n" +
      "THERE, this silly monster ran into your lance!\n\n\n" +
      "Congrats, you killed JABBERWOCKY!\n"); 
}
      
