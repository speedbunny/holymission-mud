inherit "/players/kbl/objs/gcity";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_city_name("none","Arissia");
    long_desc = "This is a cloud. Below is the ground, about 3200 feet\n"+
                "down. The gates to the city of Arissia are south of here.\n"+
                "The great walls surrounding this cloud city is made of\n"+
                "a black material mined from deep within Holy Mission.\n";
    items = ({
              "cloud","Soft white and fluffy but also air like. What you\n"+
                      "stand on is a platform, that leads to Arissia",
              "platform","Made of a dark material similar to the walls",
              "walls","Made of some kind of dark material unknown to you",
              "gates","Gold trim with deepest black hinges",
              "hinges","Got a star pattern on them",
              "star pattern","Too far away to get detail",
              "city","The city of Arissia is behind the walls",
              "ground","Long ways down but it seems like a forest",
              "material","Dark black metalic ore",
             });
    smells = ({
               "Fresh air dominates your senses",
               "The smell of food moves past your nose",
               "Odorless but tasty the air quality here is superior",
               "Cool and crisp air... Ahhhhhhhhhhhhhh...",
              });
    hear_items = ({
                   "wind","The wind flows freely here",
                   "wings","You hear the wings pushing against the air",
                   "bird","It sings so wonderfully",
                    "birds","They are flying in a star pattern",
                  });
    room_sound = ({
                   "The wind rushes past the tall walls of the city",
                   "Several birds fly by above",
                   "You hear a bird singing",
                   "You hear a bird flapping its wings somewhere",
                  });
    set_tree_bottom("/players/kbl/expa/for14b");
    dest_dir = ({
                 "/players/kbl/kblroom","down",
                });
    set_level(200);
  }
}

