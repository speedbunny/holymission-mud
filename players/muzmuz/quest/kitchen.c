inherit "room/room";

int _open(string str) {

    if (!str || str != "cupboard") return 0;

    printf("You try to open the cupboard, but it is locked.\n");
    return 1;
}

void reset(int arg)
{
    if(!arg)
    {

      short_desc = "Kitchen";
       long_desc = "You have entered the kitchen. The oven warms up the room. You notice the \n" +
                   "smell of ham and you start to get hungry. The cupboard seems to be locked.\n" +
                   "The livingroom is to the west.\n";

        items =({"cupboard","A small cupboard, it is locked",
                 "oven","The oven is hot ! Better not touch it !",
                               });

       dest_dir = ({"players/muzmuz/quest/livingroom","west",
                            });

          set_light (1);

}
}

void init() {

    ::init();
    add_action("_open","open");

}
