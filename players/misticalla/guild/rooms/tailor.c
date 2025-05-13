
inherit "/room/room";

mapping what;

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "Monk's Tailor Shop";
        long_desc =
       "You enter a small room that has many different "+
        "colored fabrics hanging from the walls. The girl "+
        "behind the desk, named Tanja, is a young nun. "+
        "She looks up from her sewing and sees you standing "+
        "in the doorway. You notice a small sign behind "+
        "her counter. The courtyard is back to the east.\n";

        what = ([
                  "headband":20,
                  "robe":200
                ]);
 
       items = ({
        "sign","There is something written on it",
        "wall","The walls are made of red bricks",
        "walls","The walls are made of red bricks",
        "desk","It's an oak wooden desk",
        "tanja","She is sitting behind the desk working busily"
        });

        dest_dir =({
          "/players/misticalla/guild/rooms/courtyard1","east",
         });
      }
  }


void init()
{
   add_action("do_read","read");
   add_action("do_buy","buy");
   ::init();
}


int do_read(string arg)
{
  string *arr;
  int i, sz;

    if (arg!="sign") return 0; 

    arr = m_indices(what);

    write("Buyable items currently:\n\n");

    for (sz = sizeof(arr),i = 0; i < sz; i ++)
         printf("%-10s for %-8s coins\n",arr[i],to_string(what[arr[i]]));
    write("\nHeadbands and robes are autoload and protect a bit.\n"+ 
         "The color of the headband shows you the guild status\n"+
          "of the monk. The color of the robe shows the sex of the\n"+
          "guild member. These clothes are only wearable\n"+
          "by monks!!!\n");
    return 1;
}

int do_buy(string arg)
{
   if (member(what,arg)!=1)
   {
       notify_fail("Tanja tells you:\n"+
                   "Sorry, but I don't sell "+arg+".\n");
       return 0;
   }
   else if (this_player()->query_money() < what[arg])
   {
       notify_fail("Tanja tells you:\n"+
                   "Sorry, but you can't effort the "+arg+".\n");
       return 0;
   } 
   else if (present(arg,this_player()))
   {
       notify_fail("Tanja tells you:\n"+
                   "Sorry, but I sell only one "+arg+" to one member.\n");
       return 0;
    }

  /* here to add new */
  switch(arg)
  {
    case "headband":
          move_object(clone_object("/players/whisky/guild/obj/headband"),
          this_player());
    break;
    case "robe":
          move_object(clone_object("/players/whisky/guild/obj/robe"),
          this_player());
    break;
  }
  write("Tanja gives you the "+arg+".\n");
  this_player()->add_money(-what[arg]);
  return 1;
}
          

    
    

