
/* shore.c */

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
        "forest","You see a beautiful mixed forest"+\
        "trees","You see oaks, birches... all kind of trees"+\
        "isle","There is a beautiful grassy isle in the middle"+\
               "of the lake.",\
        "trail","The small trail is winding itself around the lake"\
        "trail","The small trails are winding themself around the lake"\
        })

#define DESC\
        "You are standing on the pictureque shore of the blue Crescent\n"+\
        "Lake. Out in the centre of the clear, blue lake stands is the\n"+\
        "green Isle of Magi with the high, black magetower of Arcanarton.\n"

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
     short_desc = "On the shore of a beautiful, blue lake\n";
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

     
void init() 
{
     ::init();
     add_action("fcn_fish","fish");
}

int fcn_fish()
{
   object fi;

    if (!present("rod",this_player()))
    {
        notify_fail("You need a fishing rod to catch a fish.\n");
        return 0;
    }

    switch (random(100)) 
    {
      case 0:
       write("Oops, you caught an eel.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/eel");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      case 1:
       write("Oops, you caught a river snake.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/snake");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      case 2:
       write("Oops, you caught a river pike.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/pike");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      case 3:
       write("Oops, you caught a trout.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/trout");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      case 4:
       write("Oops, you caught a cancer.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/cancer");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      default:
       write("Hmm, bad luck the fish won't bite today.\n");
       break;
     }
   return 1;
}
       
         
           

       
        

/* shore.c */

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
        "forest","You see a beautiful mixed forest"+\
        "trees","You see oaks, birches... all kind of trees"+\
        "isle","There is a beautiful grassy isle in the middle"+\
               "of the lake.",\
        "trail","The small trail is winding itself around the lake"\
        "trail","The small trails are winding themself around the lake"\
        })

#define DESC\
        "You are standing on the pictureque shore of the blue Crescent\n"+\
        "Lake. Out in the centre of the clear, blue lake stands is the\n"+\
        "green Isle of Magi with the high, black magetower of Arcanarton.\n"

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
     short_desc = "On the shore of a beautiful, blue lake\n";
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

     
void init() 
{
     ::init();
     add_action("fcn_fish","fish");
}

int fcn_fish()
{
   object fi;

    if (!present("rod",this_player()))
    {
        notify_fail("You need a fishing rod to catch a fish.\n");
        return 0;
    }

    switch (random(100)) 
    {
      case 0:
       write("Oops, you caught an eel.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/eel");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      case 1:
       write("Oops, you caught a river snake.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/snake");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      case 2:
       write("Oops, you caught a river pike.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/pike");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      case 3:
       write("Oops, you caught a trout.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/trout");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      case 4:
       write("Oops, you caught a cancer.\n");
       say(this_player()->query_name()+" caught a something !\n",this_player());
       fi = clone_object("/players/whisky/lake/monster/cancer");
       move_object(fi,this_object());
       fi->attack_object(this_player());
       break;
      default:
       write("Hmm, bad luck the fish won't bite today.\n");
       break;
     }
   return 1;
}
       
         
           

       
        
