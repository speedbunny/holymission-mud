
/* Coded by Tegerl, 8.3.1995 */
/* rooms/out/door */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

query_long()
{
 if (!present("guard",this_object()))
    return (    "This is the entrance to the city. " +
           "There is a huge door which is currently open. Normally it is " +
           "heavily guarded. As you look around in front of " +
           "the door you realize that "+
           "the entrance isn't protected. Maybe the guards are drunken "+
	   "and they are sleeping in a pub.\n" );

 return (    "This is the entrance to the city. " +
         "There is a huge door which is currently open. But it is " +
         "heavily guarded. As you look at the big crowd in front of " +
         "the door you realize that the guard will not let you in.\n" );
}
 
void reset(int arg) 
{
 ::reset(arg);  /*this is neccessery for query_long() */
 if (arg) return;
 clone_list=({1,2,"guard",PATH+"monsters/guard1",0,
              2,2,"farmer",PATH+"monsters/farmer",0,
              3,2,"peasant woman",PATH+"monsters/pewoman",0,
              4,4,"peasant child",PATH+"monsters/pechild",0,
              5,2,"poor man",PATH+"monsters/pman",0,
              6,2,"poor woman",PATH+"monsters/pwoman",0,
              7,4,"poor child",PATH+"monsters/pchild",0});  
set_light(1);
short_desc="At the city entrance";
long_desc="@@query_long@@";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/place3", "west",
    "players/tegerl/jabberwocky/rooms/town/street1", "north",
    });

items=({
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","Yes, footprints, and they are human",
    "trails","As you look at tho trails you think that maybe a carriage used this path",
    "city-wall","The wall is very old and needs to be repaired. It seems to be very desolate",
    "wall","The wall is very old and needs to be repaired. It seems to be very desolate",
    "entrance","The entrance is heavily guarded. There is one tower left and right of the door",
    "door","The big door is made of wood, but it has metal fittings",
    "crowd","There are many people, and they all want to pass the guard",
 });

 smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
 ::reset(arg);  /* now we get monsters */
}
