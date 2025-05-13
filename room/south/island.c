
/* island.c recoded that rooms to room.c Whisky */

inherit "/room/room";

#define ITEMS ({\
        "bottom","The bottom is covered with brown earth",\
        "ground","The bottom is covered with brown earth",\
        "sky","The sky is a bit cloudy",\
        "clouds","The clouds are moving with the wind",\
        "shore","You see the shore of a beautiful lake",\
        "water","The water is clear and slighty coloured in green",\
        "lake","There are some fish swimming in the water",\
        "fish","You see some carps, trouts, pikes and other fish",\
        "magetower","You see a big black tower on the isle"+\
        "tower","You see a big black tower on the isle"+\
        "forest","You see a beautiful mixed forest in the distance"+\
        "trees","You see oaks, birches... all kind of trees"+\
        "path","You see a small dirty path"\
        "hills","You see some small grassy hills"\
        })

#define DESC ""\

/* prototyping */
string add_long();
string *add_dirs();
string *add_items();
void get_objects();

void reset(int flag)
{
   get_objects();
   if (flag==0) 
   {
     set_light(1);
     short_desc = "On the green Isle of Magi";
     long_desc = DESC + add_long();
     dest_dir =  add_dirs(); 
     items = ITEMS + add_items();
   }
}

void get_objects()
{
}

string add_long()
{
    return "";
}

string *add_dirs()
{
    return ({});
}

string *add_items()
{
    return ({});
}

