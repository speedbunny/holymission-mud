inherit "room/room";
int shield;
void check();

#define TP this_player()
#define CA capitalize
#define RN this_player()->query_real_name()
#define TO this_object()
#define TPQN TP->query_name()

reset(arg) {
  ::reset(arg);
  
  tell_room("/players/sylvyn/workroom", "There has been a reset Master.\n");
  if(arg) return;

  set_light(1);
  short_desc = "Lord Sylvyn's Workroom";
  long_desc =
"You have entered the workroom of Lord Sylvyn. You can see a large oak desk\n"+
"on the far wall, covered with papers and magical items used by Lord Sylvyn\n"+
"as he creates new worlds for you to explore. There is also a picture of his\n"+
"lovely wife Danielle. You notice the Legendary Dragon Orb that sits on the\n"+
"corner of the desk. The fire place next to the desk fills the room with\n"+
"warmth and light. Tapestries cover most of the smooth marble walls,\n"+
"depicting the greatest battles and warriors in the long history of Holy\n"+
"Mission. A large window gives you a panoramic and majestic view of the\n"+
"land. The rest of the walls are covered with bookcases, filled with all of\n"+
"Sylvyn's spell books.\n" +
"\n";

     dest_dir=({

          "players/matt/newworld/city/rooms/votebooth", "vote",
          "players/saffrin/guild/rooms/oldstart", "mages",
          "players/mangla/guild/entrance", "jedis",
          "players/whisky/guild/room", "monks",
          "players/nylakoorub/guild/room", "vaga",
          "players/airborne/temple/perfume", "perf",
          "room/post", "post",
          "room/church", "church",
          "room/adv_guild", "guild",
          "players/sylvyn/area/rooms/amazon/south/a001", "area",
          "players/danielle/workroom", "honey",
        });

  items=({
"window",
"A large panoramic view of the lands of Holy Mission",
"bookcases",
"The shelves are lined with black books with silver runes, marking\n" +
"them as belonging to Lord Sylvyn",
"desk",
"The desk is littered with tons of papers and other various magical items",
"tapestries",
"The greatest moments in Holy Mission History come alive before your very\n"+
"eyes",
"walls",
"The walls are made of the smoothest marble you have ever seen. There is\n"+
"not one single joint in them. You figure that Sylvyn must have made this\n"+
"place with his magic",
"floor",
"The floor is solid oak. There is a large bearskin rug covering the area\n"+
"between Lord Sylvyn's desk and the fireplace",
"rug",
"This is the skin from one of the larges and meanest looking bears you have\n"+
"ever seen before in your entire life. You wonder how Lord Sylvyn could\n"+
"have ever killed it",
"fireplace",
"It is a very large fireplace and the fire within is flickering wildly",
"dragon orb",
"The legendary Dragon Orb! The only one left on Holy Mission. It is said\n"+
"that with it's power one could control even the mightest dragon! Oh you\n"+
"wish you could get your hands on that Orb",
"picture",
"A lovely picture of the most beautiful woman you have ever seen. Her\n"+
"beauty is so great that you know that Sylvyn is the luckiest man alive.",
 });
   property = ({
        "no_sneak","no_steal","no_teleport","no_snoop","no_assassinate",
     });

   smell = "This place smells like a old libary.";
     }

init(){
::init();

  check();
   if(this_player()->query_invis() && RN !="sylvyn"){
write("A Ghoul suddenly appears from another realm and points at you\n" +
        "and warns his master, Lord Sylvyn, of your presence.\n");
say("The Ghoul says: "+CA(TP->query_name())+ " is trying to sneak up on you"+
   "my Master.\n");
   return 1;
 }
add_action("set_shield", "shield");
add_action("expel", "expel");
 }
int set_shield(string str){
  if(RN!="sylvyn"){
write("A Ghoul informs you: Only Lord Sylvyn may do that.\n");
  return 1;
  }
else if(!str){
write("Your servant informs you: Your field is currently "+ shield + " Master.\n");
  return 1;
  }
else if(str=="on"){
write("Your servant appears and tells you: As you wish Master, no one shall\n"+
     "enter.\n");
say("Lord Sylvyn makes a simple hand gesture and a shimmering field appears.\n");
  shield = 1;
  return 1;
  }

else if(str == "off"){
write("Your servant bows and says: As you wish Master, I will allow people\n"+
     "to enter your domain.\n");
say("Lord Sylvyn makes a gesture with his hands and the shimmering field\n"+
   "disappears.\n");
  shield=0;
  return 1;
  }

 else {
  write("Your servant looks at you and says: I can not do that my Master.\n"+
       "Please forgive me.\n");
  return 1;
}
}

  check() {
  if(shield && (RN!="sylvyn") && TP->query_level() < 300) {
write("Lord Sylvyn's servant prevents you from entering his workroom.\n");
write("Lord Sylvyn's servant transfers you somewhere.\n");
  move_object(TP, "far far away#/room/prison");
  if (find_living("sylvyn"))
tell_object(find_living("sylvyn"), "Your servant informs you: "+RN+" tried"+
           "to enter your room Master.\n");
  }
  return 1;
 }
expel(arg) {
   object player;
if(RN !="sylvyn") return;
   if(!arg) {
   write("Whom do you wish to expel Master?\n");
   return 1;
   }

player = present (arg, TO);
    if(!player) {
write("That person is not here Master.\n");
    return 1;
  }
write("You wave your hand at " + TPQN + " and he vanishes from your room.\n");
    player->move_player ("to the prison#/room/prison");
tell_room(TO, TPQN + "was magically transported to the prison for annoying\n"+
         "Lord Sylvyn.\n");
     return 1;
}
