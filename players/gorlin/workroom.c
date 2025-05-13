inherit "room/room";

void reset( int arg )
{
   ::reset( arg );

   if ( !arg ) {

   short_desc= "Gorlin's Workroom",
   long_desc= "The smell of flowers surrounds you as you enter Gorlin's\n"+
             "'workroom'. You are in a beautiful garden, surrounded by the\n"+
             "eternal walls of the void. The earth feels soft and warm under\n"+
             "your feet, and grass and flowers are covering every inch. You\n"+
             "feel the force of life engulfing this tiny universe, and you\n"+
             "have to ask yourself if this place can be real. As you draw in\n"+
             "the sight of this marvelous place you see some other items you\n"+
             "missed before. On a small, square white stone you see a tiny\n"+
             "white elephant. In a corner of the garden there are several\n"+
             "comfortable chairs and a round table, inviting you to sit down\n"+
             "and forget about the problems of the world for some time. Set\n"+
             "into the walls of the void are several magic portals leading\n"+
             "to other worlds. Some way up there is a tiny starlet which\n"+
             "orbits this improbable place and supplies it with rays of soft,\n"+
             "warm light.\n";
   set_light(1);
   items=({
   "flowers","The flowers in the garden are growing without any interference\n"+
             "by gardeners, nevertheless they all look very beautiful and have\n"+
             "a very enticing relaxing smell.",
   "walls","The walls are made of nothing. There are no stars to be seen in\n"+
             "the distance, there are no asteroids, no comets. The Void is void\n"+
             "of matter, void of energy and void of thought. Nothing could\n"+
             "probably exist out there... yet the garden does.",
   "void","The void is empty, and black. Nothing exists, or can be able to\n"+
             "exist in the void. The garden and its tiny starlet are the only\n"+
             "things that float in this nothingness.",
   "earth","The earth is dark brown and fertile. Besides from that, there is\n"+
             "nothing remarkable about it.",
   "floor","The 'floor' is, in this case, made of earth and covered with grass\n"+
             "and flowers.",
   "grass","It is green and soft... a rabbit's delight.",
   "rabbit","But there is no rabbit !! (looking stupid, are you ?)",
   "stone","It is a white stone, in the form of a square.",
   "elephant","This tiny elephant is standing on the white stone. First you thought\n"+
             "it to be made from porcelain, but then you suddenly see it move. It\n"+
             "is alive! It looks at you with its luminous, trusting eyes.",
   "chairs","The chairs are, as is the table, made from living wood. This makes\n"+
             "moving them an inconvenience, and nearly impossible, but they are\n"+
             "good to sit in. The living wood lets you relax, and you will feel\n"+
             "warmth and strength enter your body.",
   "table","The table is made from living wood, as are the chairs that surround it.",
   "portals","The portals shimmer in all colours of the rainbow, with a light\n"+
             "golden hue. They lead to strange places in other worlds.",
   "starlet","This small sun orbits the garden and sheds its light onto it,\n"+
             "making life possible for all the plants and insects that live\n"+
             "here.",
              });
   dest_dir=({
       "room/church","church",
       "players/matt/newworld/city/rooms/votebooth","vote",
       "/players/gorlin/workroom","nowhere",
              });
}
}

init()
{
  ::init();
}
