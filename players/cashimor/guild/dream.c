inherit "room/room";

string wat1,wat2,wat3;

reset(arg) {
  if(!arg) {
    short_desc="Dreamworld";
    set_light(1);
    property = "no_teleport";
    dest_dir=({"players/kbl/guild/dream","north",
               "players/kbl/guild/dream","south",
               "players/kbl/guild/dream","east",
               "players/kbl/guild/dream","west"});
    items=({"forest","It looks green and inviting",
            "undergrowth","There's someone lying under it",
            "clearing","The sun is shining above",
            "fields","They look yellow in the sun",
            "farmer","He looks friendly and nice",
            "house","It's made of stones",
            "shed","It stinks here",
            "straw","It looks like it's been used for something",
            "buildings","They belong to a farmer",
            "castle","It's not finished yet",
            "land","It looks very strange",
            "hole","It's rather deep",
            "slaves","They look frightened and hungry",
            "bear","It seems very strong",
            "girl","She isn't very pretty",
            "man","He is a real hero, like you",
            "bow","It looks like the best bow you've ever seen",
            "family","They are welcoming and pleasant",
            "torch","It's lighted",
            "soldiers","They seem to collect slaves",
            "building","It's a half-finished castle",
            "slavedriver","Not a very pleasant guy",
            "whip","There's blood on it",
            "trees","They are green and fresh",
            "horse","It's packed like it's from a traveller",
            "flowers","They look very nice",
            "fire","It looks like it's very hot",
            "night","It's indeed falling fast",
            "sun","It's burning upon your shoulders",
            "stone","It's too big to be lifted"});
    wat1=({"You're in a nice, green forest.\n",
           "You're in a part of a forest with a lot of undergrowth.\n",
           "This is a clearing in a forest.\n",
           "You're walking through the fields of a farmer.\n",
           "You're in the house of a farmer, and you're welcome.\n",
           "This is the shed of a farmer. A lot of straw is here.\n",
           "You're standing between some buildings.\n",
           "There's a castle under construction here.\n",
           "You're on a piece of land where nothing grows.\n",
           "You're at a big hole with a lot of slaves in it.\n"});
    wat2=({"There's a bear looking around in the distance.\n",
           "There's a girl here, frightened by a bear.\n",
           "A man with a bow, aimed at someone, is here.\n",
           "Some clouds can be seen in the distance.\n",
           "A family of a farmer can be seen.\n",
           "A farmer is here, holding a torch.\n",
           "A couple of soldiers can be seen, they look very dangerous.\n",
           "A lot of slaves are working on some kind of building.\n",
           "A slavedriver with a big whip is commanding around.\n",
           "The slaves sigh as they walk towards a hole in the ground.\n"});
    wat3=({"The trees look very high.\n",
           "Some of the trees are slowly dying.\n",
           "A packed horse is standing a few yards to the north.\n",
           "There are blue and red flowers blooming here.\n",
           "A fire is burning here.\n",
           "The night is slowly falling.\n",
           "A man bound on a horse is being led away.\n",
           "The sun is still shining very hot.\n",
           "There are some soldiers riding away in the distance.\n",
           "There's a big stone lying at the edge of a hole.\n"});
  }
}

long(str) {
  long_desc=wat1[random(sizeof(wat1))]+wat2[random(sizeof(wat2))]
          + wat3[random(sizeof(wat3))];
  ::long(str);
}
